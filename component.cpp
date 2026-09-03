#include "component.h"
#include <cstdlib>
#include <iostream>
#include "componentlist.h"
#include "starship.h"

component::component(componenttype *thiscomponenttype, starship *thisship) {
  thistype = thiscomponenttype;

  timeinstalled    = thisship->shipclock;
  timelastswitched = 0;                                                         // never activated
  powercycles      = 0;
  timeoffailure    = timeinstalled + thistype->mtbf;
  if(thistype->mtbfvariation != 0) {
    timeoffailure += std::rand() % thistype->mtbfvariation;
  }
  failurestate     = componenttype::STATE_OK;
  failuremode      = componenttype::FAILURE_NONE;

  temperature = 294.15;                                                         // 21 deg C in K

  // cycle through the type's parts and populate them
  std::vector<std::string>::iterator i;
  //std::cout << "DEBUG: component is " << thistype->name << std::endl;
  for(i = thiscomponenttype->parts.begin(); i != thiscomponenttype->parts.end(); ++i) {
    componenttype *thisparttype{thisship->componenttypes->getcomponent(*i)};
    if(thisparttype != nullptr) {
      component *thiscomponent{new component{thisparttype, thisship}};
      //std::cout << "  DEBUG: component " << thiscomponent->thistype->name << " is part of " << thistype->name << std::endl;
      parts.push_back(thiscomponent);
    } else {
      std::cout << "  ERROR: unknown component " << *i << " is part of " << thistype->name << std::endl;
    }
  }
}

component::~component() {
}

std::string component::get_adjective() {
  switch(failurestate) {
  case componenttype::STATE_OK:
    return "";
  case componenttype::STATE_WORN:
    return "worn";
  case componenttype::STATE_REDUCEDFUNCTION:
    return "glitchy";
  case componenttype::STATE_NONFUNCTIONAL:
    return "broken";
  case componenttype::STATE_REPAIRING:
    return "disassembled";
  case componenttype::STATE_DESTROYED:
    return "destroyed";
  case componenttype::STATE_ABSENT:
    return "missing";
  default:
    std::cout << "ERROR: get_adjective: unknown failure state enum " << failurestate << std::endl;
  }
  return "";
}

unsigned int component::get_component_count() {
  /// Return the recursive count of all discrete components that make up this part
  unsigned int count{0};
  for(std::vector<component*>::iterator i{parts.begin()}; i != parts.end(); ++i) {
    count += (*i)->get_component_count();
  }
  if(count == 0) {
    // if we have no children, then assume we're a discrete component
    ++count;
  }
  return count;
}

unsigned int component::get_systems_count() {
  /// Return the recursive count of all systems plus their subsystems that make up this part
  unsigned int count{1};                                                        // everything counts as 1 even if it has children
  for(std::vector<component*>::iterator i{parts.begin()}; i != parts.end(); ++i) {
    count += (*i)->get_systems_count();
  }
  return count;
}

unsigned int component::get_time_on() {
  /// Return the total time this part takes to start up, including all subparts
  unsigned int time{thistype->time_on};
  for(std::vector<component*>::iterator i{parts.begin()}; i != parts.end(); ++i) {
    unsigned int const thistime{(*i)->get_time_on()};
    if(thistime > time) {
      time = thistime;
    }
  }
  return time;
}

unsigned int component::get_time_off() {
  /// Return the total time this part takes to shut down, including all subparts
  unsigned int time{thistype->time_off};
  for(std::vector<component*>::iterator i{parts.begin()}; i != parts.end(); ++i) {
    unsigned int const thistime{(*i)->get_time_off()};
    if(thistime > time) {
      time = thistime;
    }
  }
  return time;
}

unsigned int component::get_required_energy() {
  /// Return the total energy this system and all subsystems require for optimal function
  unsigned int result{thistype->required_energy};
  for(std::vector<component*>::iterator i{parts.begin()}; i != parts.end(); ++i) {
    result += (*i)->get_required_energy();
  }
  return result;
}

unsigned int component::get_required_fuel() {
  /// Return the total fuel this system and all subsystems require for optimal function
  unsigned int result{thistype->required_fuel};
  for(std::vector<component*>::iterator i{parts.begin()}; i != parts.end(); ++i) {
    result += (*i)->get_required_fuel();
  }
  return result;
}

unsigned int component::get_required_energy_min() {
  /// Return the total energy this system and all subsystems require for minimal function
  unsigned int result{thistype->required_energy_min};
  for(std::vector<component*>::iterator i{parts.begin()}; i != parts.end(); ++i) {
    result += (*i)->get_required_energy_min();
  }
  return result;
}

unsigned int component::get_required_fuel_min() {
  /// Return the total fuel this system and all subsystems require for minimal function
  unsigned int result{thistype->required_fuel_min};
  for(std::vector<component*>::iterator i{parts.begin()}; i != parts.end(); ++i) {
    result += (*i)->get_required_fuel_min();
  }
  return result;
}
