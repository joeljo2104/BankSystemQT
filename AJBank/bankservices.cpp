#include "bankservices.h"
#include "ui_bankservices.h"
#include<menublank.h>
#include<mainmenu.h>
#include<suggestion.h>
#include<QBitmap>
#include<updatedetails.h>

BankServices::BankServices(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BankServices)
{
    ui->setupUi(this);
}

void BankServices::showEvent( QShowEvent* event )
{
    QMainWindow::showEvent( event );
    setWindowIcon(QIcon(":/button/buttons/Logo.png"));

    QPixmap logout(":/button/buttons/Logout.png");
    ui->LogoutButton->setMask(logout.mask());
    QPixmap suggest(":/button/buttons/Suggest.png");
    ui->SuggestButton->setMask(suggest.mask());
}

BankServices::~BankServices()
{
    delete ui;
}

void BankServices::ReceiveAcc(int CurrentAccount)
{
    ui->AccountNo->setText(QString::number(CurrentAccount));
}

void BankServices::on_DepositB_clicked()
{
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),deposit,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    deposit->showMaximized();
    this->hide();
}

void BankServices::on_WithdrawB_clicked()
{
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),withdrawal,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    withdrawal->showMaximized();
    this->hide();
}

void BankServices::on_updatedetailsB_clicked()
{
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),transactionlist,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    transactionlist->showMaximized();
    this->hide();
}

void BankServices::on_UpdateB_clicked()
{
    UpdateDetails *update = new UpdateDetails;
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),update,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    update->showMaximized();
    this->hide();
}

void BankServices::on_ViewB_clicked()
{
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),view,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    view->showMaximized();
    this->hide();
}

void BankServices::on_LogoutButton_clicked()
{
    MenuBlank *ma = new MenuBlank();
    this->hide();
    ma->showMaximized();
}

void BankServices::on_BackButton_clicked()
{
    MainMenu *ma = new MainMenu();
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),ma,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    this->hide();
    ma->showMaximized();
}

void BankServices::on_SuggestButton_clicked()
{
    Suggestion *su = new Suggestion();
    su->show();
}
