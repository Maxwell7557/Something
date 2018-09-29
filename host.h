#ifndef HOST_H
#define HOST_H

#include <QTimer>
#include <QObject>

class Host: public QObject
{
    Q_OBJECT
    QTimer *timer = new QTimer(this);
public:
    int time;
    QObject *obj;
    Host();
signals:
    void timeIsUp();
    void amountOfTimeHaveChanged();
    void isTimeUpSignal();
public slots:
    void counting(int amountOfTime);
    int returnOfValue();
    void update();
    void startOfTimer(QObject *object, int amountOfTime);
    void chek();
};

#endif // HOST_H
