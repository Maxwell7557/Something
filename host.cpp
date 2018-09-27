#include "host.h"
#include <qdebug.h>

Host::Host()
{
    time = 0;
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    connect(this,SIGNAL(amountOfTimeHaveChanged()), this, SLOT(returnOfValue()));
//    QObject *obj = this->parent()->findChild("textLable");
}

void Host::startOfTimer()
{
    timer->start(1000);
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
    }

    emit amountOfTimeHaveChanged();
}
