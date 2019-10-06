#ifndef EDUCATIONLOAN2_H
#define EDUCATIONLOAN2_H

#include <QMainWindow>

namespace Ui {
class EducationLoan2;
}

class EducationLoan2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit EducationLoan2(QWidget *parent = nullptr);
    ~EducationLoan2();

    void showEvent( QShowEvent* event );

private slots:
    void on_MainMenuB_clicked();

    void on_LogoutButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::EducationLoan2 *ui;
};

#endif // EDUCATIONLOAN2_H
