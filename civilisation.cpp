#include "civilisation.h"
#include <cstdlib>
#include <boost/random/uniform_smallint.hpp>
#include <boost/random/discrete_distribution.hpp>
#include <boost/random/normal_distribution.hpp>

civilisation::civilisation(unsigned int seed) {
  std::srand(seed);
  randomgen.seed(seed);

  // technological attributes
  techlevel = random_uchar();
  wealth    = random_uchar();
  if(wealth < techlevel / (unsigned char)2) {
    // ensure that wealth is not too far behind technology, or it looks silly
    wealth = techlevel / 2;
  }
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

  // racial/cultural preferences (-127 to 127, default to 0)
  intelligence    = random_char_normal();
  strength        = random_char_normal();
  homogeneity     = random_char_normal();
  stressability   = random_char_normal();
  liberalism      = random_char_normal();
  hierarchicality = random_char_normal();
  if(hierarchicality < -liberalism) {
    hierarchicality = -liberalism;
  }
  discipline      = random_char_normal();
  selfishness     = random_char_normal();
  if(selfishness > -discipline) {
    selfishness = -discipline;
  }
  generosity      = random_char_normal();
  honesty         = random_char_normal();
  sociability     = random_char_normal();
  geekiness       = random_char_normal();
  physicality     = random_char_normal();
  mercantility    = random_char_normal();
  artisticness    = random_char_normal();
  religiousness   = random_char_normal();
  fashion         = random_char_normal();
  treachery       = random_char_normal();
  if(treachery > -honesty) {
    treachery = -honesty;
  }
  belligirence    = random_char_normal();
  ruthlessness    = random_char_normal();
  vangefulness    = random_char_normal();
  cowardice       = random_char_normal();
  laziness        = random_char_normal();
  alcohol_use     = random_char_normal();
  tobacco_use     = random_char_normal();
  stimulant_use   = random_char_normal();
  drug_use        = random_char_normal();


  // social attributes
  deathpenalty      = random_bool_weighted(0.25);
  if(vangefulness > 100) {
    deathpenalty = true;
  }
  if(ruthlessness > 100) {
    deathpenalty = true;
  }
  alcohol_legal     = random_bool_weighted(0.75);
  if(alcohol_use < -63) {
    alcohol_legal = false;
  }
  tobacco_legal     = random_bool_weighted(0.25);
  if(tobacco_use < -63) {
    tobacco_legal = false;
  }
  stimulants_legal  = random_bool_weighted(0.75);
  if(stimulant_use < -63) {
    stimulants_legal = false;
  }
  drugs_legal       = random_bool_weighted(0.10);
  if(drug_use < -63) {
    drugs_legal = false;
  }
  uniform_mandatory = random_bool_weighted(0.8);
  if(liberalism > 100) {
    uniform_mandatory = false;
    stimulants_legal = true;
    alcohol_legal = true;
    deathpenalty = false;
  } else if(liberalism > 63) {
    deathpenalty = false;
    alcohol_legal = true;
  } else if(liberalism < -100) {
    uniform_mandatory = true;
    deathpenalty = true;
    drugs_legal = false;
  }
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
char civilisation::random_char_normal() {
  boost::random::normal_distribution<> randomdist(0.0, 64.0);
  return randomdist(randomgen);
}

unsigned char civilisation::random_uchar() {
  boost::random::uniform_smallint<> randomdist(0, 255);
  return randomdist(randomgen);
}
unsigned char civilisation::random_uchar_normal() {
  boost::random::normal_distribution<> randomdist(127.0, 64.0);
  return randomdist(randomgen);
}
