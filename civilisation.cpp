#include "civilisation.h"
#include <cstdlib>
#include <string>
#include <sstream>
#include <boost/random/uniform_smallint.hpp>
#include <boost/random/discrete_distribution.hpp>

civilisation::civilisation(unsigned int seed) {
  std::srand(seed);

  // technological attributes
  techlevel = random_uchar();
  wealth    = random_uchar();
  if(wealth < techlevel / (unsigned char)2) {
    // ensure that wealth is not too far behind technology, or it looks silly
    std::cout << "DEBUG: 1" << std::endl;
    wealth = techlevel / 2;
  }
  std::cout << "DEBUG: tech " << (unsigned int)techlevel << " wealth " << (unsigned int)wealth << std::endl;
  invented_ftl           = random_bool_weighted(0.75);
  invented_coldsleep     = random_bool_weighted(0.3);
  invented_cloaking      = random_bool_weighted(0.3);
  invented_forcefields   = random_bool_weighted(0.75);
  invented_antimatter    = random_bool_weighted(0.5);
  invented_singularities = random_bool_weighted(0.3);
  invented_tractorbeams  = random_bool_weighted(0.75);
  invented_holograms     = random_bool_weighted(0.5);
  invented_androids      = random_bool_weighted(0.75);
  invented_cloning       = random_bool_weighted(0.2);
  invented_teleportation = random_bool_weighted(0.2);

  // social attributes
  deathpenalty      = random_bool_weighted(0.25);
  alcohol_legal     = random_bool_weighted(0.75);
  tobacco_legal     = random_bool_weighted(0.25);
  stimulants_legal  = random_bool_weighted(0.5);
  drugs_legal       = random_bool_weighted(0.10);
  uniform_mandatory = random_bool_weighted(0.8);

  // racial/cultural preferences (-127 to 127, default to 0)
  intelligence    = random_char();
  strength        = random_char();
  homogeneity     = random_char();
  stressability   = random_char();
  hierarchicality = random_char();
  discipline      = random_char();
  liberalism      = random_char();
  selfishness     = random_char();
  generosity      = random_char();
  honesty         = random_char();
  sociability     = random_char();
  geekiness       = random_char();
  physicality     = random_char();
  mercantility    = random_char();
  artisticness    = random_char();
  religiousness   = random_char();
  fashion         = random_char();
  treachery       = random_char();
  belligirence    = random_char();
  ruthlessness    = random_char();
  vangefulness    = random_char();
  cowardice       = random_char();
  alcohol_use     = random_char();
  tobacco_use     = random_char();
  stimulant_use   = random_char();
  drug_use        = random_char();
}

civilisation::~civilisation() {
}

bool civilisation::random_bool() {
  boost::random::uniform_smallint<> randomdist(0, 1);
  return randomdist(randomgen);
}

bool civilisation::random_bool_weighted(double weight_true) {
  double probabilities[2];
  probabilities[1] = weight_true;
  probabilities[0] = 1 - probabilities[1];
  boost::random::discrete_distribution<> randomdist(probabilities);
  return randomdist(randomgen);
}

char civilisation::random_char() {
  boost::random::uniform_smallint<> randomdist(-127, 127);
  return randomdist(randomgen);
}
unsigned char civilisation::random_uchar() {
  boost::random::uniform_smallint<> randomdist(0, 255);
  return randomdist(randomgen);
}

std::string civilisation::describe() {
  std::stringstream desc;
  desc << "This is a ";
  if(techlevel >= 192) {
    desc << "highly advanced";
  } else if(techlevel >= 128) {
    desc << "moderately advanced";
  } else if(techlevel >= 64) {
    desc << "relatively new";
  } else {
    desc << "low-tech";
  }
  desc << " (techlevel " << (unsigned int)techlevel << ")";
  if(wealth >= 192) {
    desc << ", very wealthy";
  } else if(wealth >= 128) {
    desc << ", wealthy";
  } else if(wealth >= 64) {
  } else {
    desc << ", impoverished";
  }
  desc << " (wealth " << (unsigned int)wealth << ")";
  desc << " civilisation.";

  char attributenotethreshold = 100;

  return desc.str();
}
