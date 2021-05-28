#include "GUI/menu.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>

int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);

  Menu menu;

  QQmlApplicationEngine engine;
  engine.rootContext()->setContextProperty("menu", &menu);

  engine.load("qrc:/main.qml");

  if (engine.rootObjects().isEmpty()) {
    return EXIT_FAILURE;
  }

  return app.exec();
}
