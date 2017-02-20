#ifndef STARSHIP_H_INCLUDED
#define STARSHIP_H_INCLUDED

#include <vector>
#include <string>
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
    PROPULSION_FUSION,                                                          // Fusion rocket (star trek impulse)
    PROPULSION_FISSION,                                                         // Fission rocket
    PROPULSION_FUSIONTHERMAL,                                                   // Fusion thermal rocket
    PROPULSION_FISSIONTHERMAL,                                                  // Fission thermal rocket
    PROPULSION_FISSIONFRAGMENT,                                                 // Fission-fragment rocket
    PROPULSION_CHEMICAL,                                                        // Chemical rocket
    PROPULSION_ANTIMATTER,                                                      // Antimatter rocket
    PROPULSION_ION,                                                             // Ion thruster
    PROPULSION_RAMSCOOP,                                                        // Ramscoop (fire upon the deep ramscoops)
    PROPULSION_SAIL,                                                            // Light sails
    PROPULSION_VASIMR,                                                          // VASIMR
    PROPULSION_ANTIMATTERFUSION,                                                // Antimatter catalyzed nuclear pulse
    PROPULSION_WARPBUBBLE,                                                      // Space distortion bubble generator (star trek warp)
    PROPULSION_HYPERDRIVE,                                                      // Hyperdrive (star wars hyperdrive0
    PROPULSION_JUMPFINS,                                                        // Jump fins (fire upon the deep jump drive)
    PROPULSION_WITCHSPACE,                                                      // Witchspace drive (elite hyperspace jump)
    PROPULSION_WORMHOLE,                                                        // Wormholes (star trek wormholes)
    PROPULSION_WARPGATE                                                         // Warp gates (cowboy bebop warp gates)
  };

  enum energysourcetype {
    ENERGY_FISSIONREACTOR,                                                      // Nuclear fission reactor
    ENERGY_FUSIONREACTOR,                                                       // Nuclear fusion reactor
    ENERGY_BATTERY,                                                             // Electrical battery
    ENERGY_ANTIMATTERREACTOR,                                                   // Matter/antimatter reactor
    ENERGY_SOLARPANEL,                                                          // Solar panel
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

  // pointers to specific ship components:
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

#endif // STARSHIP_H_INCLUDED
