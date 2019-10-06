#ifndef LOANS_H
#define LOANS_H

#include <QMainWindow>

#include<carloan1.h>
#include<educationloan1.h>
#include<goldloan1.h>
#include<homeloan1.h>

namespace Ui {
class Loans;
}

class Loans : public QMainWindow
{
    Q_OBJECT
    CarLoan1 *carloan = new CarLoan1();
    EducationLoan1 *educationloan = new EducationLoan1();
    GoldLoan1 *goldloan = new GoldLoan1();
    HomeLoan1 *homeloan = new HomeLoan1();

public:
    explicit Loans(QWidget *parent = nullptr);
    ~Loans();

    void showEvent( QShowEvent* event );

private slots:
    void on_CarLoanB_clicked();

    void on_GoldLoanB_clicked();

    void on_HomeLoanB_clicked();

    void on_EducationLoanB_clicked();

    void on_LogoutButton_clicked();

    void on_BackButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::Loans *ui;
};

#endif // LOANS_H
