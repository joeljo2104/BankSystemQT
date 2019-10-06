#include "menublank.h"
#include "ui_menublank.h"
#include<welcomewindow.h>
#include<QBitmap>
#include<QTimer>
MenuBlank::MenuBlank(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuBlank)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/button/buttons/Logo.png"));

    WelcomeWindow *we = new WelcomeWindow;
    this->close();
    QTimer::singleShot(200,we,SLOT(showMaximized()));
    QTimer::singleShot(200,this,SLOT(hide()));
}

MenuBlank::~MenuBlank()
{
    delete ui;
}

void MenuBlank::ReceiveAcc(int CurrentAccount)
{
    ui->AccountNo->setText(QString::number(CurrentAccount));
}
