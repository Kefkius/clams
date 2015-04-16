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
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

//#include <QtWidgets/QAction>
//#include <QtWidgets/QApplication>
//#include <QtWidgets/QButtonGroup>
//#include <QtWidgets/QHBoxLayout>
//#include <QtWidgets/QHeaderView>
//#include <QtWidgets/QLabel>
//#include <QtWidgets/QLineEdit>
//#include <QtWidgets/QListWidget>
//#include <QtWidgets/QPushButton>
//#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NotaryPage
{
public:
    QListWidget *listWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *searchNotaryLabel;
    QLineEdit *searchNotaryEntry;
    QPushButton *searchNotaryButton;

    // QStringLiteral() is replaced with QString::fromStdString()
    // for compatibility with Qt4

    void setupUi(QWidget *NotaryPage)
    {
        if (NotaryPage->objectName().isEmpty())
            NotaryPage->setObjectName(QString::fromStdString("NotaryPage"));
        NotaryPage->resize(830, 368);
        listWidget = new QListWidget(NotaryPage);
        listWidget->setObjectName(QString::fromStdString("listWidget"));
        listWidget->setGeometry(QRect(10, 250, 811, 111));
        widget = new QWidget(NotaryPage);
        widget->setObjectName(QString::fromStdString("widget"));
        widget->setGeometry(QRect(10, 210, 631, 29));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromStdString("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        searchNotaryLabel = new QLabel(widget);
        searchNotaryLabel->setObjectName(QString::fromStdString("searchNotaryLabel"));

        horizontalLayout->addWidget(searchNotaryLabel);

        searchNotaryEntry = new QLineEdit(widget);
        searchNotaryEntry->setObjectName(QString::fromStdString("searchNotaryEntry"));

        horizontalLayout->addWidget(searchNotaryEntry);

        searchNotaryButton = new QPushButton(widget);
        searchNotaryButton->setObjectName(QString::fromStdString("searchNotaryButton"));

        horizontalLayout->addWidget(searchNotaryButton);

        searchNotaryLabel->raise();
        searchNotaryEntry->raise();
        searchNotaryButton->raise();
        searchNotaryEntry->raise();
        listWidget->raise();
        searchNotaryLabel->raise();
        searchNotaryEntry->raise();
        searchNotaryButton->raise();

        retranslateUi(NotaryPage);

        QMetaObject::connectSlotsByName(NotaryPage);
    } // setupUi

    void retranslateUi(QWidget *NotaryPage)
    {
        NotaryPage->setWindowTitle(QApplication::translate("NotaryPage", "Form", 0));
#ifndef QT_NO_TOOLTIP
        listWidget->setToolTip(QApplication::translate("NotaryPage", "Transactions containing the searched notary ID", 0));
#endif // QT_NO_TOOLTIP
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
