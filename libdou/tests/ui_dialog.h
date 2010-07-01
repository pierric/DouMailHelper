/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Thu Jul 1 19:30:22 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Main
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *phase1_btn;
    QPushButton *phase2_btn;
    QPushButton *mail_btn;
    QLabel *status;
    QPlainTextEdit *xml;

    void setupUi(QDialog *Main)
    {
        if (Main->objectName().isEmpty())
            Main->setObjectName(QString::fromUtf8("Main"));
        Main->resize(426, 340);
        layoutWidget = new QWidget(Main);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 77, 83));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        phase1_btn = new QPushButton(layoutWidget);
        phase1_btn->setObjectName(QString::fromUtf8("phase1_btn"));

        verticalLayout->addWidget(phase1_btn);

        phase2_btn = new QPushButton(layoutWidget);
        phase2_btn->setObjectName(QString::fromUtf8("phase2_btn"));

        verticalLayout->addWidget(phase2_btn);

        mail_btn = new QPushButton(layoutWidget);
        mail_btn->setObjectName(QString::fromUtf8("mail_btn"));

        verticalLayout->addWidget(mail_btn);

        status = new QLabel(Main);
        status->setObjectName(QString::fromUtf8("status"));
        status->setGeometry(QRect(30, 120, 54, 12));
        status->setAlignment(Qt::AlignCenter);
        xml = new QPlainTextEdit(Main);
        xml->setObjectName(QString::fromUtf8("xml"));
        xml->setGeometry(QRect(120, 10, 281, 321));

        retranslateUi(Main);

        QMetaObject::connectSlotsByName(Main);
    } // setupUi

    void retranslateUi(QDialog *Main)
    {
        Main->setWindowTitle(QApplication::translate("Main", "Dialog", 0, QApplication::UnicodeUTF8));
        phase1_btn->setText(QApplication::translate("Main", "1st", 0, QApplication::UnicodeUTF8));
        phase2_btn->setText(QApplication::translate("Main", "2nd", 0, QApplication::UnicodeUTF8));
        mail_btn->setText(QApplication::translate("Main", "Get Mails", 0, QApplication::UnicodeUTF8));
        status->setText(QApplication::translate("Main", "status", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Main: public Ui_Main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
