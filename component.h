#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED

#include <vector>
#include <string>
#include "componenttype.h"
class starship;

class component {
public:
  componenttype *thistype;          // what sort of component it is
  starship *thisship;               // what ship it belongs to

  std::vector<component*> parts;    // its constituent component parts

  uint64_t timeinstalled;     // actual time on ship's clock when this was installed
  uint64_t timeoffailure;     // actual time on ship's clock when this component will fail
  uint64_t powercycles;       // how many individual times it's been turned on
  uint64_t timelastswitched;  // actual time on ship's clock when it was last toggled on/off
  bool switchedon;            // is it activated right now?
  componenttype::state failurestate;      // what failure state we're in right now
  componenttype::failuremode failuremode; // what failure modes have occurred, if any

  double temperature;   // in kelvin

  component(componenttype *thiscomponenttype, starship *thisship);
  ~component();

  std::string get_adjective();
};

#endif // COMPONENT_H_INCLUDED
