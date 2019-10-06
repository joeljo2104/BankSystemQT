#ifndef AIRTICKET2_H
#define AIRTICKET2_H

#include <QMainWindow>

namespace Ui {
class AirTicket2;
}

class AirTicket2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit AirTicket2(QWidget *parent = nullptr);
    ~AirTicket2();

    void showEvent( QShowEvent* event );

private slots:
    void on_MainMenuB_clicked();

    void on_LogoutButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::AirTicket2 *ui;
};

#endif // AIRTICKET2_H
