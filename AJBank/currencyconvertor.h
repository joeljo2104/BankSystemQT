#ifndef CURRENCYCONVERTOR_H
#define CURRENCYCONVERTOR_H

#include <QMainWindow>

namespace Ui {
class CurrencyConvertor;
}

class CurrencyConvertor : public QMainWindow
{
    Q_OBJECT

public:
    explicit CurrencyConvertor(QWidget *parent = nullptr);
    ~CurrencyConvertor();

private slots:
    void on_MainMenuB_clicked();

    void on_ConvertB_clicked();

    void on_LogoutButton_clicked();

    void on_BackButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::CurrencyConvertor *ui;
};

#endif // CURRENCYCONVERTOR_H
