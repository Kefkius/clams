#ifndef NOTARYPAGE_H
#define NOTARYPAGE_H

//#include "uint256.h"

#include <QWidget>

namespace Ui {
    class NotaryPage;
}
class WalletModel;

class NotaryPage : public QWidget
{
    Q_OBJECT

public:
    explicit NotaryPage(QWidget *parent = 0);
    ~NotaryPage();

    void setModel(WalletModel *model);

//signals:
//    void searchCompleted(std::vector<uint256> vTxs);

public slots:
    void setSearchResults(std::vector<std::string> txResults);

private slots:
    void on_searchNotaryButton_clicked();

private:
    Ui::NotaryPage *ui;
    WalletModel *model;
};

#endif // NOTARYPAGE_H
