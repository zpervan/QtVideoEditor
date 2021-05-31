#include "random_number_generator.h"
#include <random>

RandomNumberGenerator::RandomNumberGenerator(QObject *parent)
    : QObject(parent) {}

int RandomNumberGenerator::Generate() {
  std::mt19937 random_number(std::time(nullptr));
//  qDebug() << random_number();
  return random_number();
}
