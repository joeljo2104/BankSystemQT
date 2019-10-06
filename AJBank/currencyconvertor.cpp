#include "currencyconvertor.h"
#include "ui_currencyconvertor.h"
#include<menublank.h>
#include<suggestion.h>
#include<QMessageBox>
#include<mainmenu.h>
#include<QBitmap>
CurrencyConvertor::CurrencyConvertor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CurrencyConvertor)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/button/buttons/Logo.png"));
    QPixmap logout(":/button/buttons/Logout.png");
    ui->LogoutButton->setMask(logout.mask());
    QPixmap suggest(":/button/buttons/Suggest.png");
    ui->SuggestButton->setMask(suggest.mask());

    setTabOrder(ui->InputCurrency,ui->Input1T);
    setTabOrder(ui->Input1T, ui->OutputCurrency);
    setTabOrder(ui->OutputCurrency,ui->ConvertB);
    on_ConvertB_clicked();

    ui->InputCurrency->setItemData( 0, QColor( Qt::white ), Qt::BackgroundRole );
    ui->InputCurrency->setItemData( 1, QColor( Qt::white ), Qt::BackgroundRole );
    ui->InputCurrency->setItemData( 2, QColor( Qt::white ), Qt::BackgroundRole );

    ui->OutputCurrency->setItemData( 0, QColor( Qt::white ), Qt::BackgroundRole );
    ui->OutputCurrency->setItemData( 1, QColor( Qt::white ), Qt::BackgroundRole );
    ui->OutputCurrency->setItemData( 2, QColor( Qt::white ), Qt::BackgroundRole );
}

CurrencyConvertor::~CurrencyConvertor()
{
    delete ui;
}

void CurrencyConvertor::ReceiveAcc(int CurrentAccount)
{
    ui->AccountNo->setText(QString::number(CurrentAccount));
}

void CurrencyConvertor::on_MainMenuB_clicked()
{
    MainMenu *ma = new MainMenu();
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),ma,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    this->hide();
    ma->showMaximized();
}

void CurrencyConvertor::on_ConvertB_clicked()
{
    QString InputA = ui->Input1T->text();
    double OutputAmount;
    QString InputC = ui->InputCurrency->currentText();
    QString OutputC = ui->OutputCurrency->currentText();
    QString Amount;

    if (InputC == "USD" && OutputC == "EUR")
    {   OutputAmount = InputA.toDouble()/1.13;
        Amount = QString::number(OutputAmount,'f',2);
        ui->OutputAmount->setText(Amount);
        ui->Currency->setText("€");
    }
    else if (InputC == "USD" && OutputC == "INR")
    {   OutputAmount = InputA.toDouble()*68.96;
        Amount = QString::number(OutputAmount,'f',2);
        ui->OutputAmount->setText(Amount);
        ui->Currency->setText("₹");
    }
    else if (InputC == "USD" && OutputC == "USD")
    {   OutputAmount = InputA.toDouble()*1;
        Amount = QString::number(OutputAmount,'f',2);
        ui->OutputAmount->setText(Amount);
        ui->Currency->setText("$");
    }
    else if (InputC == "EUR" && OutputC == "INR")
    {   OutputAmount = InputA.toDouble()*78.24;
        Amount = QString::number(OutputAmount,'f',2);
        ui->OutputAmount->setText(Amount);
        ui->Currency->setText("₹");
    }
    else if (InputC == "EUR" && OutputC == "USD")
    {   OutputAmount = InputA.toDouble()*1.13;
        Amount = QString::number(OutputAmount,'f',2);
        ui->OutputAmount->setText(Amount);
        ui->Currency->setText("$");
    }
    else if (InputC == "EUR" && OutputC == "EUR")
    {   OutputAmount = InputA.toDouble()*1;
        Amount = QString::number(OutputAmount,'f',2);
        ui->OutputAmount->setText(Amount);
        ui->Currency->setText("€");
    }
    else if (InputC == "INR" && OutputC == "EUR")
    {   OutputAmount = InputA.toDouble()*78.24;
        Amount = QString::number(OutputAmount,'f',2);
        ui->OutputAmount->setText(Amount);
        ui->Currency->setText("€");
    }
    else if (InputC == "INR" && OutputC == "USD")
    {   OutputAmount = InputA.toDouble()/68.96;
        Amount = QString::number(OutputAmount,'f',2);
        ui->OutputAmount->setText(Amount);
        ui->Currency->setText("$");
    }
    else if (InputC == "INR" && OutputC == "INR")
    {   OutputAmount = InputA.toDouble()*1;
        Amount = QString::number(OutputAmount,'f',2);
        ui->OutputAmount->setText(Amount);
        ui->Currency->setText("₹");
    }
}

void CurrencyConvertor::on_LogoutButton_clicked()
{
    MenuBlank *ma = new MenuBlank();
    this->hide();
    ma->showMaximized();
}

void CurrencyConvertor::on_BackButton_clicked()
{
    MainMenu *ma = new MainMenu();
    int CurrentAccount = ui->AccountNo->text().toInt();
    QObject::connect(this,SIGNAL(SendAcc(int)),ma,SLOT(ReceiveAcc(int)));
    emit SendAcc(CurrentAccount);
    this->hide();
    ma->showMaximized();
}

void CurrencyConvertor::on_SuggestButton_clicked()
{
    Suggestion *su = new Suggestion();
    su->show();
}
