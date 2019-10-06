#ifndef GOLDLOAN1_H
#define GOLDLOAN1_H

#include <QMainWindow>

#include<goldloan2.h>

namespace Ui {
class GoldLoan1;
}

class GoldLoan1 : public QMainWindow
{
    Q_OBJECT
    GoldLoan2 *goldloan2 = new GoldLoan2();

public:
    explicit GoldLoan1(QWidget *parent = nullptr);
    ~GoldLoan1();
    int Amount;

    void showEvent( QShowEvent* event );

private slots:
    void on_ConfirmGoldLoanB_clicked();

    void on_GoldLoanTime_valueChanged(double arg1);

    void on_GoldLoanSlider_valueChanged(int value);

    void on_LogoutButton_clicked();

    void on_BackButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::GoldLoan1 *ui;
};

#endif // GOLDLOAN1_H
