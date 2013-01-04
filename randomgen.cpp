#include "randomgen.h"
#include <boost/random/uniform_smallint.hpp>
#include <boost/random/discrete_distribution.hpp>
#include <boost/random/normal_distribution.hpp>

randomgenerator::randomgenerator(unsigned int seed) {
  gen.seed(seed);
}

bool randomgenerator::random_bool() {
  boost::random::uniform_smallint<> randomdist(0, 1);
  return randomdist(gen);
}

bool randomgenerator::random_bool_weighted(double weight_true) {
  double probabilities[2];
  probabilities[1] = weight_true;
  probabilities[0] = 1 - probabilities[1];
  boost::random::discrete_distribution<> randomdist(probabilities);
  return randomdist(gen);
}

char randomgenerator::random_char() {
  boost::random::uniform_smallint<> randomdist(-127, 127);
  return randomdist(gen);
}
char randomgenerator::random_char_normal() {
  boost::random::normal_distribution<> randomdist(0.0, 64.0);
  double thisresult = randomdist(gen);
  if(thisresult > 127) {
    thisresult = 127;
  } else if(thisresult < -127) {
    thisresult = -127;
  }
  return thisresult;
}
char randomgenerator::random_char_normal_biased(char bias) {
  boost::random::normal_distribution<> randomdist(bias, 64.0);
  double thisresult = randomdist(gen);
  if(thisresult > 127) {
    thisresult = 127;
  } else if(thisresult < -127) {
    thisresult = -127;
  }
  return thisresult;
}

unsigned char randomgenerator::random_uchar() {
  boost::random::uniform_smallint<> randomdist(0, 255);
  return randomdist(gen);
}
unsigned char randomgenerator::random_uchar_normal() {
  boost::random::normal_distribution<> randomdist(127.0, 64.0);
  double thisresult = randomdist(gen);
  if(thisresult > 255) {
    thisresult = 255;
  } else if(thisresult < 0) {
    thisresult = 0;
  }
  return thisresult;
}
unsigned char randomgenerator::random_uchar_normal_biased(unsigned char bias) {
  boost::random::normal_distribution<> randomdist(bias, 64.0);
  double thisresult = randomdist(gen);
  if(thisresult > 255) {
    thisresult = 255;
  } else if(thisresult < 0) {
    thisresult = 0;
  }
  return thisresult;
}

