#include <iostream>

#include "civilisation.h"

using namespace std;

int main() {
  cout << "Generating civilisation..." << endl;
  civilisation *thiscivilisation = new civilisation(1337);
  cout << thiscivilisation->describe() << endl;

  return 0;
}
