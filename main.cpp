#include <cstdlib>
#include <iostream>

#include <boost/program_options.hpp>

#include "civilisation.h"
#include "componentlist.h"
#include "starship.h"

int main(int argc, char *argv[]) {
  unsigned int civseed  = 0;
  unsigned int shipseed = 1;

  // 7009, 0 ~= Qeng Ho
  boost::program_options::options_description options("Options");
  options.add_options()
    ("help,h", "show this help message")
    ("civ-seed,c", boost::program_options::value<unsigned int>(&civseed)->default_value(civseed),
      "civilisation seed")
    ("ship-seed,s", boost::program_options::value<unsigned int>(&shipseed)->default_value(shipseed),
      "starship seed");

  boost::program_options::variables_map arguments;
  try {
    boost::program_options::store(
      boost::program_options::parse_command_line(argc, argv, options), arguments);

    if(arguments.count("help")) {
      std::cout << "Usage: starshipgen [options]\n\n" << options;
      return EXIT_SUCCESS;
    }

    boost::program_options::notify(arguments);
  } catch(const boost::program_options::error &error) {
    std::cerr << "Error: " << error.what() << "\n\n" << options;
    return EXIT_FAILURE;
  }

  std::cout << "Generating civilisation..." << std::endl;

  civilisation *thisciv = new civilisation(civseed);
  std::cout << thisciv->describe() << std::endl;

  componentlist *thiscomponentlist = new componentlist(thisciv);

  starship *thisship = new starship(shipseed, thisciv, thiscomponentlist);
  std::cout << thisship->describe() << std::endl;

  return EXIT_SUCCESS;
}
