#include "updatedetails.h"
#include "ui_updatedetails.h"

updatedetails::updatedetails(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::updatedetails)
{
    ui->setupUi(this);
}

updatedetails::~updatedetails()
{
    delete ui;
}
