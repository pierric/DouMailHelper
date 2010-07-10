/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Jul 10 22:33:41 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *act_connect;
    QAction *act_exit;
    QAction *act_about;
    QAction *act_disconnect;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *pg_connect;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *spacer_left;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_3;
    QPushButton *btn_connect;
    QSpacerItem *verticalSpacer;
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
    QSpacerItem *verticalSpacer_4;
    QLabel *label;
    QPushButton *btn_reconnect;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_2;
    QWidget *list;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btn_inbox;
    QCheckBox *chk_unread;
    QPushButton *btn_outbox;
    QFrame *line;
    QPushButton *btn_export;
    QPushButton *btn_back;
    QSpacerItem *verticalSpacer_2;
    QStackedWidget *stw_list_or_view;
    QWidget *pg_list;
    QHBoxLayout *horizontalLayout_7;
    QTreeView *tre_mail;
    QWidget *pg_view;
    QHBoxLayout *horizontalLayout_8;
    QPlainTextEdit *pte_view;
    QWidget *view;
    QHBoxLayout *horizontalLayout_5;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(640, 480);
        act_connect = new QAction(MainWindow);
        act_connect->setObjectName(QString::fromUtf8("act_connect"));
        act_exit = new QAction(MainWindow);
        act_exit->setObjectName(QString::fromUtf8("act_exit"));
        act_about = new QAction(MainWindow);
        act_about->setObjectName(QString::fromUtf8("act_about"));
        act_disconnect = new QAction(MainWindow);
        act_disconnect->setObjectName(QString::fromUtf8("act_disconnect"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        pg_connect = new QWidget();
        pg_connect->setObjectName(QString::fromUtf8("pg_connect"));
        horizontalLayout = new QHBoxLayout(pg_connect);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        spacer_left = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacer_left);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        label_3 = new QLabel(pg_connect);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_3);

        btn_connect = new QPushButton(pg_connect);
        btn_connect->setObjectName(QString::fromUtf8("btn_connect"));

        verticalLayout_2->addWidget(btn_connect);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        spacer_right = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacer_right);

        stackedWidget->addWidget(pg_connect);
        pg_authorize = new QWidget();
        pg_authorize->setObjectName(QString::fromUtf8("pg_authorize"));
        horizontalLayout_3 = new QHBoxLayout(pg_authorize);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
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
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        label = new QLabel(fail);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        btn_reconnect = new QPushButton(fail);
        btn_reconnect->setObjectName(QString::fromUtf8("btn_reconnect"));

        verticalLayout->addWidget(btn_reconnect);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        stackedWidget->addWidget(fail);
        list = new QWidget();
        list->setObjectName(QString::fromUtf8("list"));
        horizontalLayout_6 = new QHBoxLayout(list);
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        btn_inbox = new QPushButton(list);
        btn_inbox->setObjectName(QString::fromUtf8("btn_inbox"));

        verticalLayout_3->addWidget(btn_inbox);

        chk_unread = new QCheckBox(list);
        chk_unread->setObjectName(QString::fromUtf8("chk_unread"));
        chk_unread->setChecked(false);
        chk_unread->setTristate(false);

        verticalLayout_3->addWidget(chk_unread);

        btn_outbox = new QPushButton(list);
        btn_outbox->setObjectName(QString::fromUtf8("btn_outbox"));

        verticalLayout_3->addWidget(btn_outbox);

        line = new QFrame(list);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        btn_export = new QPushButton(list);
        btn_export->setObjectName(QString::fromUtf8("btn_export"));
        btn_export->setEnabled(false);
        btn_export->setMaximumSize(QSize(100, 16777215));

        verticalLayout_3->addWidget(btn_export);

        btn_back = new QPushButton(list);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));

        verticalLayout_3->addWidget(btn_back);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout_6->addLayout(verticalLayout_3);

        stw_list_or_view = new QStackedWidget(list);
        stw_list_or_view->setObjectName(QString::fromUtf8("stw_list_or_view"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stw_list_or_view->sizePolicy().hasHeightForWidth());
        stw_list_or_view->setSizePolicy(sizePolicy);
        pg_list = new QWidget();
        pg_list->setObjectName(QString::fromUtf8("pg_list"));
        sizePolicy.setHeightForWidth(pg_list->sizePolicy().hasHeightForWidth());
        pg_list->setSizePolicy(sizePolicy);
        horizontalLayout_7 = new QHBoxLayout(pg_list);
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        tre_mail = new QTreeView(pg_list);
        tre_mail->setObjectName(QString::fromUtf8("tre_mail"));
        tre_mail->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tre_mail->setAlternatingRowColors(true);
        tre_mail->setRootIsDecorated(false);
        tre_mail->setItemsExpandable(false);
        tre_mail->setSortingEnabled(false);
        tre_mail->setAnimated(false);
        tre_mail->setExpandsOnDoubleClick(false);
        tre_mail->header()->setProperty("showSortIndicator", QVariant(false));
        tre_mail->header()->setStretchLastSection(false);

        horizontalLayout_7->addWidget(tre_mail);

        stw_list_or_view->addWidget(pg_list);
        pg_view = new QWidget();
        pg_view->setObjectName(QString::fromUtf8("pg_view"));
        horizontalLayout_8 = new QHBoxLayout(pg_view);
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        pte_view = new QPlainTextEdit(pg_view);
        pte_view->setObjectName(QString::fromUtf8("pte_view"));

        horizontalLayout_8->addWidget(pte_view);

        stw_list_or_view->addWidget(pg_view);

        horizontalLayout_6->addWidget(stw_list_or_view);

        stackedWidget->addWidget(list);
        view = new QWidget();
        view->setObjectName(QString::fromUtf8("view"));
        horizontalLayout_5 = new QHBoxLayout(view);
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        stackedWidget->addWidget(view);

        horizontalLayout_2->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 23));
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
        menu->addAction(act_connect);
        menu->addAction(act_disconnect);
        menu->addAction(act_exit);
        menu_2->addAction(act_about);

        retranslateUi(MainWindow);
        QObject::connect(act_exit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\350\261\206\351\202\256", 0, QApplication::UnicodeUTF8));
        act_connect->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245\350\261\206\347\223\243", 0, QApplication::UnicodeUTF8));
        act_connect->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", 0, QApplication::UnicodeUTF8));
        act_exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        act_exit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        act_about->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", 0, QApplication::UnicodeUTF8));
        act_disconnect->setText(QApplication::translate("MainWindow", "\346\226\255\345\274\200\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\347\202\271\345\207\273\344\270\213\351\235\242\346\214\211\351\222\256\345\260\206\345\274\271\345\207\272\346\265\217\350\247\210\345\231\250", 0, QApplication::UnicodeUTF8));
        btn_connect->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245\350\261\206\347\223\243", 0, QApplication::UnicodeUTF8));
        btn_authorize->setText(QApplication::translate("MainWindow", "\345\256\214\346\210\220\351\252\214\350\257\201", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\351\252\214\350\257\201\345\244\261\350\264\245\343\200\202\345\234\250\351\252\214\350\257\201\351\241\265\351\235\242\344\270\255\357\274\214\345\272\224\345\275\223\351\200\211\346\213\251\345\220\214\346\204\217", 0, QApplication::UnicodeUTF8));
        btn_reconnect->setText(QApplication::translate("MainWindow", "\351\207\215\346\226\260\350\277\236\346\216\245\350\261\206\347\223\243", 0, QApplication::UnicodeUTF8));
        btn_inbox->setText(QApplication::translate("MainWindow", "\346\224\266\344\273\266\347\256\261", 0, QApplication::UnicodeUTF8));
        chk_unread->setText(QApplication::translate("MainWindow", "\346\234\252\350\257\273\351\202\256\344\273\266", 0, QApplication::UnicodeUTF8));
        btn_outbox->setText(QApplication::translate("MainWindow", "\345\217\221\344\273\266\347\256\261", 0, QApplication::UnicodeUTF8));
        btn_export->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272", 0, QApplication::UnicodeUTF8));
        btn_back->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        statusbar->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
