#include <iostream>

#include "civilisation.h"
#include "starship.h"

#include "componentlist.h"

using namespace std;

int main() {
  cout << "Generating civilisation..." << endl;
  civilisation *thisciv = new civilisation(1);
  cout << thisciv->describe() << endl;

  componentlist *thiscomponentlist = new componentlist(thisciv);

  starship *thisship = new starship(4, thisciv, thiscomponentlist);
  cout << thisship->describe() << endl;

  return 0;
}
