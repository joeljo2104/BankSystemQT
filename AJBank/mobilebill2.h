#ifndef MOBILEBILL2_H
#define MOBILEBILL2_H

#include <QMainWindow>

namespace Ui {
class MobileBill2;
}

class MobileBill2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MobileBill2(QWidget *parent = nullptr);
    ~MobileBill2();

    void showEvent( QShowEvent* event );

private slots:
    void on_MainMenuB_clicked();

    void on_LogoutButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::MobileBill2 *ui;
};

#endif // MOBILEBILL2_H
