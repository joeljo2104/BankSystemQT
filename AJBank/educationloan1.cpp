#include "educationloan1.h"
#include "ui_educationloan1.h"
#include<menublank.h>
#include<suggestion.h>
#include<loans.h>
#include<QBitmap>
#include<QSqlQuery>
#include<QtSql>
EducationLoan1::EducationLoan1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EducationLoan1)
{
    ui->setupUi(this);

}

void EducationLoan1::showEvent( QShowEvent* event )
{
    QMainWindow::showEvent( event );
    setWindowIcon(QIcon(":/button/buttons/Logo.png"));
    QPixmap logout(":/button/buttons/Logout.png");
    ui->LogoutButton->setMask(logout.mask());
    QPixmap suggest(":/button/buttons/Suggest.png");
    ui->SuggestButton->setMask(suggest.mask());
    ui->EducationLoanAmountT->setText(QString::number(100000));
    float P,rate,time,interest;
    QString P1,rate1,time1;
    P1 = ui->EducationLoanAmountT->text();
    P = P1.toInt();
    rate = 10.99/100;
    time = ui->EducationLoanTime->value();
    interest = P*rate*time;
    Amount = interest + P;
    ui->EducationLoanInterest->setText(QString::number(interest,'f',2));
    ui->EducationLoanAmount->setText(QString::number(interest+P,'f',2));
    ui->EducationLoanRepayment->setText(QString::number((interest+P)/(12*time),'f',2));
}

EducationLoan1::~EducationLoan1()
{
    delete ui;
}

void EducationLoan1::ReceiveAcc(int CurrentAccount)
{
    ui->AccountNo->setText(QString::number(CurrentAccount));
}

void EducationLoan1::on_ConfirmEducationLoanB_clicked()
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
        qDebug() << "DB Connected - EducationLoan1";
        QSqlQuery query;
        QString Date = QDateTime::currentDateTime().toString("dd-MM-yy HH:mm:ss");
        QRandomGenerator *gen1 = QRandomGenerator::global();
        int N = gen1->bounded(10000,99999);
        query.prepare("update CUSTOMER set ELAppNo = :No, ELDate = :Date, ELAmount = :Amount where AccountNo = :Account ");
        query.bindValue(":Account",CurrentAccount);
        query.bindValue(":No",N);
        query.bindValue(":Date",Date);
        query.bindValue(":Amount",Amount);
        if(!query.exec())
        {
            qDebug() << "Education Loan1 Error";
        }
    }
    QSqlDatabase::removeDatabase("db");

    QObject::connect(this,SIGNAL(SendAcc(int)),educationloan2,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    educationloan2->showMaximized();
    this->hide();
}

void EducationLoan1::on_EducationLoanTime_valueChanged(double arg1)
{
    double P,rate,time,interest;
    QString P1,rate1,time1;
    P1 = ui->EducationLoanAmountT->text();
    P = P1.toInt();
    rate = 10.99/100;
    time = arg1;
    interest = P*rate*time;
    ui->EducationLoanInterest->setText(QString::number(interest,'f',2));
    ui->EducationLoanAmount->setText(QString::number(interest+P,'f',2));
    ui->EducationLoanRepayment->setText(QString::number((interest+P)/(12*time),'f',2));
}

void EducationLoan1::on_EducationLoanSlider_valueChanged(int value)
{
    ui->EducationLoanAmountT->setText(QString::number(value));
    float P,rate,time,interest;
    QString P1,rate1,time1;
    P1 = ui->EducationLoanAmountT->text();
    P = P1.toInt();
    rate = 10.99/100;
    time = ui->EducationLoanTime->value();
    interest = P*rate*time;
    ui->EducationLoanInterest->setText(QString::number(interest,'f',2));
    ui->EducationLoanAmount->setText(QString::number(interest+P,'f',2));
    ui->EducationLoanRepayment->setText(QString::number((interest+P)/(12*time),'f',2));
}

void EducationLoan1::on_LogoutButton_clicked()
{
    MenuBlank *ma = new MenuBlank();
    this->hide();
    ma->showMaximized();
}

void EducationLoan1::on_BackButton_clicked()
{
    Loans *ma = new Loans();
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),ma,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    this->hide();
    ma->showMaximized();
}

void EducationLoan1::on_SuggestButton_clicked()
{
    Suggestion *su = new Suggestion();
    su->show();
}
