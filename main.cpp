#include <cstdlib>
#include <iostream>
#include <random>
#include <boost/program_options.hpp>
#include "civilisation.h"
#include "componentlist.h"
#include "starship.h"

auto main(int argc, char *argv[])->int {
  /// Parse seed options, generate a civilisation and starship, and describe them
  unsigned int civseed{ 0};
  unsigned int shipseed{0};

  // 7009, 0 ~= Qeng Ho
  boost::program_options::options_description options{"Options"};
  options.add_options()
    ("help,h", "show this help message")
    ("civ-seed,c", boost::program_options::value<unsigned int>(&civseed), "civilisation seed")
    ("ship-seed,s", boost::program_options::value<unsigned int>(&shipseed), "starship seed");

  boost::program_options::variables_map arguments;
  try {
    boost::program_options::store(
      boost::program_options::parse_command_line(argc, argv, options), arguments);

    if(arguments.count("help")) {
      std::cout << "Usage: starshipgen [options]" << std::endl << std::endl << options;
      return EXIT_SUCCESS;
    }

    boost::program_options::notify(arguments);
  } catch(boost::program_options::error const &error) {
    std::cerr << "ERROR: invalid command line: " << error.what() << std::endl << std::endl << options;
    return EXIT_FAILURE;
  }

  if(!arguments.count("civ-seed") || !arguments.count("ship-seed")) {
    std::random_device random;
    if(!arguments.count("civ-seed")) {
      civseed = random();
    }
    if(!arguments.count("ship-seed")) {
      shipseed = random();
    }
  }

  std::cout << "Generating civilisation with civ seed " << civseed
            << " and ship seed " << shipseed << "..." << std::endl;

  civilisation *thisciv{new civilisation{civseed}};
  std::cout << thisciv->describe() << std::endl;

  componentlist *thiscomponentlist{new componentlist{thisciv}};

  starship *thisship{new starship{shipseed, thisciv, thiscomponentlist}};
  std::cout << thisship->describe() << std::endl;

  return EXIT_SUCCESS;
}
