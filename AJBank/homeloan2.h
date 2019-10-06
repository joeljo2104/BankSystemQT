#ifndef HOMELOAN2_H
#define HOMELOAN2_H

#include <QMainWindow>

namespace Ui {
class HomeLoan2;
}

class HomeLoan2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomeLoan2(QWidget *parent = nullptr);
    ~HomeLoan2();

    void showEvent( QShowEvent* event );

private slots:
    void on_MainMenuB_clicked();

    void on_LogoutButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::HomeLoan2 *ui;
};

#endif // HOMELOAN2_H
