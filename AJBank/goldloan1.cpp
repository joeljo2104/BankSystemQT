#include "goldloan1.h"
#include "ui_goldloan1.h"
#include<loans.h>
#include<suggestion.h>
#include<menublank.h>
#include<QBitmap>
#include<QSqlQuery>
#include<QtSql>
GoldLoan1::GoldLoan1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GoldLoan1)
{
    ui->setupUi(this);

}

void GoldLoan1::showEvent( QShowEvent* event )
{
    QMainWindow::showEvent( event );
    setWindowIcon(QIcon(":/button/buttons/Logo.png"));
    QPixmap logout(":/button/buttons/Logout.png");
    ui->LogoutButton->setMask(logout.mask());
    QPixmap suggest(":/button/buttons/Suggest.png");
    ui->SuggestButton->setMask(suggest.mask());

    ui->GoldLoanAmountT->setText(QString::number(100000));
    float P,rate,time,interest;
    QString P1,rate1,time1;
    P1 = ui->GoldLoanAmountT->text();
    P = P1.toInt();
    rate = 10.65/100;
    time = ui->GoldLoanTime->value();
    interest = P*rate*time;
    Amount = interest + P;
    ui->GoldLoanInterest->setText(QString::number(interest,'f',2));
    ui->GoldLoanAmount->setText(QString::number(interest+P,'f',2));
    ui->GoldLoanRepayment->setText(QString::number((interest+P)/(12*time),'f',2));
}

GoldLoan1::~GoldLoan1()
{
    delete ui;
}

void GoldLoan1::ReceiveAcc(int CurrentAccount)
{
    ui->AccountNo->setText(QString::number(CurrentAccount));
}

void GoldLoan1::on_ConfirmGoldLoanB_clicked()
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
        qDebug() << "DB Connected - GoldLoan1";
        QSqlQuery query;
        QString Date = QDateTime::currentDateTime().toString("dd-MM-yy HH:mm:ss");
        QRandomGenerator *gen1 = QRandomGenerator::global();
        int N = gen1->bounded(10000,99999);
        query.prepare("update CUSTOMER set GLAppNo = :No, GLDate = :Date, GLAmount = :Amount where AccountNo = :Account ");
        query.bindValue(":Account",CurrentAccount);
        query.bindValue(":No",N);
        query.bindValue(":Date",Date);
        query.bindValue(":Amount",Amount);
        if(!query.exec())
        {
            qDebug() << "Gold Loan1 Error";
        }
    }
    QSqlDatabase::removeDatabase("db");

    QObject::connect(this,SIGNAL(SendAcc(int)),goldloan2,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    goldloan2->showMaximized();
    this->hide();
}

void GoldLoan1::on_GoldLoanTime_valueChanged(double arg1)
{
    float P,rate,time,interest;
    QString P1,rate1,time1;
    P1 = ui->GoldLoanAmountT->text();
    P = P1.toInt();
    rate = 10.65/100;
    time = arg1;
    interest = P*rate*time;
    ui->GoldLoanInterest->setText(QString::number(interest,'f',2));
    ui->GoldLoanAmount->setText(QString::number(interest+P,'f',2));
    ui->GoldLoanRepayment->setText(QString::number((interest+P)/(12*time),'f',2));
}

void GoldLoan1::on_GoldLoanSlider_valueChanged(int value)
{
    ui->GoldLoanAmountT->setText(QString::number(value));
    float P,rate,time,interest;
    QString P1,rate1,time1;
    P1 = ui->GoldLoanAmountT->text();
    P = P1.toInt();
    rate = 10.65/100;
    time = ui->GoldLoanTime->value();
    interest = P*rate*time;
    ui->GoldLoanInterest->setText(QString::number(interest,'f',2));
    ui->GoldLoanAmount->setText(QString::number(interest+P,'f',2));
    ui->GoldLoanRepayment->setText(QString::number((interest+P)/(12*time),'f',2));
}

void GoldLoan1::on_LogoutButton_clicked()
{
    MenuBlank *ma = new MenuBlank();
    this->hide();
    ma->showMaximized();
}

void GoldLoan1::on_BackButton_clicked()
{
    Loans *ma = new Loans();
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),ma,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    this->hide();
    ma->showMaximized();
}

void GoldLoan1::on_SuggestButton_clicked()
{
    Suggestion *su = new Suggestion();
    su->show();
}
