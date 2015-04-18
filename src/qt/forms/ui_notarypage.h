/********************************************************************************
** Form generated from reading UI file 'notarypage.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTARYPAGE_H
#define UI_NOTARYPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qvalidatedlineedit.h"

QT_BEGIN_NAMESPACE

class Ui_NotaryPage
{
public:
    QWidget *widget;
    QVBoxLayout *notaryLayout;
    QVBoxLayout *sendSectionLayout;
    QLabel *notaryExplanation;
    QHBoxLayout *sendLayout;
    QLineEdit *sendNotaryEntry;
    QPushButton *selectFileButton;
    QPushButton *sendNotaryButton;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *searchSectionLayout;
    QLabel *searchNotaryLabel;
    QHBoxLayout *searchLayout;
    QValidatedLineEdit *searchNotaryEntry;
    QPushButton *searchNotaryButton;
    QTableWidget *tableWidget;

    void setupUi(QWidget *NotaryPage)
    {
        if (NotaryPage->objectName().isEmpty())
            NotaryPage->setObjectName(QString::fromStdString("NotaryPage"));
        NotaryPage->resize(830, 417);
        widget = new QWidget(NotaryPage);
        widget->setObjectName(QString::fromStdString("widget"));
        widget->setGeometry(QRect(10, 20, 801, 381));
        notaryLayout = new QVBoxLayout(widget);
        notaryLayout->setObjectName(QString::fromStdString("notaryLayout"));
        notaryLayout->setContentsMargins(0, 0, 0, 0);
        sendSectionLayout = new QVBoxLayout();
        sendSectionLayout->setObjectName(QString::fromStdString("sendSectionLayout"));
        notaryExplanation = new QLabel(widget);
        notaryExplanation->setObjectName(QString::fromStdString("notaryExplanation"));
        notaryExplanation->setWordWrap(true);

        sendSectionLayout->addWidget(notaryExplanation);

        sendLayout = new QHBoxLayout();
        sendLayout->setObjectName(QString::fromStdString("sendLayout"));
        sendNotaryEntry = new QLineEdit(widget);
        sendNotaryEntry->setObjectName(QString::fromStdString("sendNotaryEntry"));

        sendLayout->addWidget(sendNotaryEntry);

        selectFileButton = new QPushButton(widget);
        selectFileButton->setObjectName(QString::fromStdString("selectFileButton"));

        sendLayout->addWidget(selectFileButton);

        sendNotaryButton = new QPushButton(widget);
        sendNotaryButton->setObjectName(QString::fromStdString("sendNotaryButton"));

        sendLayout->addWidget(sendNotaryButton);


        sendSectionLayout->addLayout(sendLayout);


        notaryLayout->addLayout(sendSectionLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        notaryLayout->addItem(verticalSpacer);

        searchSectionLayout = new QVBoxLayout();
        searchSectionLayout->setObjectName(QString::fromStdString("searchSectionLayout"));
        searchNotaryLabel = new QLabel(widget);
        searchNotaryLabel->setObjectName(QString::fromStdString("searchNotaryLabel"));
        searchNotaryLabel->setWordWrap(true);

        searchSectionLayout->addWidget(searchNotaryLabel);

        searchLayout = new QHBoxLayout();
        searchLayout->setObjectName(QString::fromStdString("searchLayout"));
        searchNotaryEntry = new QValidatedLineEdit(widget);
        searchNotaryEntry->setObjectName(QString::fromStdString("searchNotaryEntry"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(searchNotaryEntry->sizePolicy().hasHeightForWidth());
        searchNotaryEntry->setSizePolicy(sizePolicy);

        searchLayout->addWidget(searchNotaryEntry);

        searchNotaryButton = new QPushButton(widget);
        searchNotaryButton->setObjectName(QString::fromStdString("searchNotaryButton"));

        searchLayout->addWidget(searchNotaryButton);


        searchSectionLayout->addLayout(searchLayout);

        tableWidget = new QTableWidget(widget);
        tableWidget->setObjectName(QString::fromStdString("tableWidget"));
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setHighlightSections(false);

        searchSectionLayout->addWidget(tableWidget);


        notaryLayout->addLayout(searchSectionLayout);

        notaryExplanation->raise();

        retranslateUi(NotaryPage);

        QMetaObject::connectSlotsByName(NotaryPage);
    } // setupUi

    void retranslateUi(QWidget *NotaryPage)
    {
        NotaryPage->setWindowTitle(QApplication::translate("NotaryPage", "Form", 0));
        notaryExplanation->setText(QApplication::translate("NotaryPage", "You can create a unique notary ID from a file on your computer and embed it in the blockchain. You can use this to later prove that you had access to the data at a certain time.", 0));
        sendNotaryEntry->setPlaceholderText(QApplication::translate("NotaryPage", "Enter a file name", 0));
        selectFileButton->setText(QApplication::translate("NotaryPage", "Select File...", 0));
        sendNotaryButton->setText(QApplication::translate("NotaryPage", "Notarize", 0));
        searchNotaryLabel->setText(QApplication::translate("NotaryPage", "Search for transactions containing a notary ID below. A notary ID is 64 hex characters long (like a transaction ID).", 0));
#ifndef QT_NO_TOOLTIP
        searchNotaryEntry->setToolTip(QApplication::translate("NotaryPage", "Notary ID to search for", 0));
#endif // QT_NO_TOOLTIP
        searchNotaryButton->setText(QApplication::translate("NotaryPage", "Search", 0));
    } // retranslateUi

};

namespace Ui {
    class NotaryPage: public Ui_NotaryPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTARYPAGE_H
