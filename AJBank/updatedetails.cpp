#include "updatedetails.h"
#include "ui_updatedetails.h"
#include<QBitmap>
#include<bankservices.h>
#include<suggestion.h>
#include<menublank.h>
#include<QtSql>
#include<QRegExp>
UpdateDetails::UpdateDetails(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UpdateDetails)
{
    ui->setupUi(this);
}

UpdateDetails::~UpdateDetails()
{
    delete ui;
}

void UpdateDetails::showEvent( QShowEvent* event )
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
        ui->SelectedDetail->addItem("Name - " + query.value(1).toString());
        ui->SelectedDetail->addItem("EmailID - " + query.value(3).toString());
        ui->SelectedDetail->addItem("Date of Birth - " + query.value(4).toString());
        ui->SelectedDetail->addItem("Phone No - " + query.value(5).toString());
        ui->SelectedDetail->addItem("Address - " + query.value(6).toString());
        ui->SelectedDetail->setItemData( 0, QColor( Qt::white ), Qt::BackgroundRole );
        ui->SelectedDetail->setItemData( 1, QColor( Qt::white ), Qt::BackgroundRole );
        ui->SelectedDetail->setItemData( 2, QColor( Qt::white ), Qt::BackgroundRole );
        ui->SelectedDetail->setItemData( 3, QColor( Qt::white ), Qt::BackgroundRole );
        ui->SelectedDetail->setItemData( 4, QColor( Qt::white ), Qt::BackgroundRole );
    }
    QSqlDatabase::removeDatabase("db");

}

void UpdateDetails::ReceiveAcc(int CurrentAccount)
{
    ui->AccountNo->setText(QString::number(CurrentAccount));
}

void UpdateDetails::on_SuggestButton_clicked()
{
    Suggestion *su = new Suggestion();
    su->show();
}

void UpdateDetails::on_LogoutButton_clicked()
{
    MenuBlank *ma = new MenuBlank();
    this->hide();
    ma->showMaximized();
}

void UpdateDetails::on_BackButton_clicked()
{
    BankServices *ma = new BankServices();
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),ma,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    this->hide();
    ma->showMaximized();
}

void UpdateDetails::on_UpdateB_clicked()
{
    int CurrentAccount = ui->AccountNo->text().toInt();
    QSqlQuery query;
    QString select = ui->SelectedDetail->currentText().left(5);
    QString detail = ui->NewUsernameT->text();
    if (select == "Name ")
    {
        if (ui->NewUsernameT->text().isEmpty())
        {
            ui->Display->setText("Please enter a valid Name!");
        }
        else
        {query.prepare("update CUSTOMER set Name = :Name where AccountNo = :Account ");
            query.bindValue(":Account",CurrentAccount);
            query.bindValue(":Name",detail);
            if(!query.exec())
            {
                qDebug()<< "didnt execute";
            }
            else {
                ui->Display->setText("Updated Successfully!");
            }
        }
    }

    else if (select == "Email")
    {
        const QRegExp pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
        if (!(pattern.exactMatch(detail)))
        {
            ui->Display->setText("Please enter a valid EmailID!");
        }
        else {
            ui->Display->setText("Updated Successfully!");
            query.prepare("update CUSTOMER set EmailID = :EmailID where AccountNo = :Account ");
            query.bindValue(":Account",CurrentAccount);
            query.bindValue(":EmailID",detail);
            if(!query.exec())
            {
                qDebug()<< "didnt execute";
            }
        }
    }
    else if (select == "Date ")
    {
        query.prepare("update CUSTOMER set DoB = :DoB where AccountNo = :Account ");
        query.bindValue(":Account",CurrentAccount);
        query.bindValue(":DoB",detail);
        if(!query.exec())
        {
            qDebug()<< "didnt execute";
        }
        else {
            ui->Display->setText("Updated Successfully!");
        }

    }
    else if (select == "Phone")
    {
        const QRegExp pattern1("[0-9][0-9]*");
        QString Phone = ui->Display->text();
        if (!(pattern1.exactMatch(detail)))
        {
            ui->Display->setText("Please enter a valid PhoneNumber!");
        }
        else
        {query.prepare("update CUSTOMER set PhoneNumber = :PhoneNumber where AccountNo = :Account ");
            query.bindValue(":Account",CurrentAccount);
            query.bindValue(":PhoneNumber",detail);
            if(!query.exec())
            {
                qDebug()<< "didnt execute";
            }

            else {
                ui->Display->setText("Updated Successfully!");
            }}

    }
    else if (select == "Addre")
    {   if (ui->NewUsernameT->text().isEmpty())
        {
            ui->Display->setText("Please enter a valid Address!");
        }
        else
        {query.prepare("update CUSTOMER set Address = :Address where AccountNo = :Account ");
            query.bindValue(":Account",CurrentAccount);
            query.bindValue(":Address",detail);
            if(!query.exec())
            {
                qDebug()<< "didnt execute";
            }
            else {
                ui->Display->setText("Updated Successfully!");
            }
        }
    }

    ui->SelectedDetail->clear();
    QSqlQuery query1;
    query1.prepare("select * from CUSTOMER where AccountNo = :Account ");
    query1.bindValue(":Account",CurrentAccount);
    query1.exec();
    query1.first();
    ui->SelectedDetail->addItem("Name - " + query1.value(1).toString());
    ui->SelectedDetail->addItem("EmailID - " + query1.value(3).toString());
    ui->SelectedDetail->addItem("Date of Birth - " + query1.value(4).toString());
    ui->SelectedDetail->addItem("Phone No - " + query1.value(5).toString());
    ui->SelectedDetail->addItem("Address - " + query1.value(6).toString());
    ui->SelectedDetail->setItemData( 0, QColor( Qt::white ), Qt::BackgroundRole );
    ui->SelectedDetail->setItemData( 1, QColor( Qt::white ), Qt::BackgroundRole );
    ui->SelectedDetail->setItemData( 2, QColor( Qt::white ), Qt::BackgroundRole );
    ui->SelectedDetail->setItemData( 3, QColor( Qt::white ), Qt::BackgroundRole );
    ui->SelectedDetail->setItemData( 4, QColor( Qt::white ), Qt::BackgroundRole );

    QSqlDatabase::removeDatabase("db");
}
