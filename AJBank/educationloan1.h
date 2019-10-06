#ifndef EDUCATIONLOAN1_H
#define EDUCATIONLOAN1_H

#include <QMainWindow>

#include<educationloan2.h>

namespace Ui {
class EducationLoan1;
}

class EducationLoan1 : public QMainWindow
{
    Q_OBJECT
    EducationLoan2 *educationloan2 = new EducationLoan2();

public:
    explicit EducationLoan1(QWidget *parent = nullptr);
    ~EducationLoan1();
    int Amount;

    void showEvent( QShowEvent* event );

private slots:
    void on_ConfirmEducationLoanB_clicked();

    void on_EducationLoanTime_valueChanged(double arg1);

    void on_EducationLoanSlider_valueChanged(int value);

    void on_LogoutButton_clicked();

    void on_BackButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::EducationLoan1 *ui;
};

#endif // EDUCATIONLOAN1_H
