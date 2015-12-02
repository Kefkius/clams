#include "clamourpage.h"
#include "ui_clamourpage.h"
#include "openssl/sha.h"
#include "clamspeech.h"
#include "main.h"
#include "util.h"
#include "walletmodel.h"

#include <QDebug>
#include <QMessageBox>

ClamourPage::ClamourPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClamourPage),
    model(0)
{
    ui->setupUi(this);
    ui->createPetitionButton->setEnabled(false);
    ui->setVoteCheckBox->setEnabled(false);
}

ClamourPage::~ClamourPage()
{
    delete ui;
}

// Calculate notary ID when text changes.
void ClamourPage::on_createPetitionEdit_textChanged()
{
    std::string petitionText(ui->createPetitionEdit->toPlainText().toStdString());
    if (petitionText.length() == 0)
    {
        ui->createPetitionButton->setEnabled(false);
        ui->setVoteCheckBox->setEnabled(false);
        return;
    }
    ui->createPetitionButton->setEnabled(true);
    ui->setVoteCheckBox->setEnabled(true);
    std::string petitionHash(StrToSHA256(petitionText));
    ui->petitionIDEdit->setText(QString::fromStdString(petitionHash));
}

// Create a tx that creates a petitition
void ClamourPage::on_createPetitionButton_clicked()
{
    std::string petitionHash(ui->petitionIDEdit->text().toStdString());

    WalletModel::UnlockContext ctx(model->requestUnlock());
    if (!ctx.isValid()) {
        return;
    }

    model->sendClamourTx(petitionHash);

    if (ui->setVoteCheckBox->isChecked())
    {
        strDefaultStakeSpeech = "clamour " + petitionHash.substr(0, 8);
        clamourClamSpeech.push_back(strDefaultStakeSpeech);
        qDebug() << "saving clamour petitions";
        if ( !SaveClamourClamSpeech() )
            qDebug() << "Clamour CLAMSpeech petitions FAILED to save!";
        loadVotes();
    }
}

void ClamourPage::on_setVotesButton_clicked()
{
    saveVotes();
}

void ClamourPage::loadVotes()
{
    QStringList list;
    for (std::vector<std::string>::iterator it = clamourClamSpeech.begin(); it != clamourClamSpeech.end(); ++it)
    {
        list.append(QString::fromStdString(*it));
    }
    ui->votesEdit->setPlainText(list.join("\n"));
}

void ClamourPage::saveVotes()
{
    QStringList list = ui->votesEdit->toPlainText().replace("\n", ",").replace(" ", ",").split(',', QString::SkipEmptyParts);
    std::vector<std::string> newSpeeches(1, "clamour");

    foreach ( const QString &strLine, list )
        if ( !strLine.isEmpty() && strLine.length() >= 8 && IsHex(strLine.toStdString()) )
        {
            // Create new string if necessary
            if (newSpeeches.back().length() > MAX_TX_COMMENT_LEN - 9)
            {
                newSpeeches.push_back("clamour");
            }
            std::string &newSpeech = newSpeeches.back();
            newSpeech = newSpeech + " " + strLine.trimmed().left(8).toStdString();
        }

    clamourClamSpeech.clear();
    for (std::vector<std::string>::iterator it = newSpeeches.begin(); it != newSpeeches.end(); ++it)
    {
        clamourClamSpeech.push_back(*it);
    }

    // save new speech
    qDebug() << "saving clamour petitions";
    if ( !SaveClamourClamSpeech() )
        qDebug() << "Clamour CLAMSpeech petitions FAILED to save!";

    loadVotes();
}

void ClamourPage::showClamourTxResult(std::string txID, std::string txError)
{
    if (txError == "") {
        std::string txSentMsg = "Clamour petition created successfully: " + txID;
        QMessageBox::information(this, tr("Create Clamour Petition"),
            tr(txSentMsg.c_str()),
            QMessageBox::Ok, QMessageBox::Ok);
        ui->createPetitionButton->setEnabled(false);
        ui->setVoteCheckBox->setEnabled(false);
    } else {
        QMessageBox::warning(this, tr("Create Clamour Petition"),
            tr(txError.c_str()),
            QMessageBox::Ok, QMessageBox::Ok);
    }
}

void ClamourPage::setModel(WalletModel *model)
{
    this->model = model;
    connect(this->model, SIGNAL(clamourTxSent(std::string, std::string)), this, SLOT(showClamourTxResult(std::string, std::string)));
    loadVotes();
}
