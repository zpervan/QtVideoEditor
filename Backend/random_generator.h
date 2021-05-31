#ifndef QTVIDEOEDITOR_BACKEND_RANDOM_GENERATOR_H_
#define QTVIDEOEDITOR_BACKEND_RANDOM_GENERATOR_H_

#include <QDebug>
#include <QObject>
#include <random>

class RandomGenerator : public QObject {
  Q_OBJECT
  Q_PROPERTY(int GenerateNumber READ GenerateNumber CONSTANT)
  Q_PROPERTY(QString GenerateColor READ GenerateColor CONSTANT)
  Q_PROPERTY(double GenerateNormalizedPosition READ GenerateNormalizedPosition CONSTANT)

public:
  explicit RandomGenerator(QObject *parent = nullptr);

public slots:
  int GenerateNumber();
  QString GenerateColor();
  double GenerateNormalizedPosition();

private:
  std::random_device random_device_;
  std::default_random_engine random_engine_;
  std::uniform_int_distribution<int> int_number_distribution_;
  std::uniform_real_distribution<double> real_number_distribution_;
};
#endif // QTVIDEOEDITOR_BACKEND_RANDOM_GENERATOR_H_
