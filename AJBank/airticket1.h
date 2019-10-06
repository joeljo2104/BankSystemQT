#ifndef AIRTICKET1_H
#define AIRTICKET1_H

#include <QMainWindow>
#include<QPushButton>
#include<airticket2.h>

namespace Ui {
class AirTicket1;
}

class AirTicket1 : public QMainWindow
{
    Q_OBJECT
    AirTicket2 *airticket2 = new AirTicket2();
    QString Type = "Economy";


public:
    explicit AirTicket1(QWidget *parent = nullptr);
    ~AirTicket1();
    int Amount;

    void showEvent( QShowEvent* event );


private slots:
    void on_ConfirmAirTicketB_clicked();

    void on_FirstClassB_clicked();

    void on_BusinessClassB_clicked();

    void on_EconomyClassB_clicked();

    void on_NoofSeats_valueChanged(int arg1);

    void on_LogoutButton_clicked();

    void on_BackButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::AirTicket1 *ui;

};

#endif // AIRTICKET1_H
