#ifndef MENUBLANK_H
#define MENUBLANK_H

#include <QMainWindow>

namespace Ui {
extern int CurrentAccount;
class MenuBlank;
}

class MenuBlank : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuBlank(QWidget *parent = nullptr);
    ~MenuBlank();

private slots:
    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::MenuBlank *ui;
};
#endif // MENUBLANK_H
