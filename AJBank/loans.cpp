#include "loans.h"
#include "ui_loans.h"
#include<menublank.h>
#include<suggestion.h>
#include<mainmenu.h>
#include<QBitmap>
Loans::Loans(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Loans)
{
    ui->setupUi(this);
}

void Loans::showEvent( QShowEvent* event )
{
    QMainWindow::showEvent( event );
    setWindowIcon(QIcon(":/button/buttons/Logo.png"));
    QPixmap logout(":/button/buttons/Logout.png");
    ui->LogoutButton->setMask(logout.mask());
    QPixmap suggest(":/button/buttons/Suggest.png");
    ui->SuggestButton->setMask(suggest.mask());
}

Loans::~Loans()
{
    delete ui;
}

void Loans::ReceiveAcc(int CurrentAccount)
{
    ui->AccountNo->setText(QString::number(CurrentAccount));
}

void Loans::on_CarLoanB_clicked()
{
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),carloan,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    carloan->showMaximized();
    this->hide();
}

void Loans::on_GoldLoanB_clicked()
{
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),goldloan,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    goldloan->showMaximized();
    this->hide();
}

void Loans::on_HomeLoanB_clicked()
{
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),homeloan,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    homeloan->showMaximized();
    this->hide();
}

void Loans::on_EducationLoanB_clicked()
{
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),educationloan,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    educationloan->showMaximized();
    this->hide();
}

void Loans::on_LogoutButton_clicked()
{
    MenuBlank *ma = new MenuBlank();
    this->hide();
    ma->showMaximized();
}

void Loans::on_BackButton_clicked()
{
    MainMenu *ma = new MainMenu();
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),ma,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    this->hide();
    ma->showMaximized();
}

void Loans::on_SuggestButton_clicked()
{
    Suggestion *su = new Suggestion();
    su->show();
}
