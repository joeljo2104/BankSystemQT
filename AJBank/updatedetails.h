#ifndef UPDATEDETAILS_H
#define UPDATEDETAILS_H

#include <QMainWindow>

namespace Ui {
class UpdateDetails;
}

class UpdateDetails : public QMainWindow
{
    Q_OBJECT

public:
    explicit UpdateDetails(QWidget *parent = nullptr);
    ~UpdateDetails();

    void showEvent( QShowEvent* event );

private slots:
    void ReceiveAcc(int CurrentAccount);

    void on_SuggestButton_clicked();

    void on_LogoutButton_clicked();

    void on_BackButton_clicked();

    void on_UpdateB_clicked();

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::UpdateDetails *ui;
};

#endif // UPDATEDETAILS_H
