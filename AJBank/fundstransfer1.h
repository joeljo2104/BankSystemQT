#ifndef FUNDSTRANSFER1_H
#define FUNDSTRANSFER1_H

#include <QMainWindow>

#include<fundstransfer2.h>

namespace Ui {
class FundsTransfer1;
}

class FundsTransfer1 : public QMainWindow
{
    Q_OBJECT
    FundsTransfer2 *fundstransfer2 = new FundsTransfer2();

public:
    explicit FundsTransfer1(QWidget *parent = nullptr);
    ~FundsTransfer1();

    void showEvent( QShowEvent* event );

    int RecAccount, RecBalance, RecNewBalance, Balance, Amount;
    QString Pass;

private slots:
    void on_ConfirmFundsTransferB_clicked();

    void on_LogoutButton_clicked();

    void on_BackButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::FundsTransfer1 *ui;
};

#endif // FUNDSTRANSFER1_H
