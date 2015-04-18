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

    void setNotaryFileName(QString fileName);

public slots:
    void setSearchResults(std::vector<std::pair<std::string, int> > txResults);
    void showNotaryTxResult(std::string txError);

private slots:
    void on_searchNotaryButton_clicked();

    void on_selectFileButton_clicked();

    void on_sendNotaryButton_clicked();

private:
    Ui::NotaryPage *ui;
    WalletModel *model;

    std::string hashFile(std::string fileName);
};

#endif // NOTARYPAGE_H
