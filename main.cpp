#include <iostream>
#include "civilisation.h"
#include "starship.h"
#include "componentlist.h"

int main() {
  std::cout << "Generating civilisation..." << std::endl;

  // 7009, 0 ~= Qeng Ho
  unsigned int civseed  = 0;
  unsigned int shipseed = 1;

  civilisation *thisciv = new civilisation(civseed);
  std::cout << thisciv->describe() << std::endl;

  componentlist *thiscomponentlist = new componentlist(thisciv);

  starship *thisship = new starship(shipseed, thisciv, thiscomponentlist);
  std::cout << thisship->describe() << std::endl;

  return EXIT_SUCCESS;
}
