#ifndef DEPOSIT2_H
#define DEPOSIT2_H

#include <QMainWindow>

namespace Ui {
class Deposit2;
}

class Deposit2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Deposit2(QWidget *parent = nullptr);
    ~Deposit2();

    void showEvent( QShowEvent* event );

private slots:
    void on_MainMenuB_clicked();

    void on_LogoutButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::Deposit2 *ui;
};

#endif // DEPOSIT2_H
