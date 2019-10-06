#ifndef WITHDRAWAL2_H
#define WITHDRAWAL2_H

#include <QMainWindow>

namespace Ui {
class Withdrawal2;
}

class Withdrawal2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Withdrawal2(QWidget *parent = nullptr);
    ~Withdrawal2();

    void showEvent( QShowEvent* event );

private slots:
    void on_MainMenuB_clicked();

    void on_LogoutButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::Withdrawal2 *ui;
};

#endif // WITHDRAWAL2_H
