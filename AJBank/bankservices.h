#ifndef BANKSERVICES_H
#define BANKSERVICES_H

#include <QMainWindow>

#include<deposit1.h>
#include<withdrawal1.h>
#include<transactionlist.h>
#include<viewdetails.h>

namespace Ui {
class BankServices;
}

class BankServices : public QMainWindow
{
    Q_OBJECT
    Deposit1 *deposit = new Deposit1();
    Withdrawal1 *withdrawal = new Withdrawal1();
    TransactionList *transactionlist = new TransactionList();
    ViewDetails *view = new ViewDetails();

public:
    explicit BankServices(QWidget *parent = nullptr);
    ~BankServices();

    void showEvent( QShowEvent* event );

private slots:
    void on_DepositB_clicked();

    void on_WithdrawB_clicked();

    void on_updatedetailsB_clicked();

    void on_UpdateB_clicked();

    void on_ViewB_clicked();

    void on_LogoutButton_clicked();

    void on_BackButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::BankServices *ui;
};

#endif // BANKSERVICES_H
