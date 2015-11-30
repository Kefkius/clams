#ifndef CLAMOURPAGE_H
#define CLAMOURPAGE_H

#include <QWidget>

namespace Ui {
class ClamourPage;
}
class WalletModel;

class ClamourPage : public QWidget
{
    Q_OBJECT

public:
    explicit ClamourPage(QWidget *parent = 0);
    ~ClamourPage();

    void setModel(WalletModel *model);

signals:
    void onClamSpeechUpdated();

public slots:
    void showClamourTxResult(std::string txID, std::string txError);

private slots:
    void on_createPetitionEdit_textChanged();

    void on_createPetitionButton_clicked();

    void on_setVotesButton_clicked();

private:
    Ui::ClamourPage *ui;
    WalletModel *model;

    void saveVotes();
};

#endif // CLAMOURPAGE_H
