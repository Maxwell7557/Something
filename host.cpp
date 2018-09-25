#include "host.h"

Host::Host()
{

}

int Host::counting(int amountOfTime)
{
    connect(timer, SIGNAL(amountOfTimeChanged()), this, SLOT(counting(int)));
    timer->start(100);

    if (amountOfTime != 0)
    {
        amountOfTime -= 1;
    }

    emit amountOfTimeHaveChanged(amountOfTime);

    return amountOfTime;
}
