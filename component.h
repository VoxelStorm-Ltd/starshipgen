#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED

#include <vector>

class component {
public:
  std::vector<component*> parts;    // its constituent component parts

  component();
  ~component();
};

#endif // COMPONENT_H_INCLUDED
