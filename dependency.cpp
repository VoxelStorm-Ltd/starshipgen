#include "dependency.h"

dependency::dependency() {
}

dependency::~dependency() {
}

void dependency::add_conduit() {
}

bool dependency::check_conduit() {
  return true;
}

std::vector<component*> dependency::get_broken_conduits() {
  std::vector<component*> componentlist;
  return componentlist;
}
