#include <iostream>

#include "civilisation.h"
#include "starship.h"

using namespace std;

int main() {
  cout << "Generating civilisation..." << endl;
  civilisation *thisciv = new civilisation(0);
  cout << thisciv->describe() << endl;

  std::vector<componenttype> componenttypelist;

  starship *thisship = new starship(2, thisciv, componenttypelist);
  cout << thisship->describe() << endl;

  return 0;
}
