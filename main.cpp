#include <iostream>

#include "civilisation.h"
#include "starship.h"

#include "componentlist.h"

using namespace std;

int main() {
  cout << "Generating civilisation..." << endl;
  civilisation *thisciv = new civilisation(1);
  cout << thisciv->describe() << endl;

  std::vector<componenttype*> componenttypelist;
  populate_componentlist(componenttypelist, thisciv);

  starship *thisship = new starship(2, thisciv, componenttypelist);
  cout << thisship->describe() << endl;

  return 0;
}
