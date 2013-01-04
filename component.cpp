#include "component.h"

component::component(componenttype *thiscomponenttype) {
  thistype = thiscomponenttype;

  timeoffailure = thistype->mtbf + rand() % thistype->mtbfvariation;
  failurestate  = componenttype::STATE_OK;
  failuremode   = componenttype::FAILURE_NONE;

  temperature = 294.15;     // 21 deg C in K
}

component::~component() {
}

