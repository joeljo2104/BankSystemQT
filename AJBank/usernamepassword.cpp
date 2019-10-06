#include "usernamepassword.h"
#include "ui_usernamepassword.h"
#include<QBitmap>
#include<suggestion.h>
#include<newcustomer.h>
#include<QRandomGenerator>
#include<QSqlQuery>

UserNamePassword::UserNamePassword(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserNamePassword)
{
    ui->setupUi(this);
}

void UserNamePassword::showEvent( QShowEvent* event )
{
    QMainWindow::showEvent( event );
    setWindowIcon(QIcon(":/button/buttons/Logo.png"));
    QPixmap suggest(":/button/buttons/Suggest.png");
    ui->SuggestButton->setMask(suggest.mask());

    setTabOrder(ui->NewUsernameT,ui->NewPasswordT);
    setTabOrder(ui->NewPasswordT,ui->NewPassword2T);
    setTabOrder(ui->NewPassword2T,ui->ProceedB);
}

UserNamePassword::~UserNamePassword()
{
    delete ui;
}

void UserNamePassword::ReceiveAcc(int CurrentAccount)
{
    ui->AccountNo->setText(QString::number(CurrentAccount));
}

void UserNamePassword::on_ProceedB_clicked()
{
    QString user = ui->NewUsernameT->text();
    int n = 0;
    if (user == "")
        ui->ErrorMessage->setText("Please enter a valid Username");
    else {
        QString pass1 = ui->NewPasswordT->text();
        QString pass2 = ui->NewPassword2T->text();
        if (pass1 == "")
            ui->ErrorMessage->setText("Please enter a valid Password");
        else {
            if (pass1 != pass2)
            {
                ui->ErrorMessage->setText("Please reenter your Password");
            }
            else
                n=1;
        }
    }

    QString CUserName,CPassword;
    CUserName = ui->NewUsernameT->text();
    CPassword = ui->NewPasswordT->text();
    int CurrentAccount = ui->AccountNo->text().toInt();
    if (n==1)
    {
        QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/ajbank.db");
        if(!db.open())
        {
            qDebug() << "Can't Connect to DB !";
        }
        else
        {
            QSqlQuery qu;
            if(qu.exec("select * from CUSTOMER where UserName = '"+CUserName+"'"))
            {
                int count = 0;
                while (qu.next())
                {
                    count++;
                }
                if (count>0)
                {
                    ui->ErrorMessage->setText("Please try a different UserName");
                }
                else {
                    qDebug() << "DB Connected - UserPass";
                    QSqlQuery query;
                    query.prepare("update CUSTOMER set UserName = :UserName, Password = :Password where AccountNo = :Account ");
                    query.bindValue(":Account",CurrentAccount);
                    query.bindValue(":UserName",CUserName);
                    query.bindValue(":Password",CPassword);

                    if(!query.exec())
                    {
                        qDebug() << "UserName Password Error";
                    }
                    else
                    {
                        n+=1;
                    }
                }
                QSqlDatabase::removeDatabase("db");
            }
            if (n==2)
            {
                login->showMaximized();
                this->hide();
            }
        }
    }
}

void UserNamePassword::on_BackButton_clicked()
{
    NewCustomer *ma = new NewCustomer();
    this->hide();
    ma->showMaximized();
}

void UserNamePassword::on_SuggestButton_clicked()
{
    Suggestion *su = new Suggestion();
    su->show();
}
