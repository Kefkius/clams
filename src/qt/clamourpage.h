#ifndef CLAMOURPAGE_H
#define CLAMOURPAGE_H

#include <QWidget>

namespace Ui {
class ClamourPage;
}

class ClamourPage : public QWidget
{
    Q_OBJECT

public:
    explicit ClamourPage(QWidget *parent = 0);
    ~ClamourPage();

signals:
    void onClamSpeechUpdated();

private slots:
    void on_createPetitionEdit_textChanged();

    void on_createPetitionButton_clicked();

    void on_setVotesButton_clicked();

private:
    Ui::ClamourPage *ui;

    std::string hashPetition(std::string petitionText);

    void saveVotes();
};

#endif // CLAMOURPAGE_H
