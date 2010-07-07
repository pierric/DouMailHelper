#include <QtGui/QApplication>
#include "helpermainwindow.h"

int main(int argc, char **argv)
{
    Q_INIT_RESOURCE(resource);
    QApplication a(argc, argv);
    HelperMainWindow w;
    w.show();
    return a.exec();
}
