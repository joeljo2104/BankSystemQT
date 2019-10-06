#ifndef CARLOAN1_H
#define CARLOAN1_H

#include <QMainWindow>

#include<carloan2.h>

namespace Ui {
class CarLoan1;
}

class CarLoan1 : public QMainWindow
{
    Q_OBJECT
    CarLoan2 *carloan2 = new CarLoan2;

public:
    explicit CarLoan1(QWidget *parent = nullptr);
    ~CarLoan1();
    int Amount;

    void showEvent( QShowEvent* event );

private slots:
    void on_CarLoanConfirmB_clicked();

    void on_CarLoanTime_valueChanged(double arg1);

    void on_CarLoanSlider_valueChanged(int value);

    void on_LogoutButton_clicked();

    void on_BackButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::CarLoan1 *ui;
};

#endif // CARLOAN1_H
