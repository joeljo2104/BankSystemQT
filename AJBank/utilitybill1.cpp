#include "utilitybill1.h"
#include "ui_utilitybill1.h"
#include<menublank.h>
#include<suggestion.h>
#include<billpayment1.h>
#include<QBitmap>
#include<QSqlQuery>
#include<QtSql>
UtilityBill1::UtilityBill1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UtilityBill1)
{
    ui->setupUi(this);
}

void UtilityBill1::showEvent( QShowEvent* event )
{
    QMainWindow::showEvent( event );

    ui->ServiceProvider->setItemData( 4, QColor( Qt::white ), Qt::BackgroundRole );
    ui->ServiceProvider->setItemData( 4, QColor( Qt::white ), Qt::BackgroundRole );
    ui->ServiceProvider->setItemData( 4, QColor( Qt::white ), Qt::BackgroundRole );

    setWindowIcon(QIcon(":/button/buttons/Logo.png"));
    QPixmap logout(":/button/buttons/Logout.png");
    ui->LogoutButton->setMask(logout.mask());
    QPixmap suggest(":/button/buttons/Suggest.png");
    ui->SuggestButton->setMask(suggest.mask());
}

UtilityBill1::~UtilityBill1()
{
    delete ui;
}

void UtilityBill1::ReceiveAcc(int CurrentAccount)
{
    ui->AccountNo->setText(QString::number(CurrentAccount));
}

void UtilityBill1::on_ConfirmUtilityBillB_clicked()
{
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
        qDebug() << "DB Connected - UtilityBill1 ";
        QSqlQuery query;
        query.prepare("select Balance from CUSTOMER where AccountNo = :Account ");
        query.bindValue(":Account",CurrentAccount);
        int Amount = ui->UtilityBillT->text().toInt();
        if(query.exec())
        {
            query.first();
            int Balance = query.value(0).toInt();
            if (Amount>Balance)
            {
                ui->ErrorMessage->setText("<font color=red>Insufficient Funds</font>");
            }
            else if (ui->UtilityBillT->text().isEmpty() || ui->UtilityBillT->text().toInt() == 0){
                ui->ErrorMessage->setText("<font color=red>Enter Valid Amount</font>");
            }
            else {
                int NewBalance = Balance - Amount;
                QRandomGenerator *gen1 = QRandomGenerator::global();
                int N = gen1->bounded(10000,99999);
                QString Date = QDateTime::currentDateTime().toString("dd-MM-yy HH:mm:ss");
                query.prepare("update CUSTOMER set Balance = :NewBalance, UBAmount = :Amount, UBDate = :Date, UBTrNo = :No where AccountNo = :Account ");
                query.bindValue(":Account",CurrentAccount);
                query.bindValue(":NewBalance",NewBalance);
                query.bindValue(":Amount",Amount);
                query.bindValue(":Date",Date);
                query.bindValue(":No",N);
                query.exec();
                QObject::connect(this,SIGNAL(SendAcc(int)),utilitybill2,SLOT(ReceiveAcc(int)));
                emit SendAcc(CurrentAccount);
                utilitybill2->show();
                this->hide();
            }
        }
        else
        {
            qDebug() << "Utility Bill Error";
        }
    }
    QSqlDatabase::removeDatabase("db");

    QSqlDatabase::removeDatabase("db");
}

void UtilityBill1::on_LogoutButton_clicked()
{
    MenuBlank *ma = new MenuBlank();
    this->hide();
    ma->showMaximized();
}

void UtilityBill1::on_BackButton_clicked()
{
    BillPayment1 *ma = new BillPayment1();
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),ma,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    this->hide();
    ma->showMaximized();
}

void UtilityBill1::on_SuggestButton_clicked()
{
    Suggestion *su = new Suggestion();
    su->show();
}
