#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>

#include<bankservices.h>
#include<billpayment1.h>
#include<tickets.h>
#include<loans.h>
#include<fundstransfer1.h>
#include<currencyconvertor.h>

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT
    BankServices *bankservices = new BankServices();
    BillPayment1 *billpayment = new BillPayment1();
    Tickets *tickets = new Tickets();
    Loans *loans = new Loans();
    FundsTransfer1 *fundstransfer = new FundsTransfer1();
    CurrencyConvertor *currencyconvert = new CurrencyConvertor();

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

    void showEvent( QShowEvent* event );

private slots:
    void on_BillPaymentB_clicked();

    void on_BankServicesB_clicked();

    void on_TicketsB_clicked();

    void on_LoansB_clicked();

    void on_FundsTransferB_clicked();

    void on_CurrencyConvertorB_clicked();

    void on_QuitB_clicked();

    void on_LogoutButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
