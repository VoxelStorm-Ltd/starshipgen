#include <iostream>

#include "civilisation.h"
#include "starship.h"

using namespace std;

int main() {
  cout << "Generating civilisation..." << endl;
  civilisation *thiscivilisation = new civilisation(1337);
  cout << thiscivilisation->describe() << endl;

  starship *thisstarship = new starship(0);
  cout << thisstarship->describe() << endl;

  return 0;
}
