#ifndef GOLDLOAN2_H
#define GOLDLOAN2_H

#include <QMainWindow>

namespace Ui {
class GoldLoan2;
}

class GoldLoan2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit GoldLoan2(QWidget *parent = nullptr);
    ~GoldLoan2();

    void showEvent( QShowEvent* event );

private slots:
    void on_MainMenuB_clicked();

    void on_LogoutButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::GoldLoan2 *ui;
};

#endif // GOLDLOAN2_H
