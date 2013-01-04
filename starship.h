#ifndef STARSHIP_H_INCLUDED
#define STARSHIP_H_INCLUDED

#include <string>
#include "randomgen.h"

class starship {
public:
  randomgenerator *randomgen;

  starship(unsigned int seed);
  ~starship();
  std::string describe();
};

#endif // STARSHIP_H_INCLUDED
