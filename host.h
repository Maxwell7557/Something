#ifndef HOST_H
#define HOST_H

#include <QTimer>
#include <QObject>

class Host: public QObject
{
    Q_OBJECT
    QTimer *timer = new QTimer(this);
//    QObject *obj = this->parent()->findChild("timeText");
public:
    int time;
    Host();
signals:
    void amountOfTimeHaveChanged();
public slots:
    void counting(int amountOfTime);
    int returnOfValue();
    void update();
    void startOfTimer();
};

#endif // HOST_H
