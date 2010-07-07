#ifndef HELPERMAINWINDOW_H
#define HELPERMAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QStateMachine>
#include <QAbstractItemModel>
#include <QList>
#include "libdou.h"
#include "objects.h"

namespace Ui
{
    class MainWindow;
}

class HelperMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    HelperMainWindow(QWidget *parent=0);
    ~HelperMainWindow();

protected:
    void changeEvent(QEvent *);

private slots:
    void on_btn_back_clicked();
    void on_btn_export_clicked();
    void listInboxMails();
    void listOutboxMails();
    void connectToDouService();
    void authorizeDouService();
    void disconnectFromDouService();
    void showMail(const QModelIndex &index);

signals:
    void connectSucceeded();
    void authorizeSucceeded();
    void authorizeFailed();

private:
    Ui::MainWindow *ui;
    QLabel *connect_status;
    QStateMachine state_machine;
    QState *st_connect;
    QState *st_authorize;
    QState *st_failure;
    QState *st_list;
    QState *st_view;

    QAbstractItemModel *mdl_inbox;
    QAbstractItemModel *mdl_outbox;

    QList<Mail> mails;

    pcontext dou_service;

private:
    void whoAmI();
};

#endif // HELPERMAINWINDOW_H
