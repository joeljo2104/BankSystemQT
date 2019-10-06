#ifndef VIEWDETAILS_H
#define VIEWDETAILS_H

#include <QMainWindow>

namespace Ui {
class ViewDetails;
}

class ViewDetails : public QMainWindow
{
    Q_OBJECT

public:
    explicit ViewDetails(QWidget *parent = nullptr);
    ~ViewDetails();

    void showEvent( QShowEvent* event );

private slots:
    void on_MainMenuB_clicked();

    void on_LogoutButton_clicked();

    void on_BackButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::ViewDetails *ui;
};

#endif // VIEWDETAILS_H
