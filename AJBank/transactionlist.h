#ifndef TRANSACTIONLIST_H
#define TRANSACTIONLIST_H

#include <QMainWindow>

namespace Ui {
class TransactionList;
}

class TransactionList : public QMainWindow
{
    Q_OBJECT

public:
    explicit TransactionList(QWidget *parent = nullptr);
    ~TransactionList();

    void showEvent( QShowEvent* event );

private slots:
    void on_LogoutButton_clicked();

    void on_BackButton_clicked();

    void on_SuggestButton_clicked();

    void ReceiveAcc(int CurrentAccount);

signals:
    void SendAcc(int CurrentAccount);

private:
    Ui::TransactionList *ui;
};

#endif // TRANSACTIONLIST_H
