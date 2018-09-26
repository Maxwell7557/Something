#include "host.h"

Host::Host()
{

}

int Host::counting(int amountOfTime)
{
    time = amountOfTime;

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(100);

//    time = update();

    return time;
}

int Host::update()
{
    connect(this,SIGNAL(amountOfTimeHaveChanged(int)), this, SLOT(counting(int)));

    if (time != 0)
    {
        time -= 1;
    }
    else
    {
        time = 0;
    }

    emit amountOfTimeHaveChanged(time);

    return time;
}
