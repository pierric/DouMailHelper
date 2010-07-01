#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "libdou.h"

namespace Ui {
    class Main;
}

class Dialog : public QDialog {
    Q_OBJECT
public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

public slots:
    void authorizeGetRequestToken();
    void authorizeGetAccessToken();
    void getMails();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Main *ui;
    struct context *dou_context;
};

#endif // DIALOG_H
