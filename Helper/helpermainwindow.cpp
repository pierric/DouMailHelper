#include "helpermainwindow.h"
#include "ui_mainwindow.h"
#include "objects.h"

#include <QState>
#include <QUrl>
#include <QDesktopServices>
#include <QStandardItemModel>
#include <QDateTime>
#include <QSettings>
#include <QTextCodec>
#include <QtXml>
#include <QDebug>

#define SERVICE_API "0fab16a3feb4853d2f0143ebfc1d8fb7"
#define SERVICE_KEY "fa4d182f572cd229"

HelperMainWindow::HelperMainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow),
        st_connect(new QState),
        st_authorize(new QState),
        st_failure(new QState),
        st_list(new QState),
        dou_service(NULL)
{
    ui->setupUi(this);


    connect(ui->btn_connect,   SIGNAL(clicked()),   this, SLOT(connectToDouService()));
    connect(ui->btn_authorize, SIGNAL(clicked()),   this, SLOT(authorizeDouService()));
    connect(ui->btn_reconnect, SIGNAL(clicked()),   this, SLOT(connectToDouService()));
    connect(ui->act_connect,   SIGNAL(triggered()), this, SLOT(connectToDouService()));
    connect(ui->act_disconnect, SIGNAL(triggered()), this, SLOT(disconnectFromDouService()));
    connect(ui->btn_inbox, SIGNAL(clicked()), this, SLOT(listInboxMails()));
    connect(ui->chk_unread, SIGNAL(stateChanged(int)), this, SLOT(listInboxMails()));
    connect(ui->btn_outbox, SIGNAL(clicked()), this, SLOT(listOutboxMails()));
    connect(ui->tre_mail, SIGNAL(clicked(QModelIndex)), this, SLOT(showMail(QModelIndex)));

    mdl_inbox = new QStandardItemModel(0, 3, this);
    //mdl_inbox->setHeaderData(0, Qt::Horizontal, trUtf8("S"));
    mdl_inbox->setHeaderData(0, Qt::Horizontal, trUtf8("来自"));
    mdl_inbox->setHeaderData(1, Qt::Horizontal, trUtf8("标题"));
    mdl_inbox->setHeaderData(2, Qt::Horizontal, trUtf8("发信时间"));
    mdl_outbox = new QStandardItemModel(0, 2, this);
    //mdl_outbox->setHeaderData(0, Qt::Horizontal, trUtf8("S"));
    mdl_outbox->setHeaderData(0, Qt::Horizontal, trUtf8("标题"));
    mdl_outbox->setHeaderData(1, Qt::Horizontal, trUtf8("发信时间"));
    ui->tre_mail->setModel(mdl_inbox);

    connect_status = new QLabel(this);
    connect_status->setMargin(3);
    connect_status->setOpenExternalLinks(true);
    ui->statusbar->addPermanentWidget(connect_status);

    ui->btn_back->setVisible(false);

    // setting up ui state machine
    st_connect->setObjectName("st_connect");
    st_connect->assignProperty(ui->stackedWidget, "currentIndex", 0);
    st_connect->assignProperty(ui->act_connect, "enabled", true);
    st_connect->assignProperty(ui->act_disconnect, "enabled", false);
    st_connect->assignProperty(connect_status, "text", "Unconnected");

    st_authorize->setObjectName("st_authorize");
    st_authorize->assignProperty(ui->stackedWidget, "currentIndex", 1);
    st_authorize->assignProperty(ui->act_connect, "enabled", false);
    st_authorize->assignProperty(ui->act_disconnect, "enabled", false);
    st_authorize->assignProperty(connect_status, "text", "");

    st_failure->setObjectName("st_failure");
    st_failure->assignProperty(ui->stackedWidget, "currentIndex", 2);
    st_failure->assignProperty(ui->act_connect, "enabled", true);
    st_failure->assignProperty(ui->act_disconnect, "enabled", false);
    st_failure->assignProperty(connect_status, "text", "Fail to connect to douban");

    st_list->setObjectName("st_list");
    st_list->assignProperty(ui->stackedWidget, "currentIndex", 3);
    st_list->assignProperty(ui->act_connect, "enabled", false);
    st_list->assignProperty(ui->act_disconnect, "enabled", true);

    st_connect->addTransition(this, SIGNAL(connectSucceeded()), st_authorize);
    st_authorize->addTransition(this, SIGNAL(authorizeSucceeded()), st_list);
    st_authorize->addTransition(this, SIGNAL(authorizeFailed()), st_failure);
    st_failure->addTransition(ui->btn_reconnect, SIGNAL(clicked()), st_authorize);
    st_list->addTransition(ui->act_disconnect, SIGNAL(triggered()), st_connect);

    state_machine.addState(st_connect);
    state_machine.addState(st_authorize);
    state_machine.addState(st_failure);
    state_machine.addState(st_list);

    QSettings settings("nonrecursive", "DouMailHelper");
    if(settings.contains("auth/accessKey") &&
       settings.contains("auth/accessSec") &&
       settings.contains("auth/uid"))
    {
        dou_service = initialize2(SERVICE_API, SERVICE_KEY,
                                  settings.value("auth/accessKey").toString().toAscii().data(),
                                  settings.value("auth/accessSec").toString().toAscii().data(),
                                  settings.value("auth/uid").toInt(NULL));
        state_machine.setInitialState(st_list);
        whoAmI();
        listInboxMails();
    }
    else
    {
        state_machine.setInitialState(st_connect);
    }
    state_machine.start();
}

