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
  thiscomponent->explosiveness       = 0;
  thiscomponent->explosivepower      = 0;
  thiscomponent->required_energy     = 0;
  thiscomponent->required_fuel       = 2394;  // milligrams of fuel
  thiscomponent->required_energy_min = 0;
  thiscomponent->required_fuel_min   = 500;
  unsigned int numturbopumps = (civ->redundancy * 4 / 255) + 0.5;
  for(unsigned int i = 0; i < numturbopumps; ++i) {
    thiscomponent->parts.push_back("turbopump");
  }
  thiscomponent->parts.push_back("nuclear_reactorcore");
  //thiscomponent->parts.push_back("nuclear_controldrum");
  //thiscomponent->parts.push_back("nuclear_reflector");
  thiscomponent->parts.push_back("armour_shield_radiation");
  thiscomponent->parts.push_back("armour_shield_radiation");
  thiscomponent->parts.push_back("engine_rocket_nozzle");
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
  thiscomponent->required_fuel       = 2394 / int((civ->redundancy * 4 / 255) + 0.5); // matching cultural redundancy factor
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

  thiscomponent = new componenttype(civ);
  thiscomponent->id = "nuclear_reactorcore";
  thiscomponent->name = "reactor core";
  thiscomponent->description = "A nuclear reactor is a device to initiate and control a sustained nuclear chain reaction. When a large fissile atomic nucleus such as uranium-235 or plutonium-239 absorbs a neutron, it may undergo nuclear fission. The heavy nucleus splits into two or more lighter nuclei (the fission products), releasing kinetic energy, gamma radiation and free neutrons. A portion of these neutrons may later be absorbed by other fissile atoms and trigger further fission events, which release more neutrons, and so on. This is known as a nuclear chain reaction.";
  thiscomponent->updatemtbf(250000, civ);
  thiscomponent->time_on      = 3600 * 12;  // 12 hours
  thiscomponent->time_off     = 30;   // rapid scramble shutdown
  thiscomponent->failuremodes = componenttype::FAILURE_NONE |
                                componenttype::FAILURE_DEACTIVATED |
                                componenttype::FAILURE_DISCONNECTED |
                                componenttype::FAILURE_LEAKING |
                                componenttype::FAILURE_ONFIRE |
                                componenttype::FAILURE_RANDOM |
                                componenttype::FAILURE_SLOWOFF |
                                componenttype::FAILURE_SLOWON |
                                componenttype::FAILURE_STUCKOFF |
                                componenttype::FAILURE_STUCKON |
                                componenttype::FAILURE_SURGING |
                                componenttype::FAILURE_TOGGLING;
  thiscomponent->vuln_mechanical     = 20;
  thiscomponent->vuln_electric       = 10;
  thiscomponent->vuln_laser          = 31;
  thiscomponent->vuln_heat           = 10;
  thiscomponent->vuln_cold           = 0;
  thiscomponent->vuln_shock          = 63;
  thiscomponent->vuln_pressure       = 63;
  thiscomponent->vuln_vacuum         = 0;
  thiscomponent->flammability        = 10;
  thiscomponent->explosiveness       = 10;
  thiscomponent->explosivepower      = 1000000; // 1 ton of TNT
  thiscomponent->required_energy     = 0;
  thiscomponent->required_fuel       = 0;
  thiscomponent->required_energy_min = 0;
  thiscomponent->required_fuel_min   = 0;
  //unsigned int numfuelbundles = 137;
  unsigned int numfuelbundles = 16;
  for(unsigned int i = 0; i < numfuelbundles; ++i) {
    thiscomponent->parts.push_back("motor_linear");
  }
  unsigned int numfuelrods = numfuelbundles * 4;
  for(unsigned int i = 0; i < numfuelrods; ++i) {
    thiscomponent->parts.push_back("nuclear_fuelrod");
    thiscomponent->parts.push_back("nuclear_controlrod");
  }
  typelist->push_back(thiscomponent);

  thiscomponent = new componenttype(civ);
  thiscomponent->id = "nuclear_fuelrod";
  thiscomponent->name = "fuel rod";
  thiscomponent->description = "Nuclear fuel is a material that can be 'burned' by nuclear fission or fusion to derive nuclear energy.  Uranium dioxide (UO2) powder is compacted to cylindrical pellets and sintered at high temperatures to produce ceramic nuclear fuel pellets with a high density and well defined physical properties and chemical composition. A grinding process is used to achieve a uniform cylindrical geometry with narrow tolerances. Such fuel pellets are then stacked and filled into zirconium alloy tubes called fuel rods.";
  thiscomponent->updatemtbf(100000, civ);
  thiscomponent->failuremodes = componenttype::FAILURE_NONE |
                                componenttype::FAILURE_DISCONNECTED |
                                componenttype::FAILURE_ONFIRE,
  thiscomponent->vuln_mechanical     = 20;
  thiscomponent->vuln_electric       = 0;
  thiscomponent->vuln_laser          = 63;
  thiscomponent->vuln_heat           = 16;
  thiscomponent->vuln_cold           = 0;
  thiscomponent->vuln_shock          = 20;
  thiscomponent->vuln_pressure       = 0;
  thiscomponent->vuln_vacuum         = 0;
  thiscomponent->flammability        = 63;
  thiscomponent->explosiveness       = 0;
  thiscomponent->explosivepower      = 0;
  typelist->push_back(thiscomponent);

  thiscomponent = new componenttype(civ);
  thiscomponent->id = "nuclear_controlrod";
  thiscomponent->name = "control rod";
  thiscomponent->description = "A control rod is a rod made of chemical elements capable of absorbing many neutrons without fissioning themselves. They are used in nuclear reactors to control the rate of fission of uranium and plutonium. Because these elements have different capture cross sections for neutrons of varying energies, the compositions of the control rods must be designed for the neutron spectrum of the reactor it is supposed to control.";
  thiscomponent->updatemtbf(1000000, civ);
  thiscomponent->failuremodes = componenttype::FAILURE_NONE |
                                componenttype::FAILURE_DISCONNECTED;
  thiscomponent->vuln_mechanical     = 20;
  thiscomponent->vuln_electric       = 0;
  thiscomponent->vuln_laser          = 63;
  thiscomponent->vuln_heat           = 16;
  thiscomponent->vuln_cold           = 0;
  thiscomponent->vuln_shock          = 20;
  thiscomponent->vuln_pressure       = 0;
  thiscomponent->vuln_vacuum         = 0;
  thiscomponent->flammability        = 63;
  thiscomponent->explosiveness       = 0;
  thiscomponent->explosivepower      = 0;
  typelist->push_back(thiscomponent);

  thiscomponent = new componenttype(civ);
  thiscomponent->id = "engine_rocket_nozzle";
  thiscomponent->name = "rocket nozzle";
  thiscomponent->description = "A rocket engine nozzle is a propelling nozzle (usually of the de Laval type) used in a rocket engine to expand and accelerate the combustion gases produced by burning propellants so that the exhaust gases exit the nozzle at hypersonic velocities.";
  thiscomponent->updatemtbf(250000, civ);
  thiscomponent->failuremodes = componenttype::FAILURE_NONE;
  thiscomponent->vuln_mechanical     = 127;
  thiscomponent->vuln_electric       = 0;
  thiscomponent->vuln_laser          = 63;
  thiscomponent->vuln_heat           = 10;
  thiscomponent->vuln_cold           = 0;
  thiscomponent->vuln_shock          = 10;
  thiscomponent->vuln_pressure       = 0;
  thiscomponent->vuln_vacuum         = 0;
  thiscomponent->flammability        = 0;
  thiscomponent->explosiveness       = 0;
  thiscomponent->explosivepower      = 0;
  typelist->push_back(thiscomponent);

  thiscomponent = new componenttype(civ);
  thiscomponent->id = "armour_shield_radiation";
  thiscomponent->name = "radiation shield";
  thiscomponent->description = "Graded-Z shielding is a laminate of several materials with different Z values (atomic numbers) designed to protect against ionizing radiation. Compared to single-material shielding, the same mass of graded-Z shielding has been shown to reduce electron penetration over 60%.  In a typical graded-Z shield, the high-Z layer effectively scatters protons and electrons. It also absorbs gamma rays, which produces X-ray fluorescence. Each subsequent layers absorbs the X-ray fluorescence of the previous material, eventually reducing the energy to a suitable level. Each decrease in energy produces bremsstrahlung and Auger electrons, which are below the detector's energy threshold.";
  thiscomponent->updatemtbf(1000000, civ);
  thiscomponent->failuremodes = componenttype::FAILURE_NONE |
                                componenttype::FAILURE_DISCONNECTED;
  thiscomponent->vuln_mechanical     = 5;
  thiscomponent->vuln_electric       = 0;
  thiscomponent->vuln_laser          = 5;
  thiscomponent->vuln_heat           = 5;
  thiscomponent->vuln_cold           = 0;
  thiscomponent->vuln_shock          = 5;
  thiscomponent->vuln_pressure       = 0;
  thiscomponent->vuln_vacuum         = 0;
  thiscomponent->flammability        = 0;
  thiscomponent->explosiveness       = 0;
  thiscomponent->explosivepower      = 0;
  typelist->push_back(thiscomponent);

  thiscomponent = new componenttype(civ);
  thiscomponent->id = "motor_linear";
  thiscomponent->name = "linear actuator";
  thiscomponent->description = "A linear actuator is an actuator that creates motion in a straight line, as contrasted with circular motion of a conventional electric motor. Linear actuators are used in machine tools and industrial machinery, in computer peripherals such as disk drives and printers, in valves and dampers, and in many other places where linear motion is required.";
  thiscomponent->updatemtbf(50000, civ);
  thiscomponent->time_on      = 2;
  thiscomponent->time_off     = 0;
  thiscomponent->failuremodes = componenttype::FAILURE_NONE |
                                componenttype::FAILURE_DISCONNECTED |
                                componenttype::FAILURE_NOPOWER |
                                componenttype::FAILURE_ONFIRE |
                                componenttype::FAILURE_SLOWOFF |
                                componenttype::FAILURE_SLOWON |
                                componenttype::FAILURE_STUCKOFF |
                                componenttype::FAILURE_STUCKON |
                                componenttype::FAILURE_TOGGLING |
                                componenttype::FAILURE_UNDERPOWER;
  thiscomponent->vuln_mechanical     = 127;
  thiscomponent->vuln_electric       = 191;
  thiscomponent->vuln_laser          = 127;
  thiscomponent->vuln_heat           = 127;
  thiscomponent->vuln_cold           = 63;
  thiscomponent->vuln_shock          = 63;
  thiscomponent->vuln_pressure       = 63;
  thiscomponent->vuln_vacuum         = 63;
  thiscomponent->flammability        = 63;
  thiscomponent->explosiveness       = 0;
  thiscomponent->explosivepower      = 0;
  thiscomponent->required_energy     = 1000;  // 1KW
  thiscomponent->required_fuel       = 0;
  thiscomponent->required_energy_min = 250;
  thiscomponent->required_fuel_min   = 0;
  typelist->push_back(thiscomponent);

  thiscomponent = new componenttype(civ);
  thiscomponent->id = "fueltank_hydrogen";
  thiscomponent->name = "liquid hydrogen tank";
  thiscomponent->description = "Liquid hydrogen (LH2 or LH2) is the liquid state of the element hydrogen. Hydrogen is found naturally in the molecular H2 form. To exist as a liquid, H2 must be cooled below hydrogen's critical point of 33 K. However, for hydrogen to be in a full liquid state without evaporating at atmospheric pressure, it needs to be cooled to 20.28K.";
  thiscomponent->updatemtbf(50000, civ);
  thiscomponent->failuremodes = componenttype::FAILURE_NONE |
                                componenttype::FAILURE_DISCONNECTED |
                                componenttype::FAILURE_ONFIRE;
  thiscomponent->vuln_mechanical     = 127;
  thiscomponent->vuln_electric       = 63;
  thiscomponent->vuln_laser          = 127;
  thiscomponent->vuln_heat           = 255;
  thiscomponent->vuln_cold           = 0;
  thiscomponent->vuln_shock          = 127;
  thiscomponent->vuln_pressure       = 0;
  thiscomponent->vuln_vacuum         = 0;
  thiscomponent->flammability        = 255;
  thiscomponent->explosiveness       = 255;
  thiscomponent->explosivepower      = 10000; // 10KG TNT
  typelist->push_back(thiscomponent);

  thiscomponent = new componenttype(civ);
  thiscomponent->id = "fueltank_oxygen";
  thiscomponent->name = "liquid oxygen tank";
  thiscomponent->description = "Liquid oxygen — abbreviated LOx, LOX or Lox in the aerospace, submarine and gas industries — is one of the physical forms of elemental oxygen. Liquid oxygen has a pale blue color and is strongly paramagnetic and can be suspended between the poles of a powerful horseshoe magnet. Liquid oxygen has a density of 1.141 g/cm^3(1.141 kg/L) and is cryogenic with a freezing point of 50.5 K (−368.77  °F; −222.65 °C) and a boiling point of 90.19 K (−297.33 °F, −182.96 °C) at 101.325 kPa (760 mmHg). Liquid oxygen has an expansion ratio of 1:861 at 20 °C (68 °F), and because of this, it is used in some commercial and military aircraft as a source of breathing oxygen.";
  thiscomponent->updatemtbf(50000, civ);
  thiscomponent->failuremodes = componenttype::FAILURE_NONE |
                                componenttype::FAILURE_DISCONNECTED |
                                componenttype::FAILURE_ONFIRE;
  thiscomponent->vuln_mechanical     = 127;
  thiscomponent->vuln_electric       = 63;
  thiscomponent->vuln_laser          = 127;
  thiscomponent->vuln_heat           = 255;
  thiscomponent->vuln_cold           = 0;
  thiscomponent->vuln_shock          = 127;
  thiscomponent->vuln_pressure       = 0;
  thiscomponent->vuln_vacuum         = 0;
  thiscomponent->flammability        = 255;
  thiscomponent->explosiveness       = 255;
  thiscomponent->explosivepower      = 10000; // 10KG TNT
  typelist->push_back(thiscomponent);

  thiscomponent = new componenttype(civ);
  thiscomponent->id = "fueltank_argon";
  thiscomponent->name = "liquid argon tank";
  thiscomponent->description = "Argon is a chemical element with symbol Ar and atomic number 18. It is in group 18 (noble gases) of the periodic table. Argon is the third most common gas in the Earth's atmosphere, at 0.93% (9,300 ppm), making it approximately 23.8 times as abundant as next most common atmospheric gas, carbon dioxide (390 ppm), and more than 500 times as abundant as the next most common noble gas, neon (18 ppm). Nearly all of this argon is radiogenic argon-40 derived from the decay of potassium-40 in the Earth's crust. In the universe, argon-36 is by far the most common argon isotope, being the preferred argon isotope produced by stellar nucleosynthesis in supernovas.";
  thiscomponent->updatemtbf(50000, civ);
  thiscomponent->failuremodes = componenttype::FAILURE_NONE |
                                componenttype::FAILURE_DISCONNECTED;;
  thiscomponent->vuln_mechanical     = 127;
  thiscomponent->vuln_electric       = 0;
  thiscomponent->vuln_laser          = 127;
  thiscomponent->vuln_heat           = 255;
  thiscomponent->vuln_cold           = 0;
  thiscomponent->vuln_shock          = 127;
  thiscomponent->vuln_pressure       = 0;
  thiscomponent->vuln_vacuum         = 0;
  thiscomponent->flammability        = 0;
  thiscomponent->explosiveness       = 63;
  thiscomponent->explosivepower      = 1000; // 1KG TNT
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
  std::cout << "WARNING: getcomponent request for " << thisid << " returned NULL" << std::endl;
  return NULL;
}
