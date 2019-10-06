#include "transactionlist.h"
#include "ui_transactionlist.h"
#include<menublank.h>
#include<suggestion.h>
#include<bankservices.h>
#include<QBitmap>
#include<QtSql>
TransactionList::TransactionList(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TransactionList)
{
    ui->setupUi(this);
}

void TransactionList::showEvent( QShowEvent* event )
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
        qDebug() << "DB Connected - TransactionList";
        QSqlQuery query;
        query.prepare("select * from CUSTOMER where AccountNo = :Account ");
        query.bindValue(":Account",CurrentAccount);
        query.exec();
        query.first();
        ui->FTTrNo->setText(query.value(40).toString());
        ui->FTDate->setText(query.value(41).toString());
        ui->FTAmount->setText("₹ "+query.value(42).toString());
        ui->FAcc->setText(query.value(43).toString());
        ui->MBTrNo->setText(query.value(28).toString());
        ui->MBDate->setText(query.value(29).toString());
        ui->MBAmount->setText("₹ "+query.value(30).toString());
        ui->UBTrNo->setText(query.value(31).toString());
        ui->UBDate->setText(query.value(32).toString());
        ui->UBAmount->setText("₹ "+query.value(33).toString());
        ui->ATTrNo->setText(query.value(22).toString());
        ui->ATDate->setText(query.value(23).toString());
        ui->ATAmount->setText("₹ "+query.value(24).toString());
        ui->MTTrNo->setText(query.value(25).toString());
        ui->MTDate->setText(query.value(26).toString());
        ui->MTAmount->setText("₹ "+query.value(27).toString());
        ui->DepTrNo->setText(query.value(34).toString());
        ui->DepDate->setText(query.value(35).toString());
        ui->DepAmount->setText("₹ "+query.value(36).toString());
        ui->WitTrNo->setText(query.value(37).toString());
        ui->WitDate->setText(query.value(38).toString());
        ui->WitAmount->setText("₹ "+query.value(39).toString());
        ui->CLAppNo->setText(query.value(10).toString());
        ui->CLDate->setText(query.value(11).toString());
        ui->CLAmount->setText("₹ "+query.value(12).toString());
        ui->ELAppNo->setText(query.value(13).toString());
        ui->ELDate->setText(query.value(14).toString());
        ui->ELAmount->setText("₹ "+query.value(15).toString());
        ui->GLAppNo->setText(query.value(16).toString());
        ui->GLDate->setText(query.value(17).toString());
        ui->GLAmount->setText("₹ "+query.value(18).toString());
        ui->HLAppNo->setText(query.value(19).toString());
        ui->HLDate->setText(query.value(20).toString());
        ui->HLAmount->setText("₹ "+query.value(21).toString());
    }
    QSqlDatabase::removeDatabase("db");
}

TransactionList::~TransactionList()
{
    delete ui;
}

void TransactionList::ReceiveAcc(int CurrentAccount)
{
    ui->AccountNo->setText(QString::number(CurrentAccount));
}

void TransactionList::on_LogoutButton_clicked()
{
    MenuBlank *ma = new MenuBlank();
    this->hide();
    ma->showMaximized();
}

void TransactionList::on_BackButton_clicked()
{
    BankServices *ma = new BankServices();
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),ma,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    this->hide();
    ma->showMaximized();
}

void TransactionList::on_SuggestButton_clicked()
{
    Suggestion *su = new Suggestion();
    su->show();
}
