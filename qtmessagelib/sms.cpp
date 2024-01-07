#include "sms.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QUrlQuery>
#include <QString>
#include <QByteArray>
#include <QTextStream>

SMS::SMS(QString sid, QString token, QString from): sid(sid), token(token), from(from) {}

void SMS::Send(QString to, QString message) {

    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(responseReceived(QNetworkReply*)));
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SIGNAL(finished()));
    QUrl url(QString("https://api.twilio.com/2010-04-01/Accounts/%1/Messages.json").arg(sid));
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    QString authtoken = QString("%1:%2").arg(sid,token).toUtf8().toBase64();
    request.setRawHeader("Authorization",QString("Basic %1").arg(authtoken).toUtf8());
    QUrlQuery postArray;
    postArray.addQueryItem("From",from);
    postArray.addQueryItem("To",to);
    postArray.addQueryItem("Body",message);
    manager->post(request, postArray.toString(QUrl::FullyEncoded).toUtf8());
}

void SMS::responseReceived(QNetworkReply * reply) {
    QByteArray response = reply->readAll();
    QString str = QString::fromUtf8(response);
    qDebug() << "Reply: " << str;
    reply->deleteLater();
}
