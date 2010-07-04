#include "helpermainwindow.h"
#include "ui_mainwindow.h"

#include <QState>
#include <QUrl>
#include <QDesktopServices>
#include <QDebug>

HelperMainWindow::HelperMainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow),
        st_connect(new QState),
        st_authorize(new QState),
        st_failure(new QState),
        st_list(new QState),
        st_view(new QState),
        dou_service(NULL)
{
    ui->setupUi(this);

    st_connect->setObjectName("st_connect");
    st_connect->assignProperty(ui->stackedWidget, "currentIndex", 0);
    st_authorize->setObjectName("st_authorize");
    st_authorize->assignProperty(ui->stackedWidget, "currentIndex", 1);
    st_failure->setObjectName("st_failure");
    st_failure->assignProperty(ui->stackedWidget, "currentIndex", 2);
    st_list->setObjectName("st_list");
    st_list->assignProperty(ui->stackedWidget, "currentIndex", 3);
    st_view->setObjectName("st_view");
    st_view->assignProperty(ui->stackedWidget, "currentIndex", 4);
    state_machine.addState(st_connect);
    state_machine.addState(st_authorize);
    state_machine.addState(st_failure);
    state_machine.addState(st_list);
    state_machine.addState(st_view);
    state_machine.setInitialState(st_connect);
    state_machine.start();

    st_connect->addTransition(ui->btn_connect, SIGNAL(clicked()), st_authorize);
    st_authorize->addTransition(this, SIGNAL(authorizeSucceeded()), st_list);
    st_authorize->addTransition(this, SIGNAL(authorizeFailed()), st_failure);
    st_failure->addTransition(ui->btn_reconnect, SIGNAL(clicked()), st_authorize);

    connect(ui->btn_connect, SIGNAL(clicked()), this, SLOT(connectToDouService()));
    connect(ui->btn_authorize, SIGNAL(clicked()), this, SLOT(authorizeDouService()));
    connect(ui->btn_reconnect, SIGNAL(clicked()), this, SLOT(connectToDouService()));
}

HelperMainWindow::~HelperMainWindow()
{
    delete ui;
}

void HelperMainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch(e->type())
    {
    case QEvent::LanguageChange : ui->retranslateUi(this); break;
    default: break;
    }
}

void HelperMainWindow::connectToDouService()
{
    if(dou_service) free(dou_service);
    dou_service = initialize("0fab16a3feb4853d2f0143ebfc1d8fb7", "fa4d182f572cd229");
    char uri[100];
    get_authorize_uri(dou_service, uri);
    QDesktopServices::openUrl(QUrl(uri));
}

void HelperMainWindow::authorizeDouService()
{
    if(!authorize(dou_service))
        emit authorizeFailed();
    else
        emit authorizeSucceeded();
}
