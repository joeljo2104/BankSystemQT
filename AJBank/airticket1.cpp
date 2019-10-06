#include "airticket1.h"
#include "ui_airticket1.h"
#include<menublank.h>
#include<suggestion.h>
#include<tickets.h>
#include <QBitmap>
#include<QSqlQuery>
#include<QtSql>
#include<QRandomGenerator>
AirTicket1::AirTicket1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AirTicket1)
{
    ui->setupUi(this);

}

void AirTicket1::showEvent( QShowEvent* event )
{
    QMainWindow::showEvent( event );
    setWindowIcon(QIcon(":/button/buttons/Logo.png"));

    QPixmap logout(":/button/buttons/Logout.png");
    ui->LogoutButton->setMask(logout.mask());
    QPixmap suggest(":/button/buttons/Suggest.png");
    ui->SuggestButton->setMask(suggest.mask());
}

AirTicket1::~AirTicket1()
{
    delete ui;
}

void AirTicket1::ReceiveAcc(int CurrentAccount)
{
    ui->AccountNo->setText(QString::number(CurrentAccount));
}

void AirTicket1::on_ConfirmAirTicketB_clicked()
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
        qDebug() << "DB Connected - AirTicket1 ";
        QSqlQuery query;
        query.prepare("select Balance from CUSTOMER where AccountNo = :Account ");
        query.bindValue(":Account",CurrentAccount);
        if(query.exec())
        {
            query.first();
            int Balance = query.value(0).toInt();
            if (ui->AirTicketAmount->text().isEmpty() || ui->AirTicketAmount->text().toInt() == 0){
                ui->ErrorMessage->setText("<font color=red>Choose Tickets</font>");
            }
            else if (Amount>Balance)
            {
                ui->ErrorMessage->setText("<font color=red>Insufficient Funds</font>");
            }
            else {
                Amount = ui->AirTicketAmount->text().toInt();
                int NewBalance = Balance - Amount;
                QRandomGenerator *gen1 = QRandomGenerator::global();
                int N = gen1->bounded(10000,99999);
                QString Date = QDateTime::currentDateTime().toString("dd-MM-yy HH:mm:ss");
                query.prepare("update CUSTOMER set Balance = :NewBalance, ATAmount = :Amount, ATDate = :Date, ATTrNo = :No where AccountNo = :Account ");
                query.bindValue(":Account",CurrentAccount);
                query.bindValue(":NewBalance",NewBalance);
                query.bindValue(":Amount",Amount);
                query.bindValue(":Date",Date);
                query.bindValue(":No",N);
                query.exec();
                QObject::connect(this,SIGNAL(SendAcc(int)),airticket2,SLOT(ReceiveAcc(int)));
                emit SendAcc(CurrentAccount);
                airticket2->show();
                this->hide();
            }
        }
        else
        {
            qDebug() << "Air Ticket Error";
        }
    }
    QSqlDatabase::removeDatabase("db");
}

void AirTicket1::on_FirstClassB_clicked()
{
    Type = "First";
    int Seats = ui->NoofSeats->value();
    int Amount = 60000*Seats;
    QString A = QString::number(Amount);
    ui->AirTicketAmount->setText(A);
    ui->Currency->setText("₹");
}

void AirTicket1::on_BusinessClassB_clicked()
{
    Type = "Business";
    int Seats = ui->NoofSeats->value();
    int Amount = 40000*Seats;
    QString A = QString::number(Amount);
    ui->AirTicketAmount->setText(A);
    ui->Currency->setText("₹");
}

void AirTicket1::on_EconomyClassB_clicked()
{
    Type = "Economy";
    int Seats = ui->NoofSeats->value();
    int Amount = 20000*Seats;
    QString A = QString::number(Amount);
    ui->AirTicketAmount->setText(A);
    ui->Currency->setText("₹");
}

void AirTicket1::on_NoofSeats_valueChanged(int arg1)
{
    if (Type == "First")
    {
        int Seats = arg1;
        Amount = 60000*Seats;
    }
    if (Type == "Business")
    {
        int Seats = arg1;
        Amount = 40000*Seats;
    }
    if (Type == "Economy")
    {
        int Seats = arg1;
        Amount = 20000*Seats;
    }
    QString A = QString::number(Amount);
    ui->AirTicketAmount->setText(A);
    ui->Currency->setText("₹");
}

void AirTicket1::on_LogoutButton_clicked()
{
    MenuBlank *ma = new MenuBlank();
    this->hide();
    ma->showMaximized();
}

void AirTicket1::on_BackButton_clicked()
{
    Tickets *ma = new Tickets();
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),ma,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    this->hide();
    ma->showMaximized();
}

void AirTicket1::on_SuggestButton_clicked()
{
    Suggestion *su = new Suggestion();
    su->show();
}
