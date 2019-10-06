#ifndef BILLPAYMENT1_H
#define BILLPAYMENT1_H

#include <QMainWindow>

#include<mobilebill1.h>
#include<utilitybill1.h>

namespace Ui {
class BillPayment1;
}

class BillPayment1 : public QMainWindow
{
    Q_OBJECT
    MobileBill1 *mobilebill = new MobileBill1();
    UtilityBill1 *utilitybill = new UtilityBill1();

public:
    explicit BillPayment1(QWidget *parent = nullptr);
    ~BillPayment1();

    void showEvent( QShowEvent* event );

private slots:
    void on_MobileBillB_clicked();

    void on_UtilityBillB_clicked();

    void on_LogoutButton_clicked();

    void on_BackButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::BillPayment1 *ui;
};

#endif // BILLPAYMENT1_H
