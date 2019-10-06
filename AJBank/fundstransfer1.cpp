#include "fundstransfer1.h"
#include "ui_fundstransfer1.h"
#include<menublank.h>
#include<suggestion.h>
#include<mainmenu.h>
#include<QBitmap>
#include<QRegExp>
#include<QComboBox>
#include<QSqlQuery>
#include<QtSql>
FundsTransfer1::FundsTransfer1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FundsTransfer1)
{
    ui->setupUi(this);
}

void FundsTransfer1::showEvent( QShowEvent* event )
{
    QMainWindow::showEvent( event );
    setWindowIcon(QIcon(":/button/buttons/Logo.png"));
    QPixmap logout(":/button/buttons/Logout.png");
    ui->LogoutButton->setMask(logout.mask());
    QPixmap suggest(":/button/buttons/Suggest.png");
    ui->SuggestButton->setMask(suggest.mask());

    ui->FundsTransferAccount->setStyleSheet("background-color:white");

    int CurrentAccount = ui->AccountNo->text().toInt();
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/ajbank.db");
    if(!db.open())
    {
        qDebug() << "Can't Connect to DB !";
    }
    else
    {
        qDebug() << "DB Connected - FundsTransfer1";
        QSqlQuery query;
        query.prepare("select AccountNo,Name from CUSTOMER where AccountNo != :Account");
        query.bindValue(":Account",CurrentAccount);
        query.exec();
        int i = 0;
        while (query.next())
        {
            ui->FundsTransferAccount->setItemData( i, QColor( Qt::white ), Qt::BackgroundRole );
            i++;
            ui->FundsTransferAccount->addItem(query.value(0).toString()+" - "+query.value(1).toString());

        }
        ui->FundsTransferAccount->setItemData( i, QColor( Qt::white ), Qt::BackgroundRole );

        QSqlQuery qu;
        qu.prepare("select Balance, Password from CUSTOMER where AccountNo = :Account ");
        qu.bindValue(":Account",CurrentAccount);
        qu.exec();
        qu.first();
        Balance = qu.value(0).toInt();
        Pass = qu.value(1).toString();

    }
    QSqlDatabase::removeDatabase("db");
}

FundsTransfer1::~FundsTransfer1()
{
    delete ui;
}

void FundsTransfer1::ReceiveAcc(int CurrentAccount)
{
    ui->AccountNo->setText(QString::number(CurrentAccount));
}

void FundsTransfer1::on_ConfirmFundsTransferB_clicked()
{
    Amount = ui->FundsTransferAmountT->text().toInt();
    ui->FundsTransferPasswordT->text();
    if (ui->FundsTransferAccount->currentText() == "Choose Account")
    {
        ui->ErrorMessage->setText("Choose Recipient Account No.");
    }
    else {
        if(ui->FundsTransferPasswordT->text().isEmpty())
        {
            ui->ErrorMessage->setText("Enter your Password");
        }
        else {
            if (ui->FundsTransferPasswordT->text() != Pass)
            {
                ui->ErrorMessage->setText("Invalid Password");
            }
            else {
                if (ui->FundsTransferAmountT->text().isEmpty())
                {
                    ui->ErrorMessage->setText("Enter an Amount.");
                }
                else {
                    const QRegExp pattern1("[0-9][0-9]*");
                    QString Amount1 = ui->FundsTransferAmountT->text();
                    if (!(pattern1.exactMatch(Amount1)))
                    {
                        ui->ErrorMessage->setText("Enter a valid Amount.");
                    }
                    else {
                        if (Amount1.toInt() > Balance)
                        {
                            ui->ErrorMessage->setText("Insufficient Funds");
                        }
                        else {
                            int NewBalance = Balance - Amount1.toInt();
                            int CurrentAccount = ui->AccountNo->text().toInt();
                            QRandomGenerator *gen1 = QRandomGenerator::global();
                            int N = gen1->bounded(10000,99999);
                            QString Date = QDateTime::currentDateTime().toString("dd-MM-yy HH:mm:ss");
                            RecAccount = ui->FundsTransferAccount->currentText().left(8).toInt();

                            QSqlDatabase db;
                            db = QSqlDatabase::addDatabase("QSQLITE");
                            db.setDatabaseName("C:/ajbank.db");
                            db.open();
                            qDebug() << "DB Connected - FundsTransfer1";
                            QSqlQuery query;
                            query.prepare("update CUSTOMER set Balance = :Balance, FTrNo = :Tr, FDate = :Date, FAmount = :Amount, FAcc = :Rec where AccountNo = :Account ");
                            query.bindValue(":Account",CurrentAccount);
                            query.bindValue(":Balance",NewBalance);
                            query.bindValue(":Tr",N);
                            query.bindValue(":Date",Date);
                            query.bindValue(":Amount",Amount1.toInt());
                            query.bindValue(":Rec",RecAccount);
                            query.exec();

                            QSqlQuery qu;
                            qu.prepare("select Balance from CUSTOMER where AccountNo = :Account ");
                            qu.bindValue(":Account",RecAccount);
                            qu.exec();
                            qu.first();
                            RecBalance = qu.value(0).toInt();

                            RecNewBalance = RecBalance + Amount1.toInt();
                            qu.prepare("update CUSTOMER set Balance = :Balance where AccountNo = :Account ");
                            qu.bindValue(":Account",RecAccount);
                            qu.bindValue(":Balance",RecNewBalance);
                            qu.exec();

                            QObject::connect(this,SIGNAL(SendAcc(int)),fundstransfer2,SLOT(ReceiveAcc(int)));
                            emit SendAcc(CurrentAccount);
                            fundstransfer2->showMaximized();
                            this->hide();
                        }
                    }
                }
            }
        }

    }
}

void FundsTransfer1::on_LogoutButton_clicked()
{
    MenuBlank *ma = new MenuBlank();
    this->hide();
    ma->showMaximized();
}

void FundsTransfer1::on_BackButton_clicked()
{
    MainMenu *ma = new MainMenu();
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),ma,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    this->hide();
    ma->showMaximized();
}

void FundsTransfer1::on_SuggestButton_clicked()
{
    Suggestion *su = new Suggestion();
    su->show();
}
