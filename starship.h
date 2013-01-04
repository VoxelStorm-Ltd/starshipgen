#ifndef STARSHIP_H_INCLUDED
#define STARSHIP_H_INCLUDED

#include <vector>
#include <string>
#include "randomgen.h"
#include "component.h"
#include "dependency.h"

class starship {
public:
  enum propulsiontype {
    PROPULSION_WARPBUBBLE,        // Space distortion bubble generator (star trek warp)
    PROPULSION_FUSION,            // Fusion rocket (star trek impulse)
    PROPULSION_FISSION,           // Fission rocket
    PROPULSION_CHEMICAL,          // Chemical rocket
    PROPULSION_ANTIMATTER,        // Antimatter rocket
    PROPULSION_HYPERDRIVE,        // Hyperdrive (star wars hyperdrive0
    PROPULSION_JUMPFINS,          // Jump fins (fire upon the deep jump drive)
    PROPULSION_WITCHSPACE,        // Witchspace drive (elite hyperspace jump)
    PROPULSION_ION,               // Ion thruster
    PROPULSION_RAMSCOOP,          // Ramscoop (fire upon the deep ramscoops)
    PROPULSION_SAIL,              // Light sails
    PROPULSION_VASIMR,            // VASIMR
    PROPULSION_ANTIMATTERFUSION,  // Antimatter catalyzed nuclear pulse
    PROPULSION_WORMHOLE,          // Wormholes (star trek wormholes)
    PROPULSION_WARPGATE           // Warp gates (cowboy bebop warp gates)
  };

  enum energysourcetype {
    ENERGY_FISSIONREACTOR,        // Nuclear fission reactor
    ENERGY_FUSIONREACTOR,         // Nuclear fusion reactor
    ENERGY_BATTERY,               // Electrical battery
    ENERGY_ANTIMATTERREACTOR,     // Matter/antimatter reactor
    ENERGY_SOLARPANEL,            // Solar panel
  };

  randomgenerator *randomgen;

  std::vector<component*> parts;          // its constituent component parts
  std::vector<dependency*> dependencies;  // all shipboard interdependencies

  starship(unsigned int seed);
  ~starship();
  std::string describe();
};

#endif // STARSHIP_H_INCLUDED
