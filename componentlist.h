#ifndef COMPONENTLIST_H_INCLUDED
#define COMPONENTLIST_H_INCLUDED

#include <vector>
#include "componenttype.h"
// This file must NOT be included by any other in-project files

void populate_componentlist(std::vector<componenttype*> componenttypelist, civilisation *thisciv) {
  componenttype *thiscomponent;
  thiscomponent = new componenttype(thisciv);
  thiscomponent->name = "Thermal nuclear rocket engine";
  thiscomponent->description = "In a nuclear thermal rocket a working fluid, usually liquid hydrogen, is heated to a high temperature in a nuclear reactor, and then expands through a rocket nozzle to create thrust. In this kind of thermal rocket, the nuclear reactor's energy replaces the chemical energy of the propellant's reactive chemicals in a chemical rocket. Due to the higher energy density of the nuclear fuel compared to chemical fuels, about 10^7 times, the resulting propellant efficiency (effective exhaust velocity) of the engine is at least twice as good as chemical engines.";
  thiscomponent->updatemtbf(1000, thisciv);
  thiscomponent->time_on             = 60 * 4;
  thiscomponent->time_off            = 60 * 16;
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
  componenttypelist.push_back(thiscomponent);
}

#endif // COMPONENTLIST_H_INCLUDED
