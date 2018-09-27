#include "host.h"

Host::Host()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    connect(this,SIGNAL(amountOfTimeHaveChanged(int)), this, SLOT(counting(int)));

//    QObject *obj = this->parent()->findChild("timeText");
}

void Host::startOfTimer()
{
    timer->start(100);
}

int Host::counting(int amountOfTime)
{
    time = amountOfTime;

    return last;
}

void Host::update()
{
    if (time != 0)
    {
        time -= 1;
    }
    else
    {
        time = 0;
    }

    last = time;

    obj->setProperty("text",time);

    emit amountOfTimeHaveChanged(time);
}
