#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "host.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

//    Host host;
//    QQmlApplicationEngine engine;
//    QQmlContext *context=engine.rootContext();
//    context->setContextProperty("host",&host);
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    qmlRegisterType<Host>("MyModule", 1,0, "Host");
    Host host;

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QQmlContext *context=engine.rootContext();
    context->setContextProperty("host",&host);

    return app.exec();
}
