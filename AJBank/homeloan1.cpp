#include "homeloan1.h"
#include "ui_homeloan1.h"
#include<menublank.h>
#include<suggestion.h>
#include<loans.h>
#include<QBitmap>
#include<QSqlQuery>
#include<QtSql>
HomeLoan1::HomeLoan1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomeLoan1)
{
    ui->setupUi(this);
}

void HomeLoan1::showEvent( QShowEvent* event )
{
    QMainWindow::showEvent( event );
    setWindowIcon(QIcon(":/button/buttons/Logo.png"));
    QPixmap logout(":/button/buttons/Logout.png");
    ui->LogoutButton->setMask(logout.mask());
    QPixmap suggest(":/button/buttons/Suggest.png");
    ui->SuggestButton->setMask(suggest.mask());

    ui->HomeLoanAmountT->setText(QString::number(100000));
    float P,rate,time,interest;
    QString P1,rate1,time1;
    P1 = ui->HomeLoanAmountT->text();
    P = P1.toInt();
    rate = 8.95/100;
    time = ui->HomeLoanTime->value();
    interest = P*rate*time;
    Amount = interest + P;
    ui->HomeLoanInterest->setText(QString::number(interest,'f',2));
    ui->HomeLoanAmount->setText(QString::number(interest+P,'f',2));
    ui->HomeLoanRepayment->setText(QString::number((interest+P)/(12*time),'f',2));
}


HomeLoan1::~HomeLoan1()
{
    delete ui;
}

void HomeLoan1::ReceiveAcc(int CurrentAccount)
{
    ui->AccountNo->setText(QString::number(CurrentAccount));
}

void HomeLoan1::on_ConfirmHomeLoanB_clicked()
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
        qDebug() << "DB Connected - HomeLoan1";
        QSqlQuery query;
        QString Date = QDateTime::currentDateTime().toString("dd-MM-yy HH:mm:ss");
        QRandomGenerator *gen1 = QRandomGenerator::global();
        int N = gen1->bounded(10000,99999);
        query.prepare("update CUSTOMER set HLAppNo = :No, HLDate = :Date, HLAmount = :Amount where AccountNo = :Account ");
        query.bindValue(":Account",CurrentAccount);
        query.bindValue(":No",N);
        query.bindValue(":Date",Date);
        query.bindValue(":Amount",Amount);
        if(!query.exec())
        {
            qDebug() << "Home Loan1 Error";
        }
    }
    QSqlDatabase::removeDatabase("db");

    QObject::connect(this,SIGNAL(SendAcc(int)),homeloan2,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    homeloan2->showMaximized();
    this->hide();
}

void HomeLoan1::on_HomeLoanTime_valueChanged(double arg1)
{
    double P,rate,time,interest;
    QString P1,rate1,time1;
    P1 = ui->HomeLoanAmountT->text();
    P = P1.toInt();
    rate = 8.95/100;
    time = arg1;
    interest = P*rate*time;
    ui->HomeLoanInterest->setText(QString::number(interest,'f',2));
    ui->HomeLoanAmount->setText(QString::number(interest+P,'f',2));
    ui->HomeLoanRepayment->setText(QString::number((interest+P)/(12*time),'f',2));
}

void HomeLoan1::on_HomeLoanSlider_valueChanged(int value)
{
    ui->HomeLoanAmountT->setText(QString::number(value));
    float P,rate,time,interest;
    QString P1,rate1,time1;
    P1 = ui->HomeLoanAmountT->text();
    P = P1.toInt();
    rate = 8.95/100;
    time = ui->HomeLoanTime->value();
    interest = P*rate*time;
    ui->HomeLoanInterest->setText(QString::number(interest,'f',2));
    ui->HomeLoanAmount->setText(QString::number(interest+P,'f',2));
    ui->HomeLoanRepayment->setText(QString::number((interest+P)/(12*time),'f',2));
}

void HomeLoan1::on_LogoutButton_clicked()
{
    MenuBlank *ma = new MenuBlank();
    this->hide();
    ma->showMaximized();
}

void HomeLoan1::on_BackButton_clicked()
{
    Loans *ma = new Loans();
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),ma,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    this->hide();
    ma->showMaximized();
}

void HomeLoan1::on_SuggestButton_clicked()
{
    Suggestion *su = new Suggestion();
    su->show();
}
