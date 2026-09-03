#include "randomgen.h"
#include <boost/random/discrete_distribution.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/uniform_smallint.hpp>

randomgenerator::randomgenerator(unsigned int const seed) {
  gen.seed(seed);
}

bool randomgenerator::random_bool() {
  boost::random::uniform_smallint<> randomdist{0, 1};
  return randomdist(gen);
}

bool randomgenerator::random_bool_weighted(double const weight_true) {
  double const probabilities[2]{1 - weight_true, weight_true};
  boost::random::discrete_distribution<> randomdist{probabilities};
  return randomdist(gen);
}

char randomgenerator::random_char() {
  boost::random::uniform_smallint<> randomdist{-127, 127};
  return randomdist(gen);
}
char randomgenerator::random_char_normal() {
  boost::random::normal_distribution<> randomdist{0.0, 64.0};
  double thisresult{randomdist(gen)};
  if(thisresult > 127) {
    thisresult = 127;
  } else if(thisresult < -127) {
    thisresult = -127;
  }
  return thisresult;
}
char randomgenerator::random_char_normal_biased(char const bias) {
  boost::random::normal_distribution<> randomdist{static_cast<double>(bias), 64.0};
  double thisresult{randomdist(gen)};
  if(thisresult > 127) {
    thisresult = 127;
  } else if(thisresult < -127) {
    thisresult = -127;
  }
  return thisresult;
}

unsigned char randomgenerator::random_uchar() {
  boost::random::uniform_smallint<> randomdist{0, 255};
  return randomdist(gen);
}
unsigned char randomgenerator::random_uchar_normal() {
  boost::random::normal_distribution<> randomdist{127.0, 64.0};
  double thisresult{randomdist(gen)};
  if(thisresult > 255) {
    thisresult = 255;
  } else if(thisresult < 0) {
    thisresult = 0;
  }
  return thisresult;
}
unsigned char randomgenerator::random_uchar_normal_biased(unsigned char const bias) {
  boost::random::normal_distribution<> randomdist{static_cast<double>(bias), 64.0};
  double thisresult{randomdist(gen)};
  if(thisresult > 255) {
    thisresult = 255;
  } else if(thisresult < 0) {
    thisresult = 0;
  }
  return thisresult;
}

char randomgenerator::pick_one(char const c1, char const c2) {
  boost::random::uniform_smallint<> randomdist{1, 2};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  }
  return c1;
}
char randomgenerator::pick_one(char const c1, char const c2, char const c3) {
  boost::random::uniform_smallint<> randomdist{1, 3};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  }
  return c1;
}
char randomgenerator::pick_one(char const c1, char const c2, char const c3, char const c4) {
  boost::random::uniform_smallint<> randomdist{1, 4};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  }
  return c1;
}
char randomgenerator::pick_one(char const c1, char const c2, char const c3, char const c4, char const c5) {
  boost::random::uniform_smallint<> randomdist{1, 5};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  }
  return c1;
}
char randomgenerator::pick_one(char const c1, char const c2, char const c3, char const c4, char const c5, char const c6) {
  boost::random::uniform_smallint<> randomdist{1, 6};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  case 6:
    return c6;
  }
  return c1;
}
char randomgenerator::pick_one(char const c1, char const c2, char const c3, char const c4, char const c5, char const c6, char const c7) {
  boost::random::uniform_smallint<> randomdist{1, 7};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  case 6:
    return c6;
  case 7:
    return c7;
  }
  return c1;
}
char randomgenerator::pick_one(char const c1, char const c2, char const c3, char const c4, char const c5, char const c6, char const c7, char const c8) {
  boost::random::uniform_smallint<> randomdist{1, 8};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  case 6:
    return c6;
  case 7:
    return c7;
  case 8:
    return c8;
  }
  return c1;
}
char randomgenerator::pick_one(char const c1, char const c2, char const c3, char const c4, char const c5, char const c6, char const c7, char const c8, char const c9) {
  boost::random::uniform_smallint<> randomdist{1, 9};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  case 6:
    return c6;
  case 7:
    return c7;
  case 8:
    return c8;
  case 9:
    return c9;
  }
  return c1;
}
char randomgenerator::pick_one(char const c1, char const c2, char const c3, char const c4, char const c5, char const c6, char const c7, char const c8, char const c9, char const c10) {
  boost::random::uniform_smallint<> randomdist{1, 10};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  case 6:
    return c6;
  case 7:
    return c7;
  case 8:
    return c8;
  case 9:
    return c9;
  case 10:
    return c10;
  }
  return c1;
}

