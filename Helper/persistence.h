#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include <QObject>

#include "objects.h"

class Persistence : public QObject
{
Q_OBJECT
Q_DISABLE_COPY(Persistence)

public:
    explicit Persistence(QObject *parent = 0);
    bool pushNew(Mail mail);
    void Save(QString filename);
    void Load(QString filename);

private:
    QList<Mail> mails;

signals:

public slots:

};

#endif // PERSISTENCE_H
