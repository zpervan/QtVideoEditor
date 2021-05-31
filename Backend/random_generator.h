#ifndef QTVIDEOEDITOR_BACKEND_RANDOM_GENERATOR_H_
#define QTVIDEOEDITOR_BACKEND_RANDOM_GENERATOR_H_

#include <QDebug>
#include <QObject>
#include <random>

/// @brief Contains all logic related to generating random integer and real numbers
class RandomGenerator : public QObject {
  Q_OBJECT
  Q_PROPERTY(int GenerateNumber READ GenerateNumber CONSTANT)
  Q_PROPERTY(QString GenerateColor READ GenerateColor CONSTANT)
  Q_PROPERTY(double GenerateNormalizedPosition READ GenerateNormalizedPosition CONSTANT)

public:
  explicit RandomGenerator(QObject *parent = nullptr);

public slots:
  /// @brief Generates a random integer number between 0 and 146
  /// @return Randomly generated integer value
  int GenerateNumber();

  /// @brief Returns a color name from the color map based on the randomly
  /// generated integer value
  /// @return Color name
  QString GenerateColor();

  /// @brief Generated a real numeric value between 0.0 and 1.0 which is used
  /// for the gradient color position
  /// @return Gradient color position as a normalized value
  double GenerateNormalizedPosition();

private:
  std::random_device random_device_;
  std::default_random_engine random_engine_;
  std::uniform_int_distribution<int> int_number_distribution_;
  std::uniform_real_distribution<double> real_number_distribution_;
};
#endif // QTVIDEOEDITOR_BACKEND_RANDOM_GENERATOR_H_
