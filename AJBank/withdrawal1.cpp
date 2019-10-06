#include "withdrawal1.h"
#include "ui_withdrawal1.h"
#include<menublank.h>
#include<suggestion.h>
#include<bankservices.h>
#include<QBitmap>
#include<QSqlQuery>
#include<QtSql>
Withdrawal1::Withdrawal1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Withdrawal1)
{
    ui->setupUi(this);
}

void Withdrawal1::showEvent( QShowEvent* event )
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
        qDebug() << "DB Connected - Withdrawal1";
        QSqlQuery query;
        query.prepare("select Balance from CUSTOMER where AccountNo = :Account ");
        query.bindValue(":Account",CurrentAccount);
        query.exec();
        query.first();
        ui->AccountBalance->setText(query.value(0).toString());
    }
    QSqlDatabase::removeDatabase("db");
}

Withdrawal1::~Withdrawal1()
{
    delete ui;
}

void Withdrawal1::ReceiveAcc(int CurrentAccount)
{
    ui->AccountNo->setText(QString::number(CurrentAccount));
}

void Withdrawal1::on_ConfirmWithdrawalB_clicked()
{
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
        qDebug() << "DB Connected - Withdrawal1";
        QSqlQuery query;
        query.prepare("select Balance from CUSTOMER where AccountNo = :Account ");
        query.bindValue(":Account",CurrentAccount);
        if(query.exec())
        {
            query.first();
            int Balance = query.value(0).toInt();
            ui->AccountBalance->setNum(Balance);
            int Amount = ui->WithdrawAmountT->text().toInt();
            if (Amount>Balance)
            {
                ui->ErrorMessage->setText("<font color=red>Insufficient Funds</font>");
            }
            else {
                QRandomGenerator *gen1 = QRandomGenerator::global();
                int N = gen1->bounded(10000,99999);
                QString Date = QDateTime::currentDateTime().toString("dd-MM-yy HH:mm:ss");
                int NewBalance = Balance - Amount;
                query.prepare("update CUSTOMER set Balance = :NewBalance, WitAmount = :Amount,WitDate = :Date, WitTrNo = :No where AccountNo = :Account ");
                query.bindValue(":Account",CurrentAccount);
                query.bindValue(":NewBalance",NewBalance);
                query.bindValue(":Amount",Amount);
                query.bindValue(":Date",Date);
                query.bindValue(":No",N);
                query.exec();
                QObject::connect(this,SIGNAL(SendAcc(int)),withdrawal2,SLOT(ReceiveAcc(int)));
                emit SendAcc(CurrentAccount);
                withdrawal2->show();
                this->hide();
            }
        }
        else
        {
            qDebug() << "Withdrawal Error";
        }
    }

    QSqlDatabase::removeDatabase("db");
}

void Withdrawal1::on_LogoutButton_clicked()
{
    MenuBlank *ma = new MenuBlank();
    this->hide();
    ma->showMaximized();
}

void Withdrawal1::on_BackButton_clicked()
{
    BankServices *ma = new BankServices();
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),ma,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    this->hide();
    ma->showMaximized();
}

void Withdrawal1::on_SuggestButton_clicked()
{
    Suggestion *su = new Suggestion();
    su->show();
}
