#ifndef MOVIETICKET2_H
#define MOVIETICKET2_H

#include <QMainWindow>

namespace Ui {
class MovieTicket2;
}

class MovieTicket2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MovieTicket2(QWidget *parent = nullptr);
    ~MovieTicket2();

    void showEvent( QShowEvent* event );

private slots:
    void on_MainMenuB_clicked();

    void on_LogoutButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::MovieTicket2 *ui;
};

#endif // MOVIETICKET2_H
