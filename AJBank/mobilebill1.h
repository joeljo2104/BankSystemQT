#ifndef MOBILEBILL1_H
#define MOBILEBILL1_H

#include <QMainWindow>

#include<mobilebill2.h>

namespace Ui {
class MobileBill1;
}

class MobileBill1 : public QMainWindow
{
    Q_OBJECT
    MobileBill2 *mobilebill2 = new MobileBill2();

public:
    explicit MobileBill1(QWidget *parent = nullptr);
    ~MobileBill1();

    void showEvent( QShowEvent* event );

private slots:
    void on_ConfirmB_clicked();

    void on_LogoutButton_clicked();

    void on_BackButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::MobileBill1 *ui;
};

#endif // MOBILEBILL1_H
