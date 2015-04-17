#include "notarypage.h"
#include "ui_notarypage.h"
#include "uint256.h"
#include "walletmodel.h"

NotaryPage::NotaryPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotaryPage),
    model(0)
{
    ui->setupUi(this);
//    connect(ui->searchNotaryButton, SIGNAL(clicked()), this, SLOT(on_searchNotaryButton_clicked()));

    //connect(this, SIGNAL(searchCompleted(std::vector<uint256>)), this, SLOT(setSearchResults(std::vector<uint256>)));
//    connect(model, SIGNAL(notarySearchComplete(std::string)), this, SLOT(setSearchResults(std::string)));
//    connect(ui->searchNotaryButton, SIGNAL(clicked()), ui->listWidget, SLOT(clear()));
}

NotaryPage::~NotaryPage()
{
    delete ui;
}

void NotaryPage::setSearchResults(std::vector<std::pair<std::string, int> > txResults)
{
/*    QStringList txs;
    for (std::vector<std::string>::iterator it = vTxs.begin(); it != v.end(); ++it)
    {
        //std::string hashStr = it->GetHex();
        QString hashQ = QString::fromStdString(hashStr);
        txs.append(hashQ);
    }
*/
    QStringList txs;
    for (std::vector<std::pair<std::string, int> >::iterator iter = txResults.begin(); iter != txResults.end(); ++iter)
    {
        QString hashQ = QString::fromStdString(iter->first);
        txs.append(hashQ);
    }
    ui->searchNotaryButton->setEnabled(true);
//    QString txQ = QString::fromStdString(resultTx);
//    ui->listWidget->addItem(txQ);
    ui->listWidget->addItems(txs);
}

void NotaryPage::on_searchNotaryButton_clicked()
{
    std::string notaryID = ui->searchNotaryEntry->text().toStdString();
    uint256 hash = uint256(notaryID);
    //std::vector<unsigned char> vSearch(notaryID.begin(), notaryID.end());
    //uint256 hash(vSearch);
    //std::vector<uint256> vTxs(1);
    ui->searchNotaryButton->setEnabled(false);
    model->searchNotaryTx(hash);

    //emit searchCompleted(vTxs);
}

void NotaryPage::setModel(WalletModel *model)
{
    this->model = model;
    connect(this->model, SIGNAL(notarySearchComplete(std::vector<std::pair<std::string, int> >)), ui->listWidget, SLOT(clear()));
    connect(this->model, SIGNAL(notarySearchComplete(std::vector<std::pair<std::string, int> >)), this, SLOT(setSearchResults(std::vector<std::pair<std::string, int> >)));
}
