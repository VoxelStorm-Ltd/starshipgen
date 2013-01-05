#include <iostream>

#include "civilisation.h"
#include "starship.h"

#include "componentlist.h"

using namespace std;

int main() {
  cout << "Generating civilisation..." << endl;

  // 7009, 0 ~= Qeng Ho
  unsigned int civseed  = 108;
  unsigned int shipseed = 0;

  civilisation *thisciv = new civilisation(civseed);
  cout << thisciv->describe() << endl;

  componentlist *thiscomponentlist = new componentlist(thisciv);

  starship *thisship = new starship(shipseed, thisciv, thiscomponentlist);
  cout << thisship->describe() << endl;

  return 0;
}
