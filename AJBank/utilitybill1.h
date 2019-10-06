#ifndef UTILITYBILL1_H
#define UTILITYBILL1_H

#include <QMainWindow>

#include<utilitybill2.h>

namespace Ui {
class UtilityBill1;
}

class UtilityBill1 : public QMainWindow
{
    Q_OBJECT
    UtilityBill2 *utilitybill2 = new UtilityBill2();

public:
    explicit UtilityBill1(QWidget *parent = nullptr);
    ~UtilityBill1();

    void showEvent( QShowEvent* event );

private slots:
    void on_ConfirmUtilityBillB_clicked();

    void on_LogoutButton_clicked();

    void on_BackButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::UtilityBill1 *ui;
};

#endif // UTILITYBILL1_H
