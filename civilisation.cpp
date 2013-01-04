#include "civilisation.h"
#include <cstdlib>

civilisation::civilisation(unsigned int seed) {
  randomgen = new randomgenerator(seed);

  // technological attributes
  techlevel = randomgen->random_uchar();
  wealth    = randomgen->random_uchar();
  if(wealth < techlevel / (unsigned char)2) {
    // ensure that wealth is not too far behind technology, or it looks silly
    wealth = techlevel / 2;
  }
  invented_ftl           = randomgen->random_bool_weighted(0.75);
  invented_coldsleep     = randomgen->random_bool_weighted(0.3);
  invented_cloaking      = randomgen->random_bool_weighted(0.3);
  invented_forcefields   = randomgen->random_bool_weighted(0.75);
  invented_antimatter    = randomgen->random_bool_weighted(0.5);
  invented_singularities = randomgen->random_bool_weighted(0.3);
  invented_tractorbeams  = randomgen->random_bool_weighted(0.75);
  invented_holograms     = randomgen->random_bool_weighted(0.5);
  invented_androids      = randomgen->random_bool_weighted(0.75);
  invented_cloning       = randomgen->random_bool_weighted(0.2);
  invented_teleportation = randomgen->random_bool_weighted(0.2);
  invented_replicator    = randomgen->random_bool_weighted(0.75);

  // racial/cultural preferences (-127 to 127, default to 0)
  intelligence    = randomgen->random_char_normal();
  strength        = randomgen->random_char_normal();
  homogeneity     = randomgen->random_char_normal();
  stressability   = randomgen->random_char_normal();
  liberalism      = randomgen->random_char_normal();
  hierarchicality = randomgen->random_char_normal();
  if(hierarchicality < -liberalism) {
    hierarchicality = -liberalism;
  }
  discipline      = randomgen->random_char_normal();
  selfishness     = randomgen->random_char_normal();
  if(selfishness > -discipline) {
    selfishness = -discipline;
  }
  generosity      = randomgen->random_char_normal();
  honesty         = randomgen->random_char_normal();
  sociability     = randomgen->random_char_normal();
  geekiness       = randomgen->random_char_normal();
  physicality     = randomgen->random_char_normal();
  mercantility    = randomgen->random_char_normal();
  artisticness    = randomgen->random_char_normal();
  religiousness   = randomgen->random_char_normal();
  fashion         = randomgen->random_char_normal();
  treachery       = randomgen->random_char_normal();
  if(treachery > -honesty) {
    treachery = -honesty;
  }
  belligirence    = randomgen->random_char_normal();
  ruthlessness    = randomgen->random_char_normal();
  vangefulness    = randomgen->random_char_normal();
  cowardice       = randomgen->random_char_normal();
  laziness        = randomgen->random_char_normal();
  alcohol_use     = randomgen->random_char_normal();
  tobacco_use     = randomgen->random_char_normal();
  stimulant_use   = randomgen->random_char_normal();
  drug_use        = randomgen->random_char_normal();


  // social attributes
  deathpenalty      = randomgen->random_bool_weighted(0.25);
  if(vangefulness > 100) {
    deathpenalty = true;
  }
  if(ruthlessness > 100) {
    deathpenalty = true;
  }
  alcohol_legal     = randomgen->random_bool_weighted(0.75);
  if(alcohol_use < -63) {
    alcohol_legal = false;
  }
  tobacco_legal     = randomgen->random_bool_weighted(0.25);
  if(tobacco_use < -63) {
    tobacco_legal = false;
  }
  stimulants_legal  = randomgen->random_bool_weighted(0.75);
  if(stimulant_use < -63) {
    stimulants_legal = false;
  }
  drugs_legal       = randomgen->random_bool_weighted(0.10);
  if(drug_use < -63) {
    drugs_legal = false;
  }
  uniform_mandatory = randomgen->random_bool_weighted(0.8);
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


