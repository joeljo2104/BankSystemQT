#ifndef DEPOSIT1_H
#define DEPOSIT1_H

#include <QMainWindow>

#include<deposit2.h>

namespace Ui {
class Deposit1;
}

class Deposit1 : public QMainWindow
{
    Q_OBJECT
    Deposit2 *deposit2 = new Deposit2();

public:
    explicit Deposit1(QWidget *parent = nullptr);
    ~Deposit1();

    void showEvent( QShowEvent* event );

private slots:
    void on_ConfirmDepositB_clicked();

    void on_LogoutButton_clicked();

    void on_BackButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::Deposit1 *ui;
};

#endif // DEPOSIT1_H
