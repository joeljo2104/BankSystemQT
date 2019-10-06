#ifndef UTILITYBILL2_H
#define UTILITYBILL2_H

#include <QMainWindow>

namespace Ui {
class UtilityBill2;
}

class UtilityBill2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit UtilityBill2(QWidget *parent = nullptr);
    ~UtilityBill2();

    void showEvent( QShowEvent* event );

private slots:
    void on_MainMenuB_clicked();

    void on_LogoutButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::UtilityBill2 *ui;
};

#endif // UTILITYBILL2_H
