#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QMainWindow>

namespace Ui {
class AdminPage;
}

class AdminPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminPage(QWidget *parent = nullptr);
    ~AdminPage();

private slots:
    void on_LogoutButton_clicked();

    void on_BackButton_clicked();

private:
    Ui::AdminPage *ui;
};

#endif // ADMINPAGE_H