unsigned char randomgenerator::pick_one(unsigned char const c1, unsigned char const c2) {
  boost::random::uniform_smallint<> randomdist{1, 2};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  }
  return c1;
}
unsigned char randomgenerator::pick_one(unsigned char const c1, unsigned char const c2, unsigned char const c3) {
  boost::random::uniform_smallint<> randomdist{1, 3};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  }
  return c1;
}
unsigned char randomgenerator::pick_one(unsigned char const c1, unsigned char const c2, unsigned char const c3, unsigned char const c4) {
  boost::random::uniform_smallint<> randomdist{1, 4};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  }
  return c1;
}
unsigned char randomgenerator::pick_one(unsigned char const c1, unsigned char const c2, unsigned char const c3, unsigned char const c4, unsigned char const c5) {
  boost::random::uniform_smallint<> randomdist{1, 5};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  }
  return c1;
}
unsigned char randomgenerator::pick_one(unsigned char const c1, unsigned char const c2, unsigned char const c3, unsigned char const c4, unsigned char const c5, unsigned char const c6) {
  boost::random::uniform_smallint<> randomdist{1, 6};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  case 6:
    return c6;
  }
  return c1;
}
unsigned char randomgenerator::pick_one(unsigned char const c1, unsigned char const c2, unsigned char const c3, unsigned char const c4, unsigned char const c5, unsigned char const c6, unsigned char const c7) {
  boost::random::uniform_smallint<> randomdist{1, 7};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  case 6:
    return c6;
  case 7:
    return c7;
  }
  return c1;
}
unsigned char randomgenerator::pick_one(unsigned char const c1, unsigned char const c2, unsigned char const c3, unsigned char const c4, unsigned char const c5, unsigned char const c6, unsigned char const c7, unsigned char const c8) {
  boost::random::uniform_smallint<> randomdist{1, 8};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  case 6:
    return c6;
  case 7:
    return c7;
  case 8:
    return c8;
  }
  return c1;
}
unsigned char randomgenerator::pick_one(unsigned char const c1, unsigned char const c2, unsigned char const c3, unsigned char const c4, unsigned char const c5, unsigned char const c6, unsigned char const c7, unsigned char const c8, unsigned char const c9) {
  boost::random::uniform_smallint<> randomdist{1, 9};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  case 6:
    return c6;
  case 7:
    return c7;
  case 8:
    return c8;
  case 9:
    return c9;
  }
  return c1;
}
unsigned char randomgenerator::pick_one(unsigned char const c1, unsigned char const c2, unsigned char const c3, unsigned char const c4, unsigned char const c5, unsigned char const c6, unsigned char const c7, unsigned char const c8, unsigned char const c9, unsigned char const c10) {
  boost::random::uniform_smallint<> randomdist{1, 10};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  case 6:
    return c6;
  case 7:
    return c7;
  case 8:
    return c8;
  case 9:
    return c9;
  case 10:
    return c10;
  }
  return c1;
}

