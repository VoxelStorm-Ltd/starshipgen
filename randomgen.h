#ifndef RANDOMGEN_H_INCLUDED
#define RANDOMGEN_H_INCLUDED

#include <boost/random/mersenne_twister.hpp>

class randomgenerator {
public:
  // random generator features
  boost::mt19937 gen;   // merseinne twister

  randomgenerator(unsigned int seed);
  ~randomgenerator();
  bool random_bool();
  bool random_bool_weighted(double weight_true);
  char random_char();
  char random_char_normal();
  unsigned char random_uchar();
  unsigned char random_uchar_normal();
};

#endif // RANDOMGEN_H_INCLUDED
