#include "Backend/path_creator.h"
#include "Backend/random_generator.h"
#include "Backend/thumbnail_creator.h"
#include "Backend/video_filters.h"
#include "GUI/Code/menu.h"
#include "GUI/Code/video_list_model.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>

int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);

  qmlRegisterType<VideoListModel>("custom", 1, 0, "VideoListModel");

  Menu menu;
  RandomGenerator random_generator;
  VideoFilters video_filters;

  QQmlApplicationEngine engine;
  engine.rootContext()->setContextProperty("menu", &menu);
  engine.rootContext()->setContextProperty("randomGenerator", &random_generator);
  engine.rootContext()->setContextProperty("videoFilters", &video_filters);
  engine.load("qrc:/main.qml");

  if (engine.rootObjects().isEmpty()) {
    return EXIT_FAILURE;
  }

  return app.exec();
}
