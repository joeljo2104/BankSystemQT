#ifndef CARLOAN2_H
#define CARLOAN2_H

#include <QMainWindow>

namespace Ui {
class CarLoan2;
}

class CarLoan2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit CarLoan2(QWidget *parent = nullptr);
    ~CarLoan2();

    void showEvent( QShowEvent* event );

private slots:
    void on_MainMenuB_clicked();

    void on_LogoutButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::CarLoan2 *ui;
};

#endif // CARLOAN2_H