int randomgenerator::pick_one(int const c1, int const c2) {
  boost::random::uniform_smallint<> randomdist{1, 2};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  }
  return c1;
}
int randomgenerator::pick_one(int const c1, int const c2, int const c3) {
  boost::random::uniform_smallint<> randomdist{1, 3};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  }
  return c1;
}
int randomgenerator::pick_one(int const c1, int const c2, int const c3, int const c4) {
  boost::random::uniform_smallint<> randomdist{1, 4};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  }
  return c1;
}
int randomgenerator::pick_one(int const c1, int const c2, int const c3, int const c4, int const c5) {
  boost::random::uniform_smallint<> randomdist{1, 5};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  }
  return c1;
}
int randomgenerator::pick_one(int const c1, int const c2, int const c3, int const c4, int const c5, int const c6) {
  boost::random::uniform_smallint<> randomdist{1, 6};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  case 6:
    return c6;
  }
  return c1;
}
int randomgenerator::pick_one(int const c1, int const c2, int const c3, int const c4, int const c5, int const c6, int const c7) {
  boost::random::uniform_smallint<> randomdist{1, 7};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  case 6:
    return c6;
  case 7:
    return c7;
  }
  return c1;
}
int randomgenerator::pick_one(int const c1, int const c2, int const c3, int const c4, int const c5, int const c6, int const c7, int const c8) {
  boost::random::uniform_smallint<> randomdist{1, 8};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  case 6:
    return c6;
  case 7:
    return c7;
  case 8:
    return c8;
  }
  return c1;
}
int randomgenerator::pick_one(int const c1, int const c2, int const c3, int const c4, int const c5, int const c6, int const c7, int const c8, int const c9) {
  boost::random::uniform_smallint<> randomdist{1, 9};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  case 6:
    return c6;
  case 7:
    return c7;
  case 8:
    return c8;
  case 9:
    return c9;
  }
  return c1;
}
int randomgenerator::pick_one(int const c1, int const c2, int const c3, int const c4, int const c5, int const c6, int const c7, int const c8, int const c9, int const c10) {
  boost::random::uniform_smallint<> randomdist{1, 10};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  case 6:
    return c6;
  case 7:
    return c7;
  case 8:
    return c8;
  case 9:
    return c9;
  case 10:
    return c10;
  }
  return c1;
}

unsigned int randomgenerator::pick_one(unsigned int const c1, unsigned int const c2) {
  boost::random::uniform_smallint<> randomdist{1, 2};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  }
  return c1;
}
unsigned int randomgenerator::pick_one(unsigned int const c1, unsigned int const c2, unsigned int const c3) {
  boost::random::uniform_smallint<> randomdist{1, 3};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  }
  return c1;
}
unsigned int randomgenerator::pick_one(unsigned int const c1, unsigned int const c2, unsigned int const c3, unsigned int const c4) {
  boost::random::uniform_smallint<> randomdist{1, 4};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  }
  return c1;
}
unsigned int randomgenerator::pick_one(unsigned int const c1, unsigned int const c2, unsigned int const c3, unsigned int const c4, unsigned int const c5) {
  boost::random::uniform_smallint<> randomdist{1, 5};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  }
  return c1;
}
unsigned int randomgenerator::pick_one(unsigned int const c1, unsigned int const c2, unsigned int const c3, unsigned int const c4, unsigned int const c5, unsigned int const c6) {
  boost::random::uniform_smallint<> randomdist{1, 6};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  case 6:
    return c6;
  }
  return c1;
}
unsigned int randomgenerator::pick_one(unsigned int const c1, unsigned int const c2, unsigned int const c3, unsigned int const c4, unsigned int const c5, unsigned int const c6, unsigned int const c7) {
  boost::random::uniform_smallint<> randomdist{1, 7};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  case 6:
    return c6;
  case 7:
    return c7;
  }
  return c1;
}
unsigned int randomgenerator::pick_one(unsigned int const c1, unsigned int const c2, unsigned int const c3, unsigned int const c4, unsigned int const c5, unsigned int const c6, unsigned int const c7, unsigned int const c8) {
  boost::random::uniform_smallint<> randomdist{1, 8};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  case 6:
    return c6;
  case 7:
    return c7;
  case 8:
    return c8;
  }
  return c1;
}
unsigned int randomgenerator::pick_one(unsigned int const c1, unsigned int const c2, unsigned int const c3, unsigned int const c4, unsigned int const c5, unsigned int const c6, unsigned int const c7, unsigned int const c8, unsigned int const c9) {
  boost::random::uniform_smallint<> randomdist{1, 9};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  case 6:
    return c6;
  case 7:
    return c7;
  case 8:
    return c8;
  case 9:
    return c9;
  }
  return c1;
}
unsigned int randomgenerator::pick_one(unsigned int const c1, unsigned int const c2, unsigned int const c3, unsigned int const c4, unsigned int const c5, unsigned int const c6, unsigned int const c7, unsigned int const c8, unsigned int const c9, unsigned int const c10) {
  boost::random::uniform_smallint<> randomdist{1, 10};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  case 6:
    return c6;
  case 7:
    return c7;
  case 8:
    return c8;
  case 9:
    return c9;
  case 10:
    return c10;
  }
  return c1;
}

