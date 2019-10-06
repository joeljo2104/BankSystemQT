#include "deposit1.h"
#include "ui_deposit1.h"
#include<menublank.h>
#include<bankservices.h>
#include<suggestion.h>
#include<QBitmap>
#include<QSqlQuery>
#include<QSqlRecord>
#include<QtSql>
Deposit1::Deposit1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Deposit1)
{
    ui->setupUi(this);
}

void Deposit1::showEvent( QShowEvent* event )
{
    QMainWindow::showEvent( event );
    setWindowIcon(QIcon(":/button/buttons/Logo.png"));
    QPixmap logout(":/button/buttons/Logout.png");
    ui->LogoutButton->setMask(logout.mask());
    QPixmap suggest(":/button/buttons/Suggest.png");
    ui->SuggestButton->setMask(suggest.mask());

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
        qDebug() << "DB Connected - Deposit1";
        QSqlQuery query;
        query.prepare("select Balance from CUSTOMER where AccountNo = :Account ");
        query.bindValue(":Account",CurrentAccount);
        query.exec();
        query.first();
        int Balance = query.value(0).toInt();
        ui->AccountBalance->setText(query.value(0).toString());
    }
    QSqlDatabase::removeDatabase("db");
}

Deposit1::~Deposit1()
{
    delete ui;
}

void Deposit1::ReceiveAcc(int CurrentAccount)
{
    ui->AccountNo->setText(QString::number(CurrentAccount));
}

void Deposit1::on_ConfirmDepositB_clicked()
{
    int CurrentAccount = ui->AccountNo->text().toInt();
    int Amount = ui->DepositAmountT->text().toInt();
    if (Amount == 0)
    {
        ui->ErrorMessage->setText("Enter an valid Amount.");
    }
    else {
        QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/ajbank.db");
        if(!db.open())
        {
            qDebug() << "Can't Connect to DB !";
        }
        else
        {
            qDebug() << "DB Connected - Deposit1.1";
            QSqlQuery query;
            query.prepare("select Balance from CUSTOMER where AccountNo = :Account ");
            query.bindValue(":Account",CurrentAccount);
            if(query.exec())
            {
                query.first();
                int Balance = query.value(0).toInt();
                ui->AccountBalance->setText(query.value(0).toString());
                int Amount = ui->DepositAmountT->text().toInt();
                QRandomGenerator *gen1 = QRandomGenerator::global();
                int N = gen1->bounded(10000,99999);
                QString Date = QDateTime::currentDateTime().toString("dd-MM-yy HH:mm:ss");
                int NewBalance = Balance + Amount;
                query.prepare("update CUSTOMER set Balance = :NewBalance, DepAmount = :Amount, DepDate = :Date, DepTrNo = :No where AccountNo = :Account ");
                query.bindValue(":Account",CurrentAccount);
                query.bindValue(":NewBalance",NewBalance);
                query.bindValue(":Amount",Amount);
                query.bindValue(":Date",Date);
                query.bindValue(":No",N);
                query.exec();
                QObject::connect(this,SIGNAL(SendAcc(int)),deposit2,SLOT(ReceiveAcc(int)));
                emit SendAcc(CurrentAccount);
                deposit2->show();
                this->hide();
            }
            else
            {
                qDebug() << "Deposit Error";
            }
        }

        QSqlDatabase::removeDatabase("db");
    }
}

void Deposit1::on_LogoutButton_clicked()
{
    MenuBlank *ma = new MenuBlank();
    this->hide();
    ma->showMaximized();
}

void Deposit1::on_BackButton_clicked()
{
    BankServices *ma = new BankServices();
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),ma,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    this->hide();
    ma->showMaximized();
}

void Deposit1::on_SuggestButton_clicked()
{
    Suggestion *su = new Suggestion();
    su->show();
}
