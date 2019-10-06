#ifndef MOVIETICKET1_H
#define MOVIETICKET1_H

#include <QMainWindow>

#include<movieticket2.h>

namespace Ui {
class MovieTicket1;
}

class MovieTicket1 : public QMainWindow
{
    Q_OBJECT
    MovieTicket2 *movieticket2 = new MovieTicket2();
    QString Type = "Standard";
    int Amount;

    void showEvent( QShowEvent* event );

public:
    explicit MovieTicket1(QWidget *parent = nullptr);
    ~MovieTicket1();

private slots:
    void on_ConfirmMovieTicket_clicked();

    void on_MovieTicketStandardB_clicked();

    void on_MovieTicketVIPB_clicked();

    void on_NoofSeats_valueChanged(int arg1);

    void on_LogoutButton_clicked();

    void on_BackButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::MovieTicket1 *ui;
};

#endif // MOVIETICKET1_H
