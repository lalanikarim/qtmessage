#include <QCoreApplication>
#include <QObject>
#include "sms.h"
#include "private.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SMS twilio(PRIVATE_SID, PRIVATE_TOKEN, PRIVATE_FROM);
    QObject::connect(&twilio,SIGNAL(finished()),&a,SLOT(quit()));
    twilio.Send(PRIVATE_TO,"SMS Message to send");
    return a.exec();
}
