#include "notarypage.h"
#include "ui_notarypage.h"
#include "uint256.h"
#include "walletmodel.h"
#include "util.h"
#include "openssl/sha.h"

#include <QFileDialog>
#include <QMessageBox>

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

void NotaryPage::showNotaryTxResult(std::string txError)
{
    if (txError == "") {
        QMessageBox::information(this, tr("Send Notary Tx"),
            tr("Notary transaction sent successfully."),
            QMessageBox::Ok, QMessageBox::Ok);
    } else {
        QMessageBox::warning(this, tr("Send Notary Tx"),
            tr(txError.c_str()),
            QMessageBox::Ok, QMessageBox::Ok);
    }
}

void NotaryPage::setNotaryFileName(QString fileName)
{
    ui->sendNotaryEntry->setText(fileName);
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
    connect(this->model, SIGNAL(notaryTxSent(std::string)), this, SLOT(showNotaryTxResult(std::string)));
}

void NotaryPage::on_selectFileButton_clicked()
{
    QString fileName;
    QFileDialog dlg(this);
    dlg.setFileMode(QFileDialog::ExistingFile);

    if (dlg.exec())
    {
        fileName = dlg.selectedFiles()[0];
        setNotaryFileName(fileName);
    }
}

void NotaryPage::on_sendNotaryButton_clicked()
{
    std::string fileName = ui->sendNotaryEntry->text().toStdString();
    std::string fileHash = hashFile(fileName);
    uint256 hash;
    hash.SetHex(fileHash);

    // Make sure wallet is unlocked
    WalletModel::UnlockContext ctx(model->requestUnlock());
    if (!ctx.isValid()) {
        return;
    }

    model->sendNotaryTx(hash);
}

std::string NotaryPage::hashFile(std::string fileName)
{
    unsigned char hashSha[SHA256_DIGEST_LENGTH];
    FILE* file = fopen(fileName.c_str(), "rb");
    if (file == NULL) {
        // TODO tell the user
        return "";
    }

    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    char buffer[4096];
    int bytesRead = 0;
    while ((bytesRead = fread(buffer, 1, 4096, file)) != 0) {
        SHA256_Update(&sha256, buffer, bytesRead);
    }
    SHA256_Final(hashSha, &sha256);
    std::string notaryID = HashToString(hashSha, SHA256_DIGEST_LENGTH);
    LogPrintf("NotaryPage::hashFile: hash of file: %s\n", notaryID);

    fclose(file);

    return notaryID;
}
