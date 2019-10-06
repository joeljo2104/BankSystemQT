#ifndef USERNAMEPASSWORD_H
#define USERNAMEPASSWORD_H

#include <QMainWindow>

#include<login.h>

namespace Ui {
class UserNamePassword;
}

class UserNamePassword : public QMainWindow
{
    Q_OBJECT
    Login *login = new Login();

public:
    explicit UserNamePassword(QWidget *parent = nullptr);
    ~UserNamePassword();

    void showEvent( QShowEvent* event );

private slots:
    void on_ProceedB_clicked();

    void on_BackButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::UserNamePassword *ui;
};

#endif // USERNAMEPASSWORD_H
