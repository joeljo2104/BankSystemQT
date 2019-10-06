#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include<QSql>
#include<QSqlDatabase>
#include<QDebug>
#include<mainmenu.h>
#include<menublank.h>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT
    MainMenu *mainm = new MainMenu();
    QString User,Pass;

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

    void showEvent( QShowEvent* event );

private slots:
    void on_LoginB_clicked();

    void on_BackButton_clicked();

    void on_SuggestButton_clicked();

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::Login *ui;
    QSqlDatabase db;
};

#endif // LOGIN_H
