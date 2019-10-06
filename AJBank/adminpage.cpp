#include "adminpage.h"
#include "ui_adminpage.h"
#include<QtSql>
#include<welcomewindow.h>
#include<admin.h>
#include<QBitmap>
AdminPage::AdminPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminPage)
{
    ui->setupUi(this);

    setWindowIcon(QIcon(":/button/buttons/Logo.png"));
    QPixmap logout(":/button/buttons/Logout.png");
    ui->LogoutButton->setMask(logout.mask());

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/ajbank.db");
    db.open();
    QSqlQueryModel * modal = new QSqlQueryModel;
    qDebug() << "DB Connected - Admin";
    QSqlQuery query;
    query.prepare("select * from CUSTOMER");
    query.exec();
    modal->setQuery(query);
    ui->Table->horizontalHeader()->setStyleSheet("color:black; font: 63 14pt \"Montserrat SemiBold\";");
    ui->Table->setModel(modal);
    ui->Table->resizeColumnsToContents();

    QSqlQueryModel * model = new QSqlQueryModel;
    query.prepare("select * from SUGGESTIONS");
    query.exec();
    model->setQuery(query);
    ui->Table_2->horizontalHeader()->setStyleSheet("color:black; font: 63 14pt \"Montserrat SemiBold\";");
    ui->Table_2->setModel(model);
    ui->Table_2->resizeColumnsToContents();
    model->setHeaderData(0,Qt::Horizontal, tr("Suggestions"));

    modal->setHeaderData(0,Qt::Horizontal, tr("AccountNo"));
    modal->setHeaderData(1,Qt::Horizontal, tr("Name"));
    modal->setHeaderData(2,Qt::Horizontal, tr("Gender"));
    modal->setHeaderData(3,Qt::Horizontal, tr("EmailID"));
    modal->setHeaderData(4,Qt::Horizontal, tr("Dob"));
    modal->setHeaderData(5,Qt::Horizontal, tr("PhoneNumber"));
    modal->setHeaderData(6,Qt::Horizontal, tr("Address"));
    modal->setHeaderData(7,Qt::Horizontal, tr("Username"));
    modal->setHeaderData(8,Qt::Horizontal, tr("Password"));
    modal->setHeaderData(9,Qt::Horizontal, tr("Balance"));
    modal->setHeaderData(10,Qt::Horizontal, tr("CarloanApplicationNumber"));
    modal->setHeaderData(11,Qt::Horizontal, tr("CarloanDate"));
    modal->setHeaderData(12,Qt::Horizontal, tr("CarloanAmount"));
    modal->setHeaderData(13,Qt::Horizontal, tr("EducationLoanApplicationNumber"));
    modal->setHeaderData(14,Qt::Horizontal, tr("EducationLoanDate"));
    modal->setHeaderData(15,Qt::Horizontal, tr("EducationLoanAmount"));
    modal->setHeaderData(16,Qt::Horizontal, tr("GoldLoanApplicationNumber"));
    modal->setHeaderData(17,Qt::Horizontal, tr("GoldLoanDate"));
    modal->setHeaderData(18,Qt::Horizontal, tr("GoldLoanAmount"));
    modal->setHeaderData(19,Qt::Horizontal, tr("HomeLoanApplicationNumber"));
    modal->setHeaderData(20,Qt::Horizontal, tr("HomeLoanDate"));
    modal->setHeaderData(21,Qt::Horizontal, tr("HomeLoanAmount"));
    modal->setHeaderData(22,Qt::Horizontal, tr("AirTicketTransactionNumber"));
    modal->setHeaderData(23,Qt::Horizontal, tr("AirTicketDate"));
    modal->setHeaderData(24,Qt::Horizontal, tr("AirTicketAmount"));
    modal->setHeaderData(25,Qt::Horizontal, tr("MovieTicketTransactionNumber"));
    modal->setHeaderData(26,Qt::Horizontal, tr("MovieTicketDate"));
    modal->setHeaderData(27,Qt::Horizontal, tr("MovieTicketAmount"));
    modal->setHeaderData(28,Qt::Horizontal, tr("MobileBillTransactionNumber"));
    modal->setHeaderData(29,Qt::Horizontal, tr("MobileBillDate"));
    modal->setHeaderData(30,Qt::Horizontal, tr("MobileBillAmount"));
    modal->setHeaderData(31,Qt::Horizontal, tr("UtilityBillTransactionNumber"));
    modal->setHeaderData(32,Qt::Horizontal, tr("UtilityBillDate"));
    modal->setHeaderData(33,Qt::Horizontal, tr("UtilityBillAmount"));
    modal->setHeaderData(34,Qt::Horizontal, tr("DepositTransactionNumber"));
    modal->setHeaderData(35,Qt::Horizontal, tr("DepositDate"));
    modal->setHeaderData(36,Qt::Horizontal, tr("DepositAmount"));
    modal->setHeaderData(37,Qt::Horizontal, tr("WithdrawalTransactionNumber"));
    modal->setHeaderData(38,Qt::Horizontal, tr("WithdrawalDate"));
    modal->setHeaderData(39,Qt::Horizontal, tr("WithdrawalAmount"));
    modal->setHeaderData(40,Qt::Horizontal, tr("FundTransferTransactionNumber"));
    modal->setHeaderData(41,Qt::Horizontal, tr("FundTransferDate"));
    modal->setHeaderData(42,Qt::Horizontal, tr("FundTransferAmount"));
    modal->setHeaderData(43,Qt::Horizontal, tr("RecipientAccount"));
}

AdminPage::~AdminPage()
{
    delete ui;
}

void AdminPage::on_LogoutButton_clicked()
{
    WelcomeWindow *we = new WelcomeWindow;
    we->showMaximized();
    this->hide();
}

void AdminPage::on_BackButton_clicked()
{
    Admin *we = new Admin;
    we->showMaximized();
    this->hide();
}
