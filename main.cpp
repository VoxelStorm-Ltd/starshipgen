#include <iostream>

#include "civilisation.h"
#include "starship.h"

using namespace std;

int main() {
  cout << "Generating civilisation..." << endl;
  civilisation *thisciv = new civilisation(0);
  cout << thisciv->describe() << endl;

  starship *thisship = new starship(4, thisciv);
  cout << thisship->describe() << endl;

  return 0;
}
