#include "componenttype.h"
#include "civilisation.h"

componenttype::componenttype(civilisation *thisciv) {
  name = "Widget";
  description = "Some generic doohickey or other";

  updatemtbf(1000, thisciv);
  time_on             = 0;
  time_off            = 0;
  failuremodes        = FAILURE_NONE;
  vuln_mechanical     = 0;
  vuln_electric       = 0;
  vuln_laser          = 0;
  vuln_heat           = 0;
  vuln_cold           = 0;
  vuln_shock          = 0;
  vuln_pressure       = 0;
  vuln_vacuum         = 0;
  flammability        = 0;
  explosiveness       = 0;
  explosivepower      = 0;
  required_energy     = 0;
  required_fuel       = 0;
  required_energy_min = 0;
  required_fuel_min   = 0;
}

componenttype::~componenttype() {
}

void componenttype::updatemtbf(uint64_t thismtbf, civilisation *thisciv) {
  mtbf          = thismtbf;
  mtbfvariation = thisciv->precision * mtbf / 127;
}
