#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QMainWindow>

#include<newcustomer.h>
#include<login.h>
#include<admin.h>

namespace Ui {
class WelcomeWindow;
}

class WelcomeWindow : public QMainWindow
{
    Q_OBJECT
    NewCustomer *newcustomer = new NewCustomer();
    Login *login = new Login();
    Admin *admin = new Admin();

public:
    explicit WelcomeWindow(QWidget *parent = nullptr);
    ~WelcomeWindow();

private slots:
    void on_NewCustomerB_clicked();

    void on_ExistingCustomerB_clicked();

    void on_AdminB_clicked();

private:
    Ui::WelcomeWindow *ui;
};

#endif // WELCOMEWINDOW_H
