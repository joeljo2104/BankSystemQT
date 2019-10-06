#ifndef FUNDSTRANSFER2_H
#define FUNDSTRANSFER2_H

#include <QMainWindow>

namespace Ui {
class FundsTransfer2;
}

class FundsTransfer2 : public QMainWindow
{
    Q_OBJECT
public:
    explicit FundsTransfer2(QWidget *parent = nullptr);
    ~FundsTransfer2();

    void showEvent( QShowEvent* event );

private slots:
    void on_MainMenuB_clicked();

    void on_LogoutButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::FundsTransfer2 *ui;
};

#endif // FUNDSTRANSFER2_H
