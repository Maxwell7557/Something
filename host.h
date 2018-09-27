#ifndef HOST_H
#define HOST_H

#include <QTimer>
#include <QObject>

class Host: public QObject
{
    Q_OBJECT
    QTimer *timer = new QTimer(this);
    QObject *obj = this->parent()->findChild("timeText");
public:
    int time;
    int last;

    Host();
signals:
    void amountOfTimeHaveChanged(int amountOfTime);
public slots:
    int counting(int amountOfTime);
    void update();
    void startOfTimer();
};

#endif // HOST_H
