#include "carloan1.h"
#include "ui_carloan1.h"
#include<menublank.h>
#include<loans.h>
#include<suggestion.h>
#include<QBitmap>
#include<QSqlQuery>
#include<QtSql>
CarLoan1::CarLoan1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CarLoan1)
{
    ui->setupUi(this);
}

void CarLoan1::showEvent( QShowEvent* event )
{
    QMainWindow::showEvent( event );
    setWindowIcon(QIcon(":/button/buttons/Logo.png"));

    QPixmap logout(":/button/buttons/Logout.png");
    ui->LogoutButton->setMask(logout.mask());
    QPixmap suggest(":/button/buttons/Suggest.png");
    ui->SuggestButton->setMask(suggest.mask());

    ui->CarLoanAmountT->setText(QString::number(100000));
    float P,rate,time,interest;
    QString P1,rate1,time1;
    P1 = ui->CarLoanAmountT->text();
    P = P1.toInt();
    rate = 10.99/100;
    time = ui->CarLoanTime->value();
    interest = P*rate*time;
    Amount = interest + P;
    ui->CarLoanInterest->setText(QString::number(interest,'f',2));
    ui->CarLoanAmount->setText(QString::number(interest+P,'f',2));
    ui->CarLoanRepayment->setText(QString::number((interest+P)/(12*time),'f',2));
}

CarLoan1::~CarLoan1()
{
    delete ui;
}

void CarLoan1::ReceiveAcc(int CurrentAccount)
{
    ui->AccountNo->setText(QString::number(CurrentAccount));
}

void CarLoan1::on_CarLoanConfirmB_clicked()
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
        qDebug() << "DB Connected - CarLoan1";
        QSqlQuery query;
        QString Date = QDateTime::currentDateTime().toString("dd-MM-yy HH:mm:ss");
        QRandomGenerator *gen1 = QRandomGenerator::global();
        int N = gen1->bounded(10000,99999);
        query.prepare("update CUSTOMER set CLAppNo = :No, CLDate = :Date, CLAmount = :Amount where AccountNo = :Account ");
        query.bindValue(":Account",CurrentAccount);
        query.bindValue(":No",N);
        query.bindValue(":Date",Date);
        query.bindValue(":Amount",Amount);
        if(!query.exec())
        {
            qDebug() << "Car Loan1 Error";
        }
    }
    QSqlDatabase::removeDatabase("db");

    QObject::connect(this,SIGNAL(SendAcc(int)),carloan2,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    carloan2->showMaximized();
    this->hide();
}

void CarLoan1::on_CarLoanTime_valueChanged(double arg1)
{
    float P,rate,time,interest;
    QString P1,rate1,time1;
    P1 = ui->CarLoanAmountT->text();
    P = P1.toInt();
    rate = 8.65/100;
    time = arg1;
    interest = P*rate*time;
    ui->CarLoanInterest->setText(QString::number(interest,'f',2));
    ui->CarLoanAmount->setText(QString::number(interest+P,'f',2));
    ui->CarLoanRepayment->setText(QString::number((interest+P)/(12*time),'f',2));
}

void CarLoan1::on_CarLoanSlider_valueChanged(int value)
{
    ui->CarLoanAmountT->setText(QString::number(value));
    float P,rate,time,interest;
    QString P1,rate1,time1;
    P1 = ui->CarLoanAmountT->text();
    P = P1.toInt();
    rate = 10.99/100;
    time = ui->CarLoanTime->value();
    interest = P*rate*time;
    ui->CarLoanInterest->setText(QString::number(interest,'f',2));
    ui->CarLoanAmount->setText(QString::number(interest+P,'f',2));
    ui->CarLoanRepayment->setText(QString::number((interest+P)/(12*time),'f',2));
}

void CarLoan1::on_LogoutButton_clicked()
{
    MenuBlank *ma = new MenuBlank();
    this->hide();
    ma->showMaximized();
}

void CarLoan1::on_BackButton_clicked()
{
    Loans *ma = new Loans();
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),ma,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    this->hide();
    ma->showMaximized();
}

void CarLoan1::on_SuggestButton_clicked()
{
    Suggestion *su = new Suggestion();
    su->show();
}
