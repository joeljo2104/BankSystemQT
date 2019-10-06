#include "suggestion.h"
#include "ui_suggestion.h"
#include<QTimer>
#include<windows.h>
#include<QtSql>
#include<QSqlQuery>

Suggestion::Suggestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Suggestion)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/button/buttons/Logo.png"));
}

Suggestion::~Suggestion()
{
    delete ui;
}

void Suggestion::on_SuggestButton_clicked()
{
    if(ui->Suggests->text() != "")
    {
        QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/ajbank.db");
        if(!db.open())
        {
            qDebug() << "Can't Connect to DB !";
        }
        else
        {
            QString CSuggest = ui->Suggests->text();
            qDebug() << "DB Connected - Suggestion";
            QSqlQuery query;
            query.prepare("insert into SUGGESTIONS (Suggest) values (:Suggest) ");
            query.bindValue(":Suggest",CSuggest);

            if(!query.exec())
            {
                qDebug() << "Suggestion Error";
            }
        }
        QSqlDatabase::removeDatabase("db");

        ui->ThankYou->setText("Thank You for your Suggestion!");
        QTimer *timer = new QTimer();
        QObject::connect(timer, SIGNAL(timeout()), this, SLOT(hide()));
        timer->start(2000);
    }
    else {
        ui->ThankYou->setText("Please enter your suggestion");
    }
}
