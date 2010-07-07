#include "objects.h"
#include <QList>
#include <QTextCodec>
#include <QDomDocument>
#include <QDebug>

QList<Mail> MailParser::parse(const QString &xml)
{
    QDomDocument doc;
    QList<Mail> list;
    if( doc.setContent(xml, &errorMsg, &errorLine, &errorColumn) )
    {
        QDomElement root = doc.documentElement();
        QDomNodeList entries = root.elementsByTagName("entry");
        for(int i=0; i<entries.size(); i++)
        {
            Mail m;
            QDomElement node = entries.item(i).toElement();
            m.setId( node.firstChildElement("id").firstChild().toText().data() );
            m.setTitle( node.firstChildElement("title").firstChild().toText().data() );
            m.setPublishedTime(QDateTime::fromString(node.firstChildElement("published").firstChild().toText().data(),
                                                     Qt::ISODate));
            QDomNodeList attrs = node.elementsByTagName("db:attribute");
            for(int j=0;j<attrs.size();j++)
            {
                m.setUnreadFlag( attrs.item(j).attributes().contains("name") &&
                                 attrs.item(j).attributes().namedItem("name").toAttr().value() == "unread" &&
                                 attrs.item(j).firstChild().toText().data() == "true" );
            }

            Author author;
            author.setName(node.firstChildElement("author").firstChildElement("name").firstChild().toText().data());
            author.setUri(node.firstChildElement("author").firstChildElement("uri").firstChild().toText().data());
            m.setAuthor(author);
            list.push_back(m);
        }
    }
    return list;
}


Author::Author()
{

}

Author::~Author()
{

}

Mail::Mail()
{
}

Mail::~Mail()
{
}

bool Mail::fetch(pcontext c)
{
    if(id.length() == 0) return false;
    char *reply= service_request_get(c, id.toAscii().data());
    if(reply)
    {
        QString xml = QTextCodec::codecForName("UTF-8")->toUnicode(reply);
        QDomDocument doc;
        bool ok = doc.setContent(xml, (QString*)NULL, (int*)NULL, (int*)NULL);
        if(ok)
        {
            QDomNodeList cl = doc.elementsByTagName("content");
            if(cl.size()==1)
                content = cl.item(0).firstChild().toText().data();
            else
                ok = false;
        }
        free(reply);
        return ok;
    }
    return false;
}
