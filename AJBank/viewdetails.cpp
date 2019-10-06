#include "viewdetails.h"
#include "ui_viewdetails.h"
#include<suggestion.h>
#include<menublank.h>
#include<mainmenu.h>
#include<bankservices.h>
#include<QBitmap>
#include<QSql>
#include<QSqlQuery>
#include<QtSql>

ViewDetails::ViewDetails(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ViewDetails)
{
    ui->setupUi(this);
}

void ViewDetails::showEvent( QShowEvent* event )
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
        qDebug() << "DB Connected - ViewDetails";
        QSqlQuery query;
        query.prepare("select * from CUSTOMER where AccountNo = :Account ");
        query.bindValue(":Account",CurrentAccount);
        query.exec();
        query.first();
        ui->CustomerName->setText(query.value(1).toString());
        ui->CustomerGender->setText(query.value(2).toString());
        ui->CustomerEmailID->setText(query.value(3).toString());
        ui->CustomerDOB->setText(query.value(4).toString());
        ui->CustomerPhone->setText(query.value(5).toString());
        ui->CustomerAddress->setText(query.value(6).toString());
        ui->CustomerBalance->setText("₹ "+query.value(9).toString());
    }
    QSqlDatabase::removeDatabase("db");
}

ViewDetails::~ViewDetails()
{
    delete ui;
}

void ViewDetails::ReceiveAcc(int CurrentAccount)
{
    ui->AccountNo->setText(QString::number(CurrentAccount));
}

void ViewDetails::on_MainMenuB_clicked()
{
    MainMenu *mainm = new MainMenu();
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),mainm,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    mainm->showMaximized();
    this->hide();
}

void ViewDetails::on_LogoutButton_clicked()
{
    MenuBlank *ma = new MenuBlank();
    this->hide();
    ma->showMaximized();
}

void ViewDetails::on_BackButton_clicked()
{
    BankServices *ma = new BankServices();
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),ma,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    this->hide();
    ma->showMaximized();
}

void ViewDetails::on_SuggestButton_clicked()
{
    Suggestion *su = new Suggestion();
    su->show();
}
