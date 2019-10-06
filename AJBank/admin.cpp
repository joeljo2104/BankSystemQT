#include "admin.h"
#include "ui_admin.h"
#include<menublank.h>
#include<suggestion.h>
#include<adminpage.h>
Admin::Admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
}

void Admin::showEvent( QShowEvent* event )
{
    QMainWindow::showEvent( event );
    setWindowIcon(QIcon(":/button/buttons/Logo.png"));
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_AdminLoginB_clicked()
{
    QString admin = ui->AdminPasswordT->text();
    if (admin != "admin")
    {
        ui->ErrorMessage->setText("Invalid Password!");
    }
    else {
        ui->ErrorMessage->setText("<font color='white'>Welcome Admin!</font>");
        AdminPage *ma = new AdminPage();
        this->hide();
        ma->showMaximized();
    }
}

void Admin::on_BackButton_clicked()
{
    MenuBlank *ma = new MenuBlank();
    this->hide();
    ma->showMaximized();
}

void Admin::on_SuggestButton_clicked()
{
    Suggestion *su = new Suggestion();
    su->show();
}
