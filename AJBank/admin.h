#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>

namespace Ui {
class Admin;
}

class Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

    void showEvent( QShowEvent* event );

private slots:
    void on_AdminLoginB_clicked();

    void on_BackButton_clicked();

    void on_SuggestButton_clicked();

private:
    Ui::Admin *ui;
};

#endif // ADMIN_H
