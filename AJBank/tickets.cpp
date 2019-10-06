#include "tickets.h"
#include "ui_tickets.h"
#include<menublank.h>
#include<suggestion.h>
#include<mainmenu.h>
#include<QBitmap>

Tickets::Tickets(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tickets)
{
    ui->setupUi(this);
}

void Tickets::showEvent( QShowEvent* event )
{

    QMainWindow::showEvent( event );
    setWindowIcon(QIcon(":/button/buttons/Logo.png"));
    QPixmap logout(":/button/buttons/Logout.png");
    ui->LogoutButton->setMask(logout.mask());
    QPixmap suggest(":/button/buttons/Suggest.png");
    ui->SuggestButton->setMask(suggest.mask());
}

Tickets::~Tickets()
{
    delete ui;
}

void Tickets::ReceiveAcc(int CurrentAccount)
{
    ui->AccountNo->setText(QString::number(CurrentAccount));
}

void Tickets::on_MovieTicketB_clicked()
{
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),movieticket,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    movieticket->showMaximized();
    this->hide();
}

void Tickets::on_AirTicketsB_clicked()
{
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),airticket,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    airticket->showMaximized();
    this->hide();
}

void Tickets::on_LogoutButton_clicked()
{
    MenuBlank *ma = new MenuBlank();
    this->hide();
    ma->showMaximized();
}

void Tickets::on_BackButton_clicked()
{
    MainMenu *ma = new MainMenu();
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),ma,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    this->hide();
    ma->showMaximized();
}

void Tickets::on_SuggestButton_clicked()
{
    Suggestion *su = new Suggestion();
    su->show();
}
