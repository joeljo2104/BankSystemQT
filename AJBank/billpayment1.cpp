#include "billpayment1.h"
#include "ui_billpayment1.h"
#include<menublank.h>
#include<suggestion.h>
#include<mainmenu.h>
#include<QBitmap>
BillPayment1::BillPayment1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BillPayment1)
{
    ui->setupUi(this);
}

void BillPayment1::showEvent( QShowEvent* event )
{
    QMainWindow::showEvent( event );
    setWindowIcon(QIcon(":/button/buttons/Logo.png"));

    QPixmap logout(":/button/buttons/Logout.png");
    ui->LogoutButton->setMask(logout.mask());
    QPixmap suggest(":/button/buttons/Suggest.png");
    ui->SuggestButton->setMask(suggest.mask());
}

BillPayment1::~BillPayment1()
{
    delete ui;
}

void BillPayment1::ReceiveAcc(int CurrentAccount)
{
    ui->AccountNo->setText(QString::number(CurrentAccount));
}

void BillPayment1::on_MobileBillB_clicked()
{
    mobilebill->showMaximized();
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),mobilebill,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    this->hide();
}

void BillPayment1::on_UtilityBillB_clicked()
{
    utilitybill->showMaximized();
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),utilitybill,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    this->hide();
}

void BillPayment1::on_LogoutButton_clicked()
{
    MenuBlank *ma = new MenuBlank();
    this->hide();
    ma->showMaximized();
}

void BillPayment1::on_BackButton_clicked()
{
    MainMenu *ma = new MainMenu();
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),ma,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    this->hide();
    ma->showMaximized();
}

void BillPayment1::on_SuggestButton_clicked()
{
    Suggestion *su = new Suggestion();
    su->show();
}
