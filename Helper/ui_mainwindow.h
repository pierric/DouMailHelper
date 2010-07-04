/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Jul 3 10:16:47 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *pg_connect;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *spacer_left;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QPushButton *btn_connect;
    QSpacerItem *spacer_right;
    QWidget *pg_authorize;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *spacer_left_2;
    QPushButton *btn_authorize;
    QSpacerItem *spacer_right_2;
    QWidget *fail;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *btn_reconnect;
    QSpacerItem *horizontalSpacer_2;
    QWidget *list;
    QHBoxLayout *horizontalLayout_6;
    QListWidget *listWidget_2;
    QListWidget *listWidget;
    QWidget *view;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(320, 240);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        pg_connect = new QWidget();
        pg_connect->setObjectName(QString::fromUtf8("pg_connect"));
        horizontalLayout = new QHBoxLayout(pg_connect);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        spacer_left = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacer_left);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(pg_connect);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_3);

        btn_connect = new QPushButton(pg_connect);
        btn_connect->setObjectName(QString::fromUtf8("btn_connect"));

        verticalLayout_2->addWidget(btn_connect);


        horizontalLayout->addLayout(verticalLayout_2);

        spacer_right = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacer_right);

        stackedWidget->addWidget(pg_connect);
        pg_authorize = new QWidget();
        pg_authorize->setObjectName(QString::fromUtf8("pg_authorize"));
        horizontalLayout_3 = new QHBoxLayout(pg_authorize);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        spacer_left_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(spacer_left_2);

        btn_authorize = new QPushButton(pg_authorize);
        btn_authorize->setObjectName(QString::fromUtf8("btn_authorize"));

        horizontalLayout_3->addWidget(btn_authorize);

        spacer_right_2 = new QSpacerItem(95, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(spacer_right_2);

        stackedWidget->addWidget(pg_authorize);
        fail = new QWidget();
        fail->setObjectName(QString::fromUtf8("fail"));
        horizontalLayout_4 = new QHBoxLayout(fail);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(fail);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        btn_reconnect = new QPushButton(fail);
        btn_reconnect->setObjectName(QString::fromUtf8("btn_reconnect"));

        verticalLayout->addWidget(btn_reconnect);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        stackedWidget->addWidget(fail);
        list = new QWidget();
        list->setObjectName(QString::fromUtf8("list"));
        horizontalLayout_6 = new QHBoxLayout(list);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        listWidget_2 = new QListWidget(list);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget_2->sizePolicy().hasHeightForWidth());
        listWidget_2->setSizePolicy(sizePolicy);
        listWidget_2->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_6->addWidget(listWidget_2);

        listWidget = new QListWidget(list);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        horizontalLayout_6->addWidget(listWidget);

        stackedWidget->addWidget(list);
        view = new QWidget();
        view->setObjectName(QString::fromUtf8("view"));
        stackedWidget->addWidget(view);

        horizontalLayout_2->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 320, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);
        menu_2->addAction(action_3);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245\350\261\206\347\223\243", 0, QApplication::UnicodeUTF8));
        action_2->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        action_3->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\347\202\271\345\207\273\344\270\213\351\235\242\346\214\211\351\222\256\345\260\206\345\274\271\345\207\272\346\265\217\350\247\210\345\231\250", 0, QApplication::UnicodeUTF8));
        btn_connect->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245\350\261\206\347\223\243", 0, QApplication::UnicodeUTF8));
        btn_authorize->setText(QApplication::translate("MainWindow", "\345\256\214\346\210\220\351\252\214\350\257\201", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\351\252\214\350\257\201\345\244\261\350\264\245\343\200\202\345\234\250\351\252\214\350\257\201\351\241\265\351\235\242\344\270\255\357\274\214\345\272\224\345\275\223\351\200\211\346\213\251\345\220\214\346\204\217", 0, QApplication::UnicodeUTF8));
        btn_reconnect->setText(QApplication::translate("MainWindow", "\351\207\215\346\226\260\350\277\236\346\216\245\350\261\206\347\223\243", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
