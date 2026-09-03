#pragma once

#include <cstdint>
#include <string>
#include <vector>

class randomgenerator;
class component;
class componentlist;
class componenttype;
class dependency;
class civilisation;

class starship {
public:
  enum propulsiontype {
    PROPULSION_NONE,                                                            // no engine
    PROPULSION_FUSION,                                                          // fusion rocket (star trek impulse)
    PROPULSION_FISSION,                                                         // fission rocket
    PROPULSION_FUSIONTHERMAL,                                                   // fusion thermal rocket
    PROPULSION_FISSIONTHERMAL,                                                  // fission thermal rocket
    PROPULSION_FISSIONFRAGMENT,                                                 // fission-fragment rocket
    PROPULSION_CHEMICAL,                                                        // chemical rocket
    PROPULSION_ANTIMATTER,                                                      // antimatter rocket
    PROPULSION_ION,                                                             // ion thruster
    PROPULSION_RAMSCOOP,                                                        // ramscoop (fire upon the deep ramscoops)
    PROPULSION_SAIL,                                                            // light sails
    PROPULSION_VASIMR,                                                          // VASIMR
    PROPULSION_ANTIMATTERFUSION,                                                // antimatter catalyzed nuclear pulse
    PROPULSION_WARPBUBBLE,                                                      // space distortion bubble generator (star trek warp)
    PROPULSION_HYPERDRIVE,                                                      // hyperdrive (star wars hyperdrive)
    PROPULSION_JUMPFINS,                                                        // jump fins (fire upon the deep jump drive)
    PROPULSION_WITCHSPACE,                                                      // witchspace drive (elite hyperspace jump)
    PROPULSION_WORMHOLE,                                                        // wormholes (star trek wormholes)
    PROPULSION_WARPGATE                                                         // warp gates (cowboy bebop warp gates)
  };

  enum energysourcetype {
    ENERGY_FISSIONREACTOR,                                                      // nuclear fission reactor
    ENERGY_FUSIONREACTOR,                                                       // nuclear fusion reactor
    ENERGY_BATTERY,                                                             // electrical battery
    ENERGY_ANTIMATTERREACTOR,                                                   // matter/antimatter reactor
    ENERGY_SOLARPANEL,                                                          // solar panel
  };

  bool has_ftldrive;                                                            // can it go faster than light under its own power?
  bool has_stldrive;                                                            // can it travel under its own power slower than light?
  bool has_atmospheric;                                                         // can it fly in an atmosphere without destruction?
  propulsiontype ftlpropulsion;                                                 // the faster than light propulsion type
  propulsiontype propulsion;                                                    // the ordinary propulsion type

  randomgenerator *randomgen;

  civilisation *civ;                                                            // pointer to the owner civilisation
  componentlist *componenttypes;                                                // pointer to the components list
  std::vector<component*> parts;                                                // the ship's constituent component parts
  std::vector<dependency*> dependencies;                                        // all shipboard interdependencies

  // pointers to specific ship components
  std::vector<component*> component_engines_ftl;
  std::vector<component*> component_engines_stl;
  std::vector<component*> component_power;
  std::vector<component*> component_weapons;
  std::vector<component*> component_lifesupport;

  uint64_t shipclock;                                                           // ship's clock, in seconds since ship's epoch

  starship(unsigned int seed, civilisation *thisciv, componentlist *componenttypest);
  ~starship();
  std::string describe();

  unsigned int get_component_count();
  unsigned int get_component_count(std::vector<component*> *componentgroup);
  unsigned int get_systems_count();
  unsigned int get_systems_count(std::vector<component*> *componentgroup);
  unsigned int get_time_on();
  unsigned int get_time_on(std::vector<component*> *componentgroup);
  unsigned int get_time_off();
  unsigned int get_time_off(std::vector<component*> *componentgroup);
  unsigned int get_required_energy();
  unsigned int get_required_energy(std::vector<component*> *componentgroup);
  unsigned int get_required_fuel();
  unsigned int get_required_fuel(std::vector<component*> *componentgroup);
  unsigned int get_required_energy_min();
  unsigned int get_required_energy_min(std::vector<component*> *componentgroup);
  unsigned int get_required_fuel_min();
  unsigned int get_required_fuel_min(std::vector<component*> *componentgroup);
};
