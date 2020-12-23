#include "mainwindow.h"
#include <QApplication>
#include <QtQuick/QQuickView>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    QQmlApplicationEngine engine;
//    engine.load(QUrl("qrc:/qml/main.qml"));
//    QObject *topLevel = engine.rootObjects().value(0);
//    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);
//    window->show();


    QQuickView viewer;
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);
    viewer.setSource(QUrl("qrc:/qml/main.qml"));
    viewer.show();

    return a.exec();
}
