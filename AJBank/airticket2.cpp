#include "airticket2.h"
#include "ui_airticket2.h"
#include<QRandomGenerator>
#include<QBitmap>
#include<mainmenu.h>
#include<suggestion.h>
#include<menublank.h>
#include"airticket1.h"
#include<QSqlDatabase>
#include<QtSql>
AirTicket2::AirTicket2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AirTicket2)
{
    ui->setupUi(this);

}

void AirTicket2::showEvent( QShowEvent* event )
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
        qDebug() << "DB Connected - AirTicket2";
        QSqlQuery query;
        query.prepare("select ATTrNo from CUSTOMER where AccountNo = :Account ");
        query.bindValue(":Account",CurrentAccount);
        query.exec();
        query.first();
        ui->TransactionNo->setText(query.value(0).toString());
    }
}

AirTicket2::~AirTicket2()
{
    delete ui;
}

void AirTicket2::ReceiveAcc(int CurrentAccount)
{
    ui->AccountNo->setText(QString::number(CurrentAccount));
}

void AirTicket2::on_MainMenuB_clicked()
{
    MainMenu *ma = new MainMenu();
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),ma,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    this->hide();
    ma->showMaximized();
}

void AirTicket2::on_LogoutButton_clicked()
{
    MenuBlank *ma = new MenuBlank();
    this->hide();
    ma->showMaximized();
}

void AirTicket2::on_SuggestButton_clicked()
{
    Suggestion *su = new Suggestion();
    su->show();
}
