#ifndef TICKETS_H
#define TICKETS_H

#include <QMainWindow>

#include<airticket1.h>
#include<movieticket1.h>

namespace Ui {
class Tickets;
}

class Tickets : public QMainWindow
{
    Q_OBJECT
    AirTicket1 *airticket = new AirTicket1();
    MovieTicket1 *movieticket = new MovieTicket1();

public:
    explicit Tickets(QWidget *parent = nullptr);
    ~Tickets();

    void showEvent( QShowEvent* event );

private slots:
    void on_MovieTicketB_clicked();

    void on_AirTicketsB_clicked();

    void on_LogoutButton_clicked();

    void on_BackButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::Tickets *ui;
};

#endif // TICKETS_H
