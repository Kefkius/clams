#include "clamdb.h"
#include "ui_clamdb.h"
#include "walletmodel.h"
#include "notarypage.h"

ClamDB::ClamDB(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClamDB),
    model(0),
    notaryPage(0)
{
    ui->setupUi(this);

    notaryPage = new NotaryPage();
    ui->tabWidget->addTab(this->notaryPage, tr("Notary"));
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
