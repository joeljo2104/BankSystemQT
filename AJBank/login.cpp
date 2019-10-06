#include "login.h"
#include "ui_login.h"
#include<QBitmap>
#include<menublank.h>
#include<suggestion.h>
#include<QSqlQuery>
#include<welcomewindow.h>

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

void Login::showEvent( QShowEvent* event )
{
    QMainWindow::showEvent( event );
    setWindowIcon(QIcon(":/button/buttons/Logo.png"));
    QPixmap suggest(":/button/buttons/Suggest.png");
    ui->SuggestButton->setMask(suggest.mask());
}

Login::~Login()
{
    delete ui;
}

void Login::on_LoginB_clicked()
{
    User = ui->LoginUsernameT->text();
    Pass = ui->LoginPasswordT->text();

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/ajbank.db");
    if(!db.open())
    {
        qDebug() << "Can't Connect to DB !";
    }
    else
    {
        qDebug() << "DB Connected - Login";
        QSqlQuery query;
        if(query.exec("select * from CUSTOMER where UserName = '"+User+"' and Password = '"+Pass+"'"))
        {
            int count = 0;
            while (query.next())
            {
                count++;
            }
            if (count==1)
            {
                query.first();
                int CurrentAccount = query.value(0).toInt();
                QObject::connect(this,SIGNAL(SendAcc(int)),mainm,SLOT(ReceiveAcc(int)));
                emit SendAcc(CurrentAccount);
                mainm->showMaximized();
                this->hide();
            }
            else {
                ui->ErrorMessage->setText("Incorrect Username or Password.");
            }
        }
        else
        {
            qDebug() << "Login Error";
        }
    }
    db.close();
    QSqlDatabase::removeDatabase("db");
}

void Login::on_BackButton_clicked()
{
    WelcomeWindow *ma = new WelcomeWindow();
    this->hide();
    ma->showMaximized();
}

void Login::on_SuggestButton_clicked()
{
    Suggestion *su = new Suggestion();
    su->show();
}
