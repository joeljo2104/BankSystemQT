#ifndef NEWCUSTOMER_H
#define NEWCUSTOMER_H

#include <QMainWindow>

#include<usernamepassword.h>

namespace Ui {
class NewCustomer;
}

class NewCustomer : public QMainWindow
{
    Q_OBJECT
    UserNamePassword *username = new UserNamePassword();

public:
    explicit NewCustomer(QWidget *parent = nullptr);
    ~NewCustomer();

    void showEvent( QShowEvent* event );

private slots:
    void on_CreateUsernameB_clicked();

    void on_BackButton_clicked();

    void on_SuggestButton_clicked();

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::NewCustomer *ui;
};

#endif // NEWCUSTOMER_H
