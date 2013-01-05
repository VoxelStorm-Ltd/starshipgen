#include "component.h"
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
