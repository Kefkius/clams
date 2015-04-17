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
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <qvalidatedlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_NotaryPage
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *searchNotaryLabel;
    QValidatedLineEdit *searchNotaryEntry;
    QPushButton *searchNotaryButton;
    QTableWidget *tableWidget;

    void setupUi(QWidget *NotaryPage)
    {
        if (NotaryPage->objectName().isEmpty())
            NotaryPage->setObjectName(QString::fromStdString("NotaryPage"));
        NotaryPage->resize(830, 368);
        widget = new QWidget(NotaryPage);
        widget->setObjectName(QString::fromStdString("widget"));
        widget->setGeometry(QRect(10, 190, 801, 161));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromStdString("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromStdString("horizontalLayout"));
        searchNotaryLabel = new QLabel(widget);
        searchNotaryLabel->setObjectName(QString::fromStdString("searchNotaryLabel"));

        horizontalLayout->addWidget(searchNotaryLabel);

        searchNotaryEntry = new QValidatedLineEdit(widget);
        searchNotaryEntry->setObjectName(QString::fromStdString("searchNotaryEntry"));

        horizontalLayout->addWidget(searchNotaryEntry);

        searchNotaryButton = new QPushButton(widget);
        searchNotaryButton->setObjectName(QString::fromStdString("searchNotaryButton"));

        horizontalLayout->addWidget(searchNotaryButton);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(widget);
        tableWidget->setObjectName(QString::fromStdString("tableWidget"));
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setHighlightSections(false);

        verticalLayout->addWidget(tableWidget);


        retranslateUi(NotaryPage);

        QMetaObject::connectSlotsByName(NotaryPage);
    } // setupUi

    void retranslateUi(QWidget *NotaryPage)
    {
        NotaryPage->setWindowTitle(QApplication::translate("NotaryPage", "Form", 0));
        searchNotaryLabel->setText(QApplication::translate("NotaryPage", "Search for a Notary ID:", 0));
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
