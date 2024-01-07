#ifndef SMS_H
#define SMS_H

#include <QObject>
#include <QString>
#include <QNetworkReply>
#include "qtmessagelib_global.h"

class QTMESSAGELIB_EXPORT SMS: public QObject
{
    Q_OBJECT
public:
    QTMESSAGELIB_EXPORT SMS(QString sid, QString token, QString from);
    QTMESSAGELIB_EXPORT void Send(QString to, QString message);

signals:
    void finished();
private slots:
    void responseReceived(QNetworkReply * reply);

private:
    QString sid;
    QString token;
    QString from;
};

#endif // SMS_H
