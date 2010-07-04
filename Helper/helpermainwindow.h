#ifndef HELPERMAINWINDOW_H
#define HELPERMAINWINDOW_H

#include <QMainWindow>
#include <QStateMachine>
#include <libdou.h>

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

public slots:
    void connectToDouService();
    void authorizeDouService();

signals:
    void authorizeSucceeded();
    void authorizeFailed();

private:
    Ui::MainWindow *ui;
    QStateMachine state_machine;
    QState *st_connect;
    QState *st_authorize;
    QState *st_failure;
    QState *st_list;
    QState *st_view;

    pcontext dou_service;
};

#endif // HELPERMAINWINDOW_H
