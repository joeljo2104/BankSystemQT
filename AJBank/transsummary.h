#ifndef updatedetails_H
#define updatedetails_H

#include <QMainWindow>

namespace Ui {
class updatedetails;
}

class updatedetails : public QMainWindow
{
    Q_OBJECT

public:
    explicit updatedetails(QWidget *parent = nullptr);
    ~updatedetails();

private:
    Ui::updatedetails *ui;
};

#endif // updatedetails_H