HelperMainWindow::~HelperMainWindow()
{
    delete ui;
    if(dou_service)
    {
        QSettings settings("nonrecursive", "DouMailHelper");
        const char *key = get_access_key(dou_service);
        const char *sec = get_access_secret(dou_service);
        int uid = get_user_id(dou_service);
        if( key && sec && uid > 0)
        {
            settings.setValue("auth/accessKey", key);
            settings.setValue("auth/accessSec", sec);
            settings.setValue("auth/uid", uid);
        }
        cleanup(dou_service);
    }
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
    if(dou_service)
    {
        cleanup(dou_service);
        free(dou_service);
        dou_service = NULL;
    }
    dou_service = initialize(SERVICE_API, SERVICE_KEY);
    if(dou_service)
    {
        char uri[100];
        get_authorize_uri(dou_service, uri);
        if(!QDesktopServices::openUrl(QUrl(uri)))
            qDebug() << "Fail to open browser. Visit: " << uri;
        emit connectSucceeded();
    }
    else
    {
        qDebug() << "Error: " << last_error();
    }
}

void HelperMainWindow::authorizeDouService()
{
    if(!authorize(dou_service))
        emit authorizeFailed();
    else
    {
        whoAmI();
        emit authorizeSucceeded();
    }
}

void HelperMainWindow::disconnectFromDouService()
{
    QSettings settings("nonrecursive", "DouMailHelper");
    settings.remove("auth/accessKey");
    settings.remove("auth/accessSec");
    settings.remove("auth/uid");
    if(dou_service)
    {
        cleanup(dou_service);
        free(dou_service);
        dou_service = NULL;
    }
}

void HelperMainWindow::listInboxMails()
{
    ui->tre_mail->setModel(mdl_inbox);
    //ui->tre_mail->header()->setResizeMode(0, QHeaderView::ResizeToContents);
    ui->tre_mail->header()->setResizeMode(0, QHeaderView::ResizeToContents);
    ui->tre_mail->header()->setResizeMode(1, QHeaderView::Stretch);
    ui->tre_mail->header()->setResizeMode(2, QHeaderView::ResizeToContents);

    mdl_inbox->removeRows(0, mdl_inbox->rowCount());
    mails.clear();
    MailParser parser;
    int sindex = 0;
    do
    {
        char *xml;
        bool unread = ui->chk_unread->isChecked();
        if(unread)
            xml = get_unread(dou_service, sindex+1, 50);
        else
            xml = get_inbox (dou_service, sindex+1, 50);
        QList<Mail> ms = parser.parse(QTextCodec::codecForName("UTF-8")->toUnicode(xml));
        if(ms.empty())
        {
            free(xml);
            break;
        }
        mdl_inbox->insertRows(sindex, ms.size());
        for(int i=0;i<ms.size();i++)
        {
            //mdl_inbox->setData(mdl_inbox->index(sindex+i,0), false);
            mdl_inbox->setData(mdl_inbox->index(sindex+i,0), ms[i].getAuthor().getName());
            mdl_inbox->setData(mdl_inbox->index(sindex+i,1), ms[i].getTitle());
            mdl_inbox->setData(mdl_inbox->index(sindex+i,2),
                               ms[i].getPublishedTime().toString("yy-MM-dd hh:mm AP"));
        }
       free(xml);
       mails.append(ms);
       sindex+=50;
   }while(true);
}

