#ifndef CIVILISATION_H_INCLUDED
#define CIVILISATION_H_INCLUDED

#include <string>
#include "randomgen.h"

class civilisation {
public:
  // technological attributes
  unsigned char techlevel;      // how technologically advanced (0=present day, 63=BSG, 127=babylon5, 191=star trek, 255=fire upon the deep beyonder)
  unsigned char wealth;         // culture's material wealth and resource availability (0=no resources - BSG humans, 63=star wars empire, 127=, 191=star trek, 255=apparently infinite - star wars empire)
  bool invented_ftl;            // has invented faster than light travel?
  bool invented_coldsleep;      // has invented cryogenic suspension?
  bool invented_cloaking;       // has invented ways to make ships invisible to eyes and sensors?
  bool invented_forcefields;    // has invented ways to use energy to prevent physical passage and damage?
  bool invented_antimatter;     // has invented ways of producing and storing antimatter as an energy source
  bool invented_singularities;  // has invented ways of harnessing singularities (miniature black holes) as an energy source
  bool invented_tractorbeams;   // has invented ways to use energy to move matter remotely?
  bool invented_holograms;      // has invented interactive 3D imaging with haptic capability (holodecks etc)?
  bool invented_androids;       // whether artificially intelligent humanoid machines exist
  bool invented_cloning;        // whether fast human cloning exists (producing duplicates with a short gestation time)
  bool invented_teleportation;  // has invented ways of transmitting individual living beings across space as energy
  bool invented_replicator;     // has invented ways of reassembling matter into new molecules

  // social attributes
  bool deathpenalty;      // whether execution is a legitimate form of punishment
  bool alcohol_legal;     // whether alcohol may be consumed onboard
  bool tobacco_legal;     // whether tobacco may be smoked onboard
  bool stimulants_legal;  // whether stimulants may be used onboard
  bool drugs_legal;       // whether narcotic drugs may be used onboard
  bool uniform_mandatory; // whether all crew must wear uniform at all times

  // racial/cultural preferences (-127 to 127, default to 0)
  char intelligence;    // how likely individuals are to make the "right" decisions
  char strength;        // how strong individuals are on average
  char homogeneity;     // how similar individuals' attributes are to the racial stereotype
  char stressability;   // how susceptible they are to stress
  char hierarchicality; // how deep command and power structures are
  char discipline;      // how likely to follow orders / procedure in stress situations
  char liberalism;      // how likely to value individual freedom (in others)
  char selfishness;     // how likely to prioritise own individual well-being over others
  char generosity;      // how likely to give things away or share resources
  char honesty;         // how likely to prioritise telling the truth
  char sociability;     // how likely to make friends, how important social time is
  char geekiness;       // how likely to spend time learning
  char physicality;     // how likely to spend time on physical training
  char mercantility;    // how important trade is
  char artisticness;    // how important works of art are
  char religiousness;   // how important religious ceremony is
  char fashion;         // how important clothes and uniforms are
  char treachery;       // how likely to betray their comrades
  char belligirence;    // how eager to start a fight
  char ruthlessness;    // how likely to ignore the suffering of others
  char vangefulness;    // how likely to seek revenge when wronged
  char cowardice;       // how likely to prioritise self-preservation
  char laziness ;       // how likely they are to de-prioritise a physical task
  char alcohol_use;     // predilection to drinking alcohol (incapacitating for work)
  char tobacco_use;     // predilection to smoking
  char stimulant_use;   // predilection to using stimulants for work (caffeine, amphetamines)
  char drug_use;        // predilection to using narcotic drugs (incapacitating for work)

  randomgenerator *randomgen;

  civilisation(unsigned int seed);
  ~civilisation();
  std::string describe();
};

#endif // CIVILISATION_H_INCLUDED
