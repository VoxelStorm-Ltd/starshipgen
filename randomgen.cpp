#include "randomgen.h"
#include <boost/random/uniform_smallint.hpp>
#include <boost/random/discrete_distribution.hpp>
#include <boost/random/normal_distribution.hpp>

randomgenerator::randomgenerator(unsigned int seed) {
  gen.seed(seed);
}

bool randomgenerator::random_bool() {
  boost::random::uniform_smallint<> randomdist(0, 1);
  return randomdist(gen);
}

bool randomgenerator::random_bool_weighted(double weight_true) {
  double probabilities[2];
  probabilities[1] = weight_true;
  probabilities[0] = 1 - probabilities[1];
  boost::random::discrete_distribution<> randomdist(probabilities);
  return randomdist(gen);
}

char randomgenerator::random_char() {
  boost::random::uniform_smallint<> randomdist(-127, 127);
  return randomdist(gen);
}
char randomgenerator::random_char_normal() {
  boost::random::normal_distribution<> randomdist(0.0, 64.0);
  return randomdist(gen);
}

unsigned char randomgenerator::random_uchar() {
  boost::random::uniform_smallint<> randomdist(0, 255);
  return randomdist(gen);
}
unsigned char randomgenerator::random_uchar_normal() {
  boost::random::normal_distribution<> randomdist(127.0, 64.0);
  return randomdist(gen);
}