std::string randomgenerator::pick_one(std::string const c1, std::string const c2) {
  boost::random::uniform_smallint<> randomdist{1, 2};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  }
  return c1;
}
std::string randomgenerator::pick_one(std::string const c1, std::string const c2, std::string const c3) {
  boost::random::uniform_smallint<> randomdist{1, 3};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  }
  return c1;
}
std::string randomgenerator::pick_one(std::string const c1, std::string const c2, std::string const c3, std::string const c4) {
  boost::random::uniform_smallint<> randomdist{1, 4};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  }
  return c1;
}
std::string randomgenerator::pick_one(std::string const c1, std::string const c2, std::string const c3, std::string const c4, std::string const c5) {
  boost::random::uniform_smallint<> randomdist{1, 5};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  }
  return c1;
}
std::string randomgenerator::pick_one(std::string const c1, std::string const c2, std::string const c3, std::string const c4, std::string const c5, std::string const c6) {
  boost::random::uniform_smallint<> randomdist{1, 6};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  case 6:
    return c6;
  }
  return c1;
}
std::string randomgenerator::pick_one(std::string const c1, std::string const c2, std::string const c3, std::string const c4, std::string const c5, std::string const c6, std::string const c7) {
  boost::random::uniform_smallint<> randomdist{1, 7};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  case 6:
    return c6;
  case 7:
    return c7;
  }
  return c1;
}
std::string randomgenerator::pick_one(std::string const c1, std::string const c2, std::string const c3, std::string const c4, std::string const c5, std::string const c6, std::string const c7, std::string const c8) {
  boost::random::uniform_smallint<> randomdist{1, 8};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  case 6:
    return c6;
  case 7:
    return c7;
  case 8:
    return c8;
  }
  return c1;
}
std::string randomgenerator::pick_one(std::string const c1, std::string const c2, std::string const c3, std::string const c4, std::string const c5, std::string const c6, std::string const c7, std::string const c8, std::string const c9) {
  boost::random::uniform_smallint<> randomdist{1, 9};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  case 6:
    return c6;
  case 7:
    return c7;
  case 8:
    return c8;
  case 9:
    return c9;
  }
  return c1;
}
std::string randomgenerator::pick_one(std::string const c1, std::string const c2, std::string const c3, std::string const c4, std::string const c5, std::string const c6, std::string const c7, std::string const c8, std::string const c9, std::string const c10) {
  boost::random::uniform_smallint<> randomdist{1, 10};
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  case 3:
    return c3;
  case 4:
    return c4;
  case 5:
    return c5;
  case 6:
    return c6;
  case 7:
    return c7;
  case 8:
    return c8;
  case 9:
    return c9;
  case 10:
    return c10;
  }
  return c1;
}
