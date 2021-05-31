#ifndef QTVIDEOEDITOR_BACKEND_RANDOM_NUMBER_GENERATOR_H_
#define QTVIDEOEDITOR_BACKEND_RANDOM_NUMBER_GENERATOR_H_

#include <QDebug>
#include <QObject>

class RandomNumberGenerator : public QObject {
  Q_OBJECT
  Q_PROPERTY(int Generate READ Generate NOTIFY randomNumberGenerated)

public:
  explicit RandomNumberGenerator(QObject *parent = nullptr);

signals:
  void randomNumberGenerated();

public slots:
  int Generate();
};
#endif // QTVIDEOEDITOR_BACKEND_RANDOM_NUMBER_GENERATOR_H_
