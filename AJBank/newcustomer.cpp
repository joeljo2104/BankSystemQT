#include "newcustomer.h"
#include "ui_newcustomer.h"
#include<QBitmap>
#include<menublank.h>
#include<suggestion.h>
#include<QRegExp>
#include<QSqlQuery>
#include<QRandomGenerator>
#include<QSqlError>
NewCustomer::NewCustomer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewCustomer)
{
    ui->setupUi(this);
}

void NewCustomer::showEvent( QShowEvent* event )
{
    QMainWindow::showEvent( event );
    setWindowIcon(QIcon(":/button/buttons/Logo.png"));
    QPixmap suggest(":/button/buttons/Suggest.png");
    ui->SuggestButton->setMask(suggest.mask());

    setTabOrder(ui->NewNameT,ui->NewGender);
    setTabOrder(ui->NewGender,ui->NewEmailIDT);
    setTabOrder(ui->NewEmailIDT,ui->NewDOB);
    setTabOrder(ui->NewDOB,ui->NewPhone1T);
    setTabOrder(ui->NewPhone1T,ui->NewAddressT);
    setTabOrder(ui->NewAddressT,ui->CreateUsernameB);
}

NewCustomer::~NewCustomer()
{
    delete ui;
}

void NewCustomer::on_CreateUsernameB_clicked()
{
    int n = 0;
    if (ui->NewNameT->text().isEmpty())
    {
        ui->ErrorMessage->setText("Please enter a valid Name!");
    }
    else {
        n++;
        ui->ErrorMessage->setText("");
        const QRegExp pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
        QString Email = ui->NewEmailIDT->text();
        if (!(pattern.exactMatch(Email)))
        {
            ui->ErrorMessage->setText("Please enter a valid EmailID!");
        }
        else {
            n++;
            ui->ErrorMessage->setText("");
            const QRegExp pattern1("[0-9][0-9]*");
            QString Phone = ui->NewPhone1T->text();
            if (!(pattern1.exactMatch(Phone)))
            {
                ui->ErrorMessage->setText("Please enter a valid PhoneNumber!");
            }
            else {
                n++;
                ui->ErrorMessage->setText("");
                if (ui->NewAddressT->text().isEmpty())
                {
                    ui->ErrorMessage->setText("Please enter a valid Address!");
                }
                else {
                    n++;
                    ui->ErrorMessage->setText("");
                }
            }
        }
    }

    QRandomGenerator *gen1 = QRandomGenerator::global();
    int CurrentAccount = gen1->bounded(10000000,99999999);

    QString CAccount,CName,CGender,CEmailID,CDoB,CPhoneNumber,CAddress,CUserName,CPassword;
    CAccount = QString::number(CurrentAccount);
    CName = ui->NewNameT->text();
    CGender = ui->NewGender->currentText();
    CDoB = ui->NewDOB->date().toString();
    CEmailID = ui->NewEmailIDT->text();
    CPhoneNumber = ui->NewPhone1T->text();
    CAddress = ui->NewAddressT->text();
    CUserName = '0';
    CPassword = '0';
    if (n==4)
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
            qDebug() << "DB Connected - NewCustomer";
            QSqlQuery query;
            query.prepare("insert into CUSTOMER (AccountNo,Name,Gender,EmailID,DoB,PhoneNumber,Address,UserName,Password) values (:AccountNo,:Name,:Gender,:EmailID,:DoB,:PhoneNumber,:Address,:UserName,:Password) ");
            query.bindValue(":AccountNo",CAccount);
            query.bindValue(":Name",CName);
            query.bindValue(":Gender",CGender);
            query.bindValue(":EmailID",CEmailID);
            query.bindValue(":DoB",CDoB);
            query.bindValue(":PhoneNumber",CPhoneNumber);
            query.bindValue(":Address",CAddress);
            query.bindValue(":UserName",CUserName);
            query.bindValue(":Password",CPassword);

            if(!query.exec())
            {
                qDebug() << "New Customer Error";
            }
            else
            {
                n+=1;
            }
        }
        QSqlDatabase::removeDatabase("db");

        QObject::connect(this,SIGNAL(SendAcc(int)),username,SLOT(ReceiveAcc(int)));
        emit SendAcc(CurrentAccount);
        if (n==5)
        {
            username->showMaximized();
            this->hide();
        }
        else {
            ui->ErrorMessage->setText("Something went wrong...");
        }

    }
}

void NewCustomer::on_BackButton_clicked()
{
    MenuBlank *ma = new MenuBlank();
    this->hide();
    ma->showMaximized();
}

void NewCustomer::on_SuggestButton_clicked()
{
    Suggestion *su = new Suggestion();
    su->show();
}