void HelperMainWindow::listOutboxMails()
{
    ui->tre_mail->setModel(mdl_outbox);
    //ui->tre_mail->header()->setResizeMode(0, QHeaderView::ResizeToContents);
    ui->tre_mail->header()->setResizeMode(0, QHeaderView::Stretch);
    ui->tre_mail->header()->setResizeMode(1, QHeaderView::ResizeToContents);

    MailParser parser;
    mdl_outbox->removeRows(0, mdl_inbox->rowCount());
    mails.clear();
    int sindex = 0;
    do
    {
        char *xml = get_outbox(dou_service, sindex+1, 50);
        QList<Mail> ms = parser.parse(QTextCodec::codecForName("UTF-8")->toUnicode(xml));
        if(ms.empty() )
        {
            free(xml);
            break;
        }
        mdl_outbox->insertRows(sindex, ms.size());
        for(int i=0;i<ms.size();i++)
        {
            //mdl_outbox->setData(mdl_outbox->index(sindex+i,0), false);
            mdl_outbox->setData(mdl_outbox->index(sindex+i,0), ms[i].getTitle());
            mdl_outbox->setData(mdl_outbox->index(sindex+i,1),
                                ms[i].getPublishedTime().toString("yy-MM-dd hh:mm AP"));
        }
        free(xml);
        mails.append(ms);
        sindex+=50;
    }while(true);
}

void HelperMainWindow::whoAmI()
{
    QString ci = "Connected as <B>unknown</B>";
    int uid = get_user_id(dou_service);
    char *info = get_user_info(dou_service, uid);
    if(info)
    {
        QDomDocument doc;
        QString xml = QTextCodec::codecForName("UTF-8")->toUnicode(info);
        if(doc.setContent(xml, (QString *)NULL, (int *)NULL, (int *)NULL))
        {
            QString url;
            QString name;
            name = doc.documentElement().namedItem("db:uid").firstChild().toText().data();
            QDomNodeList links = doc.elementsByTagName("link");
            for(int i=0; i<links.size(); i++)
            {
                if( links.item(i).attributes().contains("rel") &&
                    links.item(i).attributes().namedItem("rel").toAttr().value() == "alternate" )
                {
                    url = links.item(i).attributes().namedItem("href").toAttr().value();
                }
            }
            ci = QString("Connected as <a href=\"%1\">%2</a>").arg(url).arg(name);
        }
        free(info);
    }
    st_list->assignProperty(connect_status, "text", ci);
}

void HelperMainWindow::on_btn_export_clicked()
{
    if(mails.empty()) return;
    QFile cf(":/resource/inbox.css");
    cf.open(QFile::ReadOnly);
    QFile tf(":/resource/template.html");
    tf.open(QFile::ReadOnly);
    QString tem = tf.readAll();
    QFile out("export.html");
    out.open(QFile::WriteOnly | QFile::Truncate);
    QTextStream stream(&out);
    stream << "<html>" << endl << trUtf8("<head><title>导出</title>") << endl;
    stream << "<style type=\"text/css\">" << QString(cf.readAll()) << "</style>" << endl;
    stream << "</head>";
    stream << trUtf8("<body><div id=\"collection\"> <div id = \"ct\">收件箱(共%1封)</div>").arg(mails.size());
    for(int i=0;i<mails.size();i++)
    {
        Mail &m = mails[i];
        if(i==0)
        {
            if(!m.fetch(dou_service))
                qDebug() << "fails to fetch: " << m.getId();
            qDebug() << m.getContent();
        }
        stream << tem.arg(i==0?"style=\"border-top: solid 1px black;\"":"")
                     .arg(m.getAuthor().getName())
                     .arg(m.getTitle())
                     .arg(m.getPublishedTime().toString("yy-MM-dd hh:mm AP"))
                     .arg("...") << endl;
    }
    stream << "</div></body></html>";
}

void HelperMainWindow::showMail(const QModelIndex &index)
{
    ui->btn_back->setVisible(true);
    ui->stw_list_or_view->setCurrentIndex(1);
    if(mails[index.row()].fetch(dou_service))
    {
        ui->pte_view->setPlainText(mails[index.row()].getContent());
    }
}

void HelperMainWindow::on_btn_back_clicked()
{
    ui->btn_back->setVisible(false);
    ui->stw_list_or_view->setCurrentIndex(0);
}
