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
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(1);

    // Column headers
    QString txHeader = tr("Transaction");
    QString blockHeader = tr("Block");
    QStringList tableHeaders = (QStringList() << txHeader << blockHeader);
    ui->tableWidget->setHorizontalHeaderLabels(tableHeaders);

    // Column widths
    ui->tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(false);

    // Search Validaton
    QRegExp re("[a-fA-F0-9]{64}");
    QRegExpValidator *validator = new QRegExpValidator(re);
    ui->searchNotaryEntry->setValidator(validator);

}

NotaryPage::~NotaryPage()
{
    delete ui;
}

void NotaryPage::setSearchResults(std::vector<std::pair<std::string, int> > txResults)
{
    ui->tableWidget->setRowCount(txResults.size());

    int rowNumber = 0;
    for (std::vector<std::pair<std::string, int> >::iterator iter = txResults.begin(); iter != txResults.end(); ++iter)
    {
        QString hashQ = QString::fromStdString(iter->first);
        QString blockQ = QString::number(iter->second);

        QTableWidgetItem *txItem = new QTableWidgetItem(hashQ);
        QTableWidgetItem *blockItem = new QTableWidgetItem(blockQ);
        txItem->setFlags(txItem->flags() ^ Qt::ItemIsEditable);
        blockItem->setFlags(blockItem->flags() ^ Qt::ItemIsEditable);
        ui->tableWidget->setItem(rowNumber, 0, txItem);
        ui->tableWidget->setItem(rowNumber, 1, blockItem);

        rowNumber++;
    }
    ui->searchNotaryButton->setEnabled(true);
}

void NotaryPage::on_searchNotaryButton_clicked()
{
    bool isValidHash = true;
    if (ui->searchNotaryEntry->text().length() != 64)
    {
        isValidHash = false;
    }
    if (!ui->searchNotaryEntry->hasAcceptableInput())
    {
        isValidHash = false;
    }
    if (!isValidHash)
    {
        ui->searchNotaryEntry->setValid(false);
        return;
    }

    std::string notaryID = ui->searchNotaryEntry->text().toStdString();
    uint256 hash(notaryID);
    ui->searchNotaryButton->setEnabled(false);
    model->searchNotaryTx(hash);
}

void NotaryPage::setModel(WalletModel *model)
{
    this->model = model;
    connect(this->model, SIGNAL(notarySearchComplete(std::vector<std::pair<std::string, int> >)), ui->tableWidget, SLOT(clearContents()));
    connect(this->model, SIGNAL(notarySearchComplete(std::vector<std::pair<std::string, int> >)), this, SLOT(setSearchResults(std::vector<std::pair<std::string, int> >)));
}
