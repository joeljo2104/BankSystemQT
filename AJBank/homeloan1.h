#ifndef HOMELOAN1_H
#define HOMELOAN1_H

#include <QMainWindow>

#include<homeloan2.h>

namespace Ui {
class HomeLoan1;
}

class HomeLoan1 : public QMainWindow
{
    Q_OBJECT
    HomeLoan2 *homeloan2 = new HomeLoan2();

public:
    explicit HomeLoan1(QWidget *parent = nullptr);
    ~HomeLoan1();
    int Amount;

    void showEvent( QShowEvent* event );

private slots:
    void on_ConfirmHomeLoanB_clicked();

    void on_HomeLoanTime_valueChanged(double arg1);

    void on_HomeLoanSlider_valueChanged(int value);

    void on_LogoutButton_clicked();

    void on_BackButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::HomeLoan1 *ui;
};

#endif // HOMELOAN1_H
