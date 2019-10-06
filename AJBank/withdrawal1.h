#ifndef WITHDRAWAL1_H
#define WITHDRAWAL1_H

#include <QMainWindow>

#include<withdrawal2.h>

namespace Ui {
class Withdrawal1;
}

class Withdrawal1 : public QMainWindow
{
    Q_OBJECT
    Withdrawal2 *withdrawal2 = new Withdrawal2();

public:
    explicit Withdrawal1(QWidget *parent = nullptr);
    ~Withdrawal1();

    void showEvent( QShowEvent* event );

private slots:
    void on_ConfirmWithdrawalB_clicked();

    void on_LogoutButton_clicked();

    void on_BackButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::Withdrawal1 *ui;
};

#endif // WITHDRAWAL1_H
