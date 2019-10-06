#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include<QSplashScreen>
#include<QTimer>
WelcomeWindow::WelcomeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/button/buttons/Logo.png"));
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_NewCustomerB_clicked()
{
    newcustomer->showMaximized();
    this->hide();
}

void WelcomeWindow::on_ExistingCustomerB_clicked()
{
    login->showMaximized();
    this->hide();
}

void WelcomeWindow::on_AdminB_clicked()
{
    admin->showMaximized();
    this->hide();
}
