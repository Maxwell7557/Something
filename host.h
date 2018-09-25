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
    Host();
signals:
    void amountOfTimeHaveChanged(int amountOfTime);
public slots:
    int counting(int amountOfTime);
};

#endif // HOST_H
