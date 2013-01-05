#include "componentlist.h"
#include "componenttype.h"
#include "civilisation.h"

componentlist::componentlist(civilisation *thisciv)
  : civ(thisciv) {
  /// Specific constructor
  typelist = new std::vector<componenttype*>;
  populate_componentlist();
}

componentlist::~componentlist() {
}

void componentlist::populate_componentlist() {
  componenttype *thiscomponent;
  thiscomponent = new componenttype(civ);
  thiscomponent->id = "engine_thermalnuclear";
  thiscomponent->name = "thermal nuclear rocket engine";
  thiscomponent->description = "In a nuclear thermal rocket a working fluid, usually liquid hydrogen, is heated to a high temperature in a nuclear reactor, and then expands through a rocket nozzle to create thrust. In this kind of thermal rocket, the nuclear reactor's energy replaces the chemical energy of the propellant's reactive chemicals in a chemical rocket. Due to the higher energy density of the nuclear fuel compared to chemical fuels, about 10^7 times, the resulting propellant efficiency (effective exhaust velocity) of the engine is at least twice as good as chemical engines.";
  thiscomponent->updatemtbf(1000, civ);
  thiscomponent->time_on      = 60 * 4;
  thiscomponent->time_off     = 60 * 16;
  thiscomponent->failuremodes = componenttype::FAILURE_NONE |
                                componenttype::FAILURE_DEACTIVATED |
                                componenttype::FAILURE_DISCONNECTED |
                                componenttype::FAILURE_LEAKING |
                                componenttype::FAILURE_NOFUEL |
                                componenttype::FAILURE_NOPOWER |
                                componenttype::FAILURE_ONFIRE |
                                componenttype::FAILURE_RANDOM |
                                componenttype::FAILURE_SLOWOFF |
                                componenttype::FAILURE_SLOWON |
                                componenttype::FAILURE_STUCKOFF |
                                componenttype::FAILURE_STUCKON |
                                componenttype::FAILURE_SURGING |
                                componenttype::FAILURE_TOGGLING |
                                componenttype::FAILURE_UNDERFUEL |
                                componenttype::FAILURE_UNDERPOWER;
  thiscomponent->vuln_mechanical     = 20;
  thiscomponent->vuln_electric       = 10;
  thiscomponent->vuln_laser          = 20;
  thiscomponent->vuln_heat           = 10;
  thiscomponent->vuln_cold           = 0;
  thiscomponent->vuln_shock          = 10;
  thiscomponent->vuln_pressure       = 30;
  thiscomponent->vuln_vacuum         = 0;
  thiscomponent->flammability        = 10;
  thiscomponent->explosiveness       = 10;
  thiscomponent->explosivepower      = 1000000; // 1 ton of TNT
  thiscomponent->required_energy     = 0;
  thiscomponent->required_fuel       = 2394;  // milligrams of fuel
  thiscomponent->required_energy_min = 0;
  thiscomponent->required_fuel_min   = 500;
  unsigned int numturbopumps = (civ->redundancy * 4 / 255) + 0.5;
  for(unsigned int i = 0; i < numturbopumps; ++i) {
    thiscomponent->parts.push_back("turbopump");
  }
  typelist->push_back(thiscomponent);

  thiscomponent = new componenttype(civ);
  thiscomponent->id = "turbopump";
  thiscomponent->name = "turbopump";
  thiscomponent->description = "A turbopump is a propellant pump that comprises basically two main components: a rotodynamic pump and a driving gas turbine, usually both mounted on the same shaft, or sometimes geared together. The purpose of a turbopump is to produce a high pressure fluid for feeding a combustion chamber or other use.";
  thiscomponent->updatemtbf(25000 * 3600, civ);
  thiscomponent->time_on      = 60;
  thiscomponent->time_off     = 120;
  thiscomponent->failuremodes = componenttype::FAILURE_NONE |
                                componenttype::FAILURE_DISCONNECTED |
                                componenttype::FAILURE_LEAKING |
                                componenttype::FAILURE_NOFUEL |
                                componenttype::FAILURE_NOPOWER |
                                componenttype::FAILURE_ONFIRE |
                                componenttype::FAILURE_SLOWON |
                                componenttype::FAILURE_STUCKOFF |
                                componenttype::FAILURE_UNDERFUEL |
                                componenttype::FAILURE_UNDERPOWER;
  thiscomponent->vuln_mechanical     = 128;
  thiscomponent->vuln_electric       = 0;
  thiscomponent->vuln_laser          = 10;
  thiscomponent->vuln_heat           = 32;
  thiscomponent->vuln_cold           = 32;
  thiscomponent->vuln_shock          = 128;
  thiscomponent->vuln_pressure       = 16;
  thiscomponent->vuln_vacuum         = 0;
  thiscomponent->flammability        = 10;
  thiscomponent->explosiveness       = 20;
  thiscomponent->explosivepower      = 1000;  // 1kg of TNT
  thiscomponent->required_energy     = 45000; // 60BHP ~= 45kW
  thiscomponent->required_fuel       = 0;
  thiscomponent->required_energy_min = 4500;  // 6BHP ~= 4.5kW
  thiscomponent->required_fuel_min   = 0;
  thiscomponent->parts.push_back("fan_impeller");
  thiscomponent->parts.push_back("fan_turbine");
  thiscomponent->parts.push_back("bearing_roller");
  thiscomponent->parts.push_back("bearing_roller");
  typelist->push_back(thiscomponent);

  thiscomponent = new componenttype(civ);
  thiscomponent->id = "fan_impeller";
  thiscomponent->name = "impeller";
  thiscomponent->description = "An impeller is a rotating component of a centrifugal pump, usually made of iron, steel, bronze, brass, aluminum or plastic, which transfers energy from the motor that drives the pump to the fluid being pumped by accelerating the fluid outwards from the center of rotation. The velocity achieved by the impeller transfers into pressure when the outward movement of the fluid is confined by the pump casing.";
  thiscomponent->updatemtbf(50000, civ);
  thiscomponent->failuremodes = componenttype::FAILURE_NONE;
  thiscomponent->vuln_mechanical     = 255;
  thiscomponent->vuln_electric       = 0;
  thiscomponent->vuln_laser          = 127;
  thiscomponent->vuln_heat           = 0;
  thiscomponent->vuln_cold           = 0;
  thiscomponent->vuln_shock          = 191;
  thiscomponent->vuln_pressure       = 0;
  thiscomponent->vuln_vacuum         = 0;
  thiscomponent->flammability        = 0;
  typelist->push_back(thiscomponent);

  thiscomponent = new componenttype(civ);
  thiscomponent->id = "fan_turbine";
  thiscomponent->name = "turbine";
  thiscomponent->description = "A turbine is a rotary mechanical device that extracts energy from a fluid flow and converts it into useful work. A turbine is a turbomachine with at least one moving part called a rotor assembly, which is a shaft or drum with blades attached. Moving fluid acts on the blades so that they move and impart rotational energy to the rotor.";
  thiscomponent->updatemtbf(50000, civ);
  thiscomponent->failuremodes = componenttype::FAILURE_NONE;
  thiscomponent->vuln_mechanical     = 192;
  thiscomponent->vuln_electric       = 0;
  thiscomponent->vuln_laser          = 63;
  thiscomponent->vuln_heat           = 0;
  thiscomponent->vuln_cold           = 0;
  thiscomponent->vuln_shock          = 127;
  thiscomponent->vuln_pressure       = 0;
  thiscomponent->vuln_vacuum         = 0;
  thiscomponent->flammability        = 0;
  typelist->push_back(thiscomponent);

  thiscomponent = new componenttype(civ);
  thiscomponent->id = "bearing_roller";
  thiscomponent->name = "roller bearing";
  thiscomponent->description = "A rolling-element bearing, also known as a rolling bearing, is a bearing which carries a load by placing round elements between two bearing rings. The relative motion of the pieces causes the round elements to roll with very little rolling resistance and with little sliding.";
  thiscomponent->updatemtbf(50000, civ);
  thiscomponent->failuremodes = componenttype::FAILURE_NONE |
                                componenttype::FAILURE_SLOWON |
                                componenttype::FAILURE_STUCKOFF |
                                componenttype::FAILURE_ONFIRE;
  thiscomponent->vuln_mechanical     = 63;
  thiscomponent->vuln_electric       = 0;
  thiscomponent->vuln_laser          = 32;
  thiscomponent->vuln_heat           = 63;
  thiscomponent->vuln_cold           = 63;
  thiscomponent->vuln_shock          = 16;
  thiscomponent->vuln_pressure       = 0;
  thiscomponent->vuln_vacuum         = 0;
  thiscomponent->flammability        = 63;
  typelist->push_back(thiscomponent);

}

componenttype *componentlist::getcomponent(std::string thisid) {
  /// Return a pointer to the component in the list with a given id
  std::vector<componenttype*>::iterator i;
  for(i = typelist->begin(); i != typelist->end(); ++i) {
    if((*i)->id.compare(thisid) == 0) {
      return *i;
    }
  }
  return NULL;
}
