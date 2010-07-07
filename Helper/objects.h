#ifndef OBJECTS_H
#define OBJECTS_H

#include <QObject>
#include <QString>
#include <QTime>
#include "libdou.h"

class Author
{
Q_GADGET
Q_PROPERTY(int uri READ getUri WRITE setUri)
Q_PROPERTY(QString name READ getName WRITE setName);

public:
    Author();
    ~Author();

    const QString& getUri(void) const{ return uri; }
    const QString& getName(void) const{ return name; }

    void setUri(const QString &_uri)
    {
        uri = _uri;
    }
    void setName(const QString &_name)
    {
        name = _name;
    }

private:
    QString uri;
    QString name;
};

class Mail
{
Q_GADGET
Q_PROPERTY(QString id READ getId WRITE setId)
Q_PROPERTY(QString title READ getTitle WRITE setTitle)
Q_PROPERTY(Author author READ getAuthor WRITE setAuthor)
Q_PROPERTY(QDateTime publishedTime READ getPubilshedTime WRITE setPublishedTime)
Q_PROPERTY(bool unreadFlag READ getUnreadFlag WRITE setUnreadFlag)

public:
    Mail();
    ~Mail();

    const QString& getId() const
    {
        return id;
    }
    void setId(const QString& _id)
    {
        id = _id;
    }
    const QString& getTitle() const
    {
        return title;
    }
    void setTitle(const QString &_title)
    {
        title = _title;
    }
    const Author& getAuthor() const
    {
        return author;
    }
    void setAuthor(const Author &_author)
    {
        author = _author;
    }
    const QDateTime& getPublishedTime() const
    {
        return publishedTime;
    }
    void setPublishedTime(const QDateTime &_time)
    {
        publishedTime = _time;
    }
    bool getUnreadFlag() const
    {
        return unreadFlag;
    }
    void setUnreadFlag(bool flag)
    {
        unreadFlag = flag;
    }

    bool fetch(pcontext);

    const QString& getContent()
    {
        return content;
    }

private:
    QString id;
    QString title;
    Author author;
    QDateTime publishedTime;
    bool unreadFlag;
    QString content;
};

class MailParser
{
public:
    QList<Mail> parse(const QString &xml);

    QString errorMsg;
    int errorLine;
    int errorColumn;
};

#endif // OBJECTS_H
