#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED

#include <vector>
#include "componenttype.h"

class component {
public:
  std::vector<component*> parts;    // its constituent component parts

  uint64_t timeoffailure;    // actual time on ship's clock when this component will fail
  componenttype::state failurestate;      // what failure state we're in right now
  componenttype::failuremode failuremode; // what failure modes have occurred, if any

  double temperature;   // in kelvin

  component();
  ~component();
};

#endif // COMPONENT_H_INCLUDED
