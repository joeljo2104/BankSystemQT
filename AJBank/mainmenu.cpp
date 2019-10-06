#include "mainmenu.h"
#include "ui_mainmenu.h"
#include<menublank.h>
#include<suggestion.h>
#include<QBitmap>
MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

void MainMenu::showEvent( QShowEvent* event )
{
    QMainWindow::showEvent( event );
    setWindowIcon(QIcon(":/button/buttons/Logo.png"));
    QPixmap logout(":/button/buttons/Logout.png");
    ui->LogoutButton->setMask(logout.mask());
    QPixmap suggest(":/button/buttons/Suggest.png");
    ui->SuggestButton->setMask(suggest.mask());
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::ReceiveAcc(int CurrentAccount)
{
    ui->AccountNo->setText(QString::number(CurrentAccount));
}

void MainMenu::on_BillPaymentB_clicked()
{
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),billpayment,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    billpayment->showMaximized();
    this->hide();
}

void MainMenu::on_BankServicesB_clicked()
{
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),bankservices,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    bankservices->showMaximized();
    this->hide();
}

void MainMenu::on_TicketsB_clicked()
{
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),tickets,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    tickets->showMaximized();
    this->hide();
}

void MainMenu::on_LoansB_clicked()
{
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),loans,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    loans->showMaximized();
    this->hide();
}

void MainMenu::on_FundsTransferB_clicked()
{
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),fundstransfer,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    fundstransfer->showMaximized();
    this->hide();
}

void MainMenu::on_CurrencyConvertorB_clicked()
{
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),currencyconvert,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    currencyconvert->showMaximized();
    this->hide();
}

void MainMenu::on_QuitB_clicked()
{
    QApplication::quit();
}

void MainMenu::on_LogoutButton_clicked()
{
    MenuBlank *ma = new MenuBlank();
    this->hide();
    ma->showMaximized();

}

void MainMenu::on_SuggestButton_clicked()
{
    Suggestion *su = new Suggestion();
    su->show();
}
