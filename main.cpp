#include "GUI/menu.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);

  qmlRegisterType<Menu>("custom.widget.menu", 1, 0, "Menu");

  QQmlApplicationEngine engine;
  engine.load("qrc:/main.qml");

  if (engine.rootObjects().isEmpty()) {
    return EXIT_FAILURE;
  }

  return app.exec();
}
