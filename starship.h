#ifndef STARSHIP_H_INCLUDED
#define STARSHIP_H_INCLUDED

#include <vector>
#include <string>
#include "randomgen.h"
#include "component.h"
#include "dependency.h"
#include "civilisation.h"

class starship {
public:
  enum propulsiontype {
    PROPULSION_NONE,              // no engine
    PROPULSION_FUSION,            // Fusion rocket (star trek impulse)
    PROPULSION_FISSION,           // Fission rocket
    PROPULSION_FUSIONTHERMAL,     // Fusion thermal rocket
    PROPULSION_FISSIONTHERMAL,    // Fission thermal rocket
    PROPULSION_FISSIONFRAGMENT,   // Fission-fragment rocket
    PROPULSION_CHEMICAL,          // Chemical rocket
    PROPULSION_ANTIMATTER,        // Antimatter rocket
    PROPULSION_ION,               // Ion thruster
    PROPULSION_RAMSCOOP,          // Ramscoop (fire upon the deep ramscoops)
    PROPULSION_SAIL,              // Light sails
    PROPULSION_VASIMR,            // VASIMR
    PROPULSION_ANTIMATTERFUSION,  // Antimatter catalyzed nuclear pulse
    PROPULSION_WARPBUBBLE,        // Space distortion bubble generator (star trek warp)
    PROPULSION_HYPERDRIVE,        // Hyperdrive (star wars hyperdrive0
    PROPULSION_JUMPFINS,          // Jump fins (fire upon the deep jump drive)
    PROPULSION_WITCHSPACE,        // Witchspace drive (elite hyperspace jump)
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

  unsigned char redundancy;       // overall redundancy factor
  bool has_ftldrive;              // can it go faster than light under its own power?
  bool has_stldrive;              // can it travel under its own power slower than light?
  bool has_atmospheric;           // can it fly in an atmosphere without destruction?
  propulsiontype ftlpropulsion;   // the faster than light propulsion type
  propulsiontype propulsion;      // the ordinary propulsion type

  randomgenerator *randomgen;

  civilisation *civ;                      // pointer to the owner civilisation
  std::vector<componenttype> componenttypelist;   // the list of all component types
  std::vector<component*> parts;          // the ship's constituent component parts
  std::vector<dependency*> dependencies;  // all shipboard interdependencies

  starship(unsigned int seed, civilisation *thisciv, std::vector<componenttype*> thiscomponenttypelist);
  ~starship();
  std::string describe();
};

#endif // STARSHIP_H_INCLUDED
