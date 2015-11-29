#include "clamdb.h"
#include "ui_clamdb.h"
#include "walletmodel.h"
#include "clamourpage.h"
#include "notarypage.h"

ClamDB::ClamDB(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClamDB),
    model(0),
    clamourPage(0),
    notaryPage(0)
{
    ui->setupUi(this);

    notaryPage = new NotaryPage();
    ui->tabWidget->addTab(this->notaryPage, tr("Notary"));

    clamourPage = new ClamourPage();
    connect( clamourPage, SIGNAL(onClamSpeechUpdated()), this, SLOT(on_clamspeech_updated()) );
    ui->tabWidget->addTab(this->clamourPage, tr("CLAMour"));
}

ClamDB::~ClamDB()
{
    delete ui;
}

void ClamDB::setModel(WalletModel *model)
{
    this->model = model;
    this->notaryPage->setModel(model);
}

void ClamDB::on_clamspeech_updated()
{
    emit onClamSpeechUpdated();
}
