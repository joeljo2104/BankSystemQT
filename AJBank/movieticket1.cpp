#include "movieticket1.h"
#include "ui_movieticket1.h"
#include<menublank.h>
#include<suggestion.h>
#include<tickets.h>
#include<QBitmap>
#include<QSqlQuery>
#include<QtSql>
MovieTicket1::MovieTicket1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MovieTicket1)
{
    ui->setupUi(this);
}

void MovieTicket1::showEvent( QShowEvent* event )
{
    QMainWindow::showEvent( event );
    setWindowIcon(QIcon(":/button/buttons/Logo.png"));
    QPixmap logout(":/button/buttons/Logout.png");
    ui->LogoutButton->setMask(logout.mask());
    QPixmap suggest(":/button/buttons/Suggest.png");
    ui->SuggestButton->setMask(suggest.mask());
}

MovieTicket1::~MovieTicket1()
{
    delete ui;
}

void MovieTicket1::ReceiveAcc(int CurrentAccount)
{
    ui->AccountNo->setText(QString::number(CurrentAccount));
}

void MovieTicket1::on_ConfirmMovieTicket_clicked()
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
        qDebug() << "DB Connected - MovieTicket1 ";
        QSqlQuery query;
        query.prepare("select Balance from CUSTOMER where AccountNo = :Account ");
        query.bindValue(":Account",CurrentAccount);
        if(query.exec())
        {
            query.first();
            int Balance = query.value(0).toInt();
            if (Amount>Balance)
            {
                ui->ErrorMessage->setText("<font color=red>Insufficient Funds</font>");
            }
            else if (ui->MovieTicketAmount->text().isEmpty() || ui->MovieTicketAmount->text().toInt() == 0){
                ui->ErrorMessage->setText("<font color=red>Choose Tickets</font>");
            }
            else {
                Amount = ui->MovieTicketAmount->text().toInt();
                int NewBalance = Balance - Amount;
                QRandomGenerator *gen1 = QRandomGenerator::global();
                int N = gen1->bounded(10000,99999);
                QString Date = QDateTime::currentDateTime().toString("dd-MM-yy HH:mm:ss");
                query.prepare("update CUSTOMER set Balance = :NewBalance, MTAmount = :Amount, MTDate = :Date, MTTrNo = :No where AccountNo = :Account ");
                query.bindValue(":Account",CurrentAccount);
                query.bindValue(":NewBalance",NewBalance);
                query.bindValue(":Amount",Amount);
                query.bindValue(":Date",Date);
                query.bindValue(":No",N);
                query.exec();
                QObject::connect(this,SIGNAL(SendAcc(int)),movieticket2,SLOT(ReceiveAcc(int)));
                emit SendAcc(CurrentAccount);
                movieticket2->show();
                this->hide();
            }
        }
        else
        {
            qDebug() << "Movie Ticket Error";
        }
    }
    QSqlDatabase::removeDatabase("db");
}

void MovieTicket1::on_MovieTicketStandardB_clicked()
{
    Type = "Standard";
    int Seats = ui->NoofSeats->value();
    int Amount = 120*Seats;
    QString A = QString::number(Amount);
    ui->MovieTicketAmount->setText(A);
    ui->Currency->setText("₹");
}

void MovieTicket1::on_MovieTicketVIPB_clicked()
{
    Type = "VIP";
    int Seats = ui->NoofSeats->value();
    int Amount = 150*Seats;
    QString A = QString::number(Amount);
    ui->MovieTicketAmount->setText(A);
    ui->Currency->setText("₹");
}

void MovieTicket1::on_NoofSeats_valueChanged(int arg1)
{
    if (Type == "Standard")
    {
        int Seats = arg1;
        Amount = 120*Seats;
    }
    if (Type == "VIP")
    {
        int Seats = arg1;
        Amount = 150*Seats;
    }
    QString A = QString::number(Amount);
    ui->MovieTicketAmount->setText(A);
    ui->Currency->setText("₹");
}

void MovieTicket1::on_LogoutButton_clicked()
{
    MenuBlank *ma = new MenuBlank();
    this->hide();
    ma->showMaximized();
}

void MovieTicket1::on_BackButton_clicked()
{
    Tickets *ma = new Tickets();
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),ma,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    this->hide();
    ma->showMaximized();
}

void MovieTicket1::on_SuggestButton_clicked()
{
    Suggestion *su = new Suggestion();
    su->show();
}
