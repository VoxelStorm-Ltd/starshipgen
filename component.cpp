#include "component.h"
#include "componentlist.h"
#include "componenttype.h"
#include "starship.h"
#include "randomgen.h"

component::component(componenttype *thiscomponenttype, starship *thisship) {
  thistype = thiscomponenttype;

  timeinstalled    = thisship->shipclock;
  timelastswitched = 0;   // never activated
  powercycles      = 0;
  timeoffailure    = timeinstalled + (thistype->mtbf + rand() % thistype->mtbfvariation);
  failurestate     = componenttype::STATE_OK;
  failuremode      = componenttype::FAILURE_NONE;

  temperature = 294.15;     // 21 deg C in K

  // cycle through the type's parts and populate them
  std::vector<std::string>::iterator i;
  //std::cout << "DEBUG: component is " << thistype->name << std::endl;
  for(i = thiscomponenttype->parts.begin(); i != thiscomponenttype->parts.end(); ++i) {
    componenttype *thisparttype = thisship->componenttypes->getcomponent(*i);
    if(thisparttype != NULL) {
      component *thiscomponent = new component(thisparttype, thisship);
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