char randomgenerator::pick_one(char c1, char c2) {
  boost::random::uniform_smallint<> randomdist(1, 2);
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  }
  return c1;
}
char randomgenerator::pick_one(char c1, char c2, char c3) {
  boost::random::uniform_smallint<> randomdist(1, 3);
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
char randomgenerator::pick_one(char c1, char c2, char c3, char c4) {
  boost::random::uniform_smallint<> randomdist(1, 4);
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
char randomgenerator::pick_one(char c1, char c2, char c3, char c4, char c5) {
  boost::random::uniform_smallint<> randomdist(1, 5);
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
char randomgenerator::pick_one(char c1, char c2, char c3, char c4, char c5, char c6) {
  boost::random::uniform_smallint<> randomdist(1, 6);
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
char randomgenerator::pick_one(char c1, char c2, char c3, char c4, char c5, char c6, char c7) {
  boost::random::uniform_smallint<> randomdist(1, 7);
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
char randomgenerator::pick_one(char c1, char c2, char c3, char c4, char c5, char c6, char c7, char c8) {
  boost::random::uniform_smallint<> randomdist(1, 8);
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
char randomgenerator::pick_one(char c1, char c2, char c3, char c4, char c5, char c6, char c7, char c8, char c9) {
  boost::random::uniform_smallint<> randomdist(1, 9);
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
char randomgenerator::pick_one(char c1, char c2, char c3, char c4, char c5, char c6, char c7, char c8, char c9, char c10) {
  boost::random::uniform_smallint<> randomdist(1, 10);
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

unsigned char randomgenerator::pick_one(unsigned char c1, unsigned char c2) {
  boost::random::uniform_smallint<> randomdist(1, 2);
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  }
  return c1;
}
unsigned char randomgenerator::pick_one(unsigned char c1, unsigned char c2, unsigned char c3) {
  boost::random::uniform_smallint<> randomdist(1, 3);
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
unsigned char randomgenerator::pick_one(unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4) {
  boost::random::uniform_smallint<> randomdist(1, 4);
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
unsigned char randomgenerator::pick_one(unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4, unsigned char c5) {
  boost::random::uniform_smallint<> randomdist(1, 5);
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
unsigned char randomgenerator::pick_one(unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4, unsigned char c5, unsigned char c6) {
  boost::random::uniform_smallint<> randomdist(1, 6);
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
unsigned char randomgenerator::pick_one(unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4, unsigned char c5, unsigned char c6, unsigned char c7) {
  boost::random::uniform_smallint<> randomdist(1, 7);
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
unsigned char randomgenerator::pick_one(unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4, unsigned char c5, unsigned char c6, unsigned char c7, unsigned char c8) {
  boost::random::uniform_smallint<> randomdist(1, 8);
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
unsigned char randomgenerator::pick_one(unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4, unsigned char c5, unsigned char c6, unsigned char c7, unsigned char c8, unsigned char c9) {
  boost::random::uniform_smallint<> randomdist(1, 9);
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
unsigned char randomgenerator::pick_one(unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4, unsigned char c5, unsigned char c6, unsigned char c7, unsigned char c8, unsigned char c9, unsigned char c10) {
  boost::random::uniform_smallint<> randomdist(1, 10);
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

int randomgenerator::pick_one(int c1, int c2) {
  boost::random::uniform_smallint<> randomdist(1, 2);
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  }
  return c1;
}
int randomgenerator::pick_one(int c1, int c2, int c3) {
  boost::random::uniform_smallint<> randomdist(1, 3);
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
int randomgenerator::pick_one(int c1, int c2, int c3, int c4) {
  boost::random::uniform_smallint<> randomdist(1, 4);
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
int randomgenerator::pick_one(int c1, int c2, int c3, int c4, int c5) {
  boost::random::uniform_smallint<> randomdist(1, 5);
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
int randomgenerator::pick_one(int c1, int c2, int c3, int c4, int c5, int c6) {
  boost::random::uniform_smallint<> randomdist(1, 6);
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
int randomgenerator::pick_one(int c1, int c2, int c3, int c4, int c5, int c6, int c7) {
  boost::random::uniform_smallint<> randomdist(1, 7);
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
int randomgenerator::pick_one(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8) {
  boost::random::uniform_smallint<> randomdist(1, 8);
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
int randomgenerator::pick_one(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, int c9) {
  boost::random::uniform_smallint<> randomdist(1, 9);
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
int randomgenerator::pick_one(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, int c9, int c10) {
  boost::random::uniform_smallint<> randomdist(1, 10);
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

unsigned int randomgenerator::pick_one(unsigned int c1, unsigned int c2) {
  boost::random::uniform_smallint<> randomdist(1, 2);
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  }
  return c1;
}
unsigned int randomgenerator::pick_one(unsigned int c1, unsigned int c2, unsigned int c3) {
  boost::random::uniform_smallint<> randomdist(1, 3);
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
unsigned int randomgenerator::pick_one(unsigned int c1, unsigned int c2, unsigned int c3, unsigned int c4) {
  boost::random::uniform_smallint<> randomdist(1, 4);
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
unsigned int randomgenerator::pick_one(unsigned int c1, unsigned int c2, unsigned int c3, unsigned int c4, unsigned int c5) {
  boost::random::uniform_smallint<> randomdist(1, 5);
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
unsigned int randomgenerator::pick_one(unsigned int c1, unsigned int c2, unsigned int c3, unsigned int c4, unsigned int c5, unsigned int c6) {
  boost::random::uniform_smallint<> randomdist(1, 6);
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
unsigned int randomgenerator::pick_one(unsigned int c1, unsigned int c2, unsigned int c3, unsigned int c4, unsigned int c5, unsigned int c6, unsigned int c7) {
  boost::random::uniform_smallint<> randomdist(1, 7);
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
unsigned int randomgenerator::pick_one(unsigned int c1, unsigned int c2, unsigned int c3, unsigned int c4, unsigned int c5, unsigned int c6, unsigned int c7, unsigned int c8) {
  boost::random::uniform_smallint<> randomdist(1, 8);
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
unsigned int randomgenerator::pick_one(unsigned int c1, unsigned int c2, unsigned int c3, unsigned int c4, unsigned int c5, unsigned int c6, unsigned int c7, unsigned int c8, unsigned int c9) {
  boost::random::uniform_smallint<> randomdist(1, 9);
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
unsigned int randomgenerator::pick_one(unsigned int c1, unsigned int c2, unsigned int c3, unsigned int c4, unsigned int c5, unsigned int c6, unsigned int c7, unsigned int c8, unsigned int c9, unsigned int c10) {
  boost::random::uniform_smallint<> randomdist(1, 10);
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

std::string randomgenerator::pick_one(std::string c1, std::string c2) {
  boost::random::uniform_smallint<> randomdist(1, 2);
  switch(randomdist(gen)) {
  case 1:
    return c1;
  case 2:
    return c2;
  }
  return c1;
}
std::string randomgenerator::pick_one(std::string c1, std::string c2, std::string c3) {
  boost::random::uniform_smallint<> randomdist(1, 3);
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
std::string randomgenerator::pick_one(std::string c1, std::string c2, std::string c3, std::string c4) {
  boost::random::uniform_smallint<> randomdist(1, 4);
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
std::string randomgenerator::pick_one(std::string c1, std::string c2, std::string c3, std::string c4, std::string c5) {
  boost::random::uniform_smallint<> randomdist(1, 5);
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
std::string randomgenerator::pick_one(std::string c1, std::string c2, std::string c3, std::string c4, std::string c5, std::string c6) {
  boost::random::uniform_smallint<> randomdist(1, 6);
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
std::string randomgenerator::pick_one(std::string c1, std::string c2, std::string c3, std::string c4, std::string c5, std::string c6, std::string c7) {
  boost::random::uniform_smallint<> randomdist(1, 7);
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
std::string randomgenerator::pick_one(std::string c1, std::string c2, std::string c3, std::string c4, std::string c5, std::string c6, std::string c7, std::string c8) {
  boost::random::uniform_smallint<> randomdist(1, 8);
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
std::string randomgenerator::pick_one(std::string c1, std::string c2, std::string c3, std::string c4, std::string c5, std::string c6, std::string c7, std::string c8, std::string c9) {
  boost::random::uniform_smallint<> randomdist(1, 9);
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
std::string randomgenerator::pick_one(std::string c1, std::string c2, std::string c3, std::string c4, std::string c5, std::string c6, std::string c7, std::string c8, std::string c9, std::string c10) {
  boost::random::uniform_smallint<> randomdist(1, 10);
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
