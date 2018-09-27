#include "host.h"
#include <qdebug.h>

Host::Host()
{
    time = 0;
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    connect(this,SIGNAL(amountOfTimeHaveChanged()), this, SLOT(returnOfValue()));
}

void Host::startOfTimer(QObject *object, int amountOfTime)
{
    timer->start(1000);
    obj = object;
    time = amountOfTime;

}

void Host::counting(int amountOfTime)
{
    time = amountOfTime;

}

int Host::returnOfValue()
{
    qDebug() << time;
    return time;
}

void Host::update()
{
    if (time != 0)
    {
        time = time - 1;
    }
    else
    {
        time = 0;
        timer->stop();
    }

//    emit amountOfTimeHaveChanged();
    obj->setProperty("text",time);
}
