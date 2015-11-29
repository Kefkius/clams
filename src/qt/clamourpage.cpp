#include "clamourpage.h"
#include "ui_clamourpage.h"
#include "openssl/sha.h"
#include "clamspeech.h"
#include "util.h"

#include <QDebug>

ClamourPage::ClamourPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClamourPage)
{
    ui->setupUi(this);
}

ClamourPage::~ClamourPage()
{
    delete ui;
}
/*
std::string NotaryPage::hashFile(std::string fileName)
{
    unsigned char hashSha[SHA256_DIGEST_LENGTH];
    FILE* file = fopen(fileName.c_str(), "rb");
    if (file == NULL) {
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
*/

// Create a petition ID.
std::string ClamourPage::hashPetition(std::string petitionText)
{
    unsigned char hashSha[SHA256_DIGEST_LENGTH];
    return "";
}

// Calculate notary ID when text changes.
void ClamourPage::on_createPetitionEdit_textChanged()
{
    std::string petitionText(ui->createPetitionEdit->toPlainText().toStdString());
    if (petitionText.length() == 0)
    {
        ui->createPetitionButton->setEnabled(false);
        return;
    }
    ui->createPetitionButton->setEnabled(true);
    std::string petitionHash(hashPetition(petitionText));
}

// Create a tx that creates a petitition
void ClamourPage::on_createPetitionButton_clicked()
{
    std::string petitionHash(ui->petitionIDEdit->text().toStdString());
    std::string clamSpeech = "create clamour " + petitionHash;

    if (ui->setVoteCheckBox->isChecked())
    {
        // TODO add to stake speech
    }
}

// Set the strDefaultStakeSpeech petition IDs
void ClamourPage::on_setVotesButton_clicked()
{
    saveVotes();
}

void ClamourPage::saveVotes()
{
    clamSpeech.clear();
    QStringList list = ui->votesEdit->toPlainText().replace("\n", ",").replace(" ", ",").split(',', QString::SkipEmptyParts);
    //std::string newSpeech = "clamour";
    std::vector<std::string> newSpeeches(1, "clamour");

    foreach ( const QString &strLine, list )
        if ( !strLine.isEmpty() && strLine.length() == 8 )
        {
            // Create new string if necessary
            if (newSpeeches.back().length() >= 131)
            {
                newSpeeches.push_back("clamour");
            }
            std::string &newSpeech = newSpeeches.back();
            newSpeech = newSpeech + " " + strLine.trimmed().toStdString();
        }

    for (std::vector<std::string>::iterator it = newSpeeches.begin(); it != newSpeeches.end(); ++it)
    {
        clamSpeech.push_back(*it);
    }
    //clamSpeech.push_back(newSpeech);

    // save new speech
    qDebug() << "saving stake petitions";
    if ( !SaveClamSpeech() )
        qDebug() << "CLAMSpeech petitions FAILED to save!";

    emit onClamSpeechUpdated();
}
