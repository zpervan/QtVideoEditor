#include "random_generator.h"
#include "types.h"
#include <random>

RandomGenerator::RandomGenerator(QObject *parent)
    : QObject(parent),
      random_device_(std::random_device()),
      random_engine_(random_device_()),
      int_number_distribution_(std::uniform_int_distribution<int>(0, types::color_map.size() - 1)),
      real_number_distribution_(std::uniform_real_distribution<double>(0.0, 1.0)){}

int RandomGenerator::GenerateNumber() {
  return int_number_distribution_(random_engine_);
}

QString RandomGenerator::GenerateColor() {
  return types::color_map[GenerateNumber()];
}

double RandomGenerator::GenerateNormalizedPosition() {
  return real_number_distribution_(random_engine_);
}
