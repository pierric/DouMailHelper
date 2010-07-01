#include <QDesktopServices>
#include <QUrl>
#include <QTextCodec>
#include <QDebug>
#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Main)
{
    ui->setupUi(this);
    dou_context = NULL;
    connect(ui->phase1_btn, SIGNAL(clicked()), this, SLOT(authorizeGetRequestToken()));
    connect(ui->phase2_btn, SIGNAL(clicked()), this, SLOT(authorizeGetAccessToken()));
    connect(ui->mail_btn,   SIGNAL(clicked()), this, SLOT(getMails()));
}

Dialog::~Dialog()
{
    delete ui;
    if(dou_context)
        free(dou_context);
}

void Dialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Dialog::authorizeGetRequestToken()
{
    dou_context = initialize("0fab16a3feb4853d2f0143ebfc1d8fb7", "fa4d182f572cd229");
    char uri[100];
    get_authorize_uri(dou_context, uri);
    QDesktopServices::openUrl(QUrl(uri));
}
void Dialog::authorizeGetAccessToken()
{
    if(authorize(dou_context))
        ui->status->setText("Succeed");
    else
        ui->status->setText("Fail");
}
void Dialog::getMails()
{
    char* mails = get_inbox(dou_context, 0, 10);
    if(mails)
    {
        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        ui->xml->setPlainText(codec->toUnicode(mails));
        free(mails);
    }
}
