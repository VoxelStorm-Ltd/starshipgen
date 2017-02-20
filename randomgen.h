#ifndef RANDOMGEN_H_INCLUDED
#define RANDOMGEN_H_INCLUDED

#include <string>
#include <boost/random/mersenne_twister.hpp>

class randomgenerator {
public:
  // random generator features
  boost::mt19937 gen;                                                           // merseinne twister

  randomgenerator(unsigned int seed);
  ~randomgenerator();
  bool random_bool();
  bool random_bool_weighted(double weight_true);
  char random_char();
  char random_char_normal();
  char random_char_normal_biased(char bias);
  unsigned char random_uchar();
  unsigned char random_uchar_normal();
  unsigned char random_uchar_normal_biased(unsigned char bias);

  char pick_one(char c1, char c2);
  char pick_one(char c1, char c2, char c3);
  char pick_one(char c1, char c2, char c3, char c4);
  char pick_one(char c1, char c2, char c3, char c4, char c5);
  char pick_one(char c1, char c2, char c3, char c4, char c5, char c6);
  char pick_one(char c1, char c2, char c3, char c4, char c5, char c6, char c7);
  char pick_one(char c1, char c2, char c3, char c4, char c5, char c6, char c7, char c8);
  char pick_one(char c1, char c2, char c3, char c4, char c5, char c6, char c7, char c8, char c9);
  char pick_one(char c1, char c2, char c3, char c4, char c5, char c6, char c7, char c8, char c9, char c10);
  unsigned char pick_one(unsigned char c1, unsigned char c2);
  unsigned char pick_one(unsigned char c1, unsigned char c2, unsigned char c3);
  unsigned char pick_one(unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4);
  unsigned char pick_one(unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4, unsigned char c5);
  unsigned char pick_one(unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4, unsigned char c5, unsigned char c6);
  unsigned char pick_one(unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4, unsigned char c5, unsigned char c6, unsigned char c7);
  unsigned char pick_one(unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4, unsigned char c5, unsigned char c6, unsigned char c7, unsigned char c8);
  unsigned char pick_one(unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4, unsigned char c5, unsigned char c6, unsigned char c7, unsigned char c8, unsigned char c9);
  unsigned char pick_one(unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4, unsigned char c5, unsigned char c6, unsigned char c7, unsigned char c8, unsigned char c9, unsigned char c10);
  int pick_one(int c1, int c2);
  int pick_one(int c1, int c2, int c3);
  int pick_one(int c1, int c2, int c3, int c4);
  int pick_one(int c1, int c2, int c3, int c4, int c5);
  int pick_one(int c1, int c2, int c3, int c4, int c5, int c6);
  int pick_one(int c1, int c2, int c3, int c4, int c5, int c6, int c7);
  int pick_one(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8);
  int pick_one(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, int c9);
  int pick_one(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, int c9, int c10);
  unsigned int pick_one(unsigned int c1, unsigned int c2);
  unsigned int pick_one(unsigned int c1, unsigned int c2, unsigned int c3);
  unsigned int pick_one(unsigned int c1, unsigned int c2, unsigned int c3, unsigned int c4);
  unsigned int pick_one(unsigned int c1, unsigned int c2, unsigned int c3, unsigned int c4, unsigned int c5);
  unsigned int pick_one(unsigned int c1, unsigned int c2, unsigned int c3, unsigned int c4, unsigned int c5, unsigned int c6);
  unsigned int pick_one(unsigned int c1, unsigned int c2, unsigned int c3, unsigned int c4, unsigned int c5, unsigned int c6, unsigned int c7);
  unsigned int pick_one(unsigned int c1, unsigned int c2, unsigned int c3, unsigned int c4, unsigned int c5, unsigned int c6, unsigned int c7, unsigned int c8);
  unsigned int pick_one(unsigned int c1, unsigned int c2, unsigned int c3, unsigned int c4, unsigned int c5, unsigned int c6, unsigned int c7, unsigned int c8, unsigned int c9);
  unsigned int pick_one(unsigned int c1, unsigned int c2, unsigned int c3, unsigned int c4, unsigned int c5, unsigned int c6, unsigned int c7, unsigned int c8, unsigned int c9, unsigned int c10);
  std::string pick_one(std::string c1, std::string c2);
  std::string pick_one(std::string c1, std::string c2, std::string c3);
  std::string pick_one(std::string c1, std::string c2, std::string c3, std::string c4);
  std::string pick_one(std::string c1, std::string c2, std::string c3, std::string c4, std::string c5);
  std::string pick_one(std::string c1, std::string c2, std::string c3, std::string c4, std::string c5, std::string c6);
  std::string pick_one(std::string c1, std::string c2, std::string c3, std::string c4, std::string c5, std::string c6, std::string c7);
  std::string pick_one(std::string c1, std::string c2, std::string c3, std::string c4, std::string c5, std::string c6, std::string c7, std::string c8);
  std::string pick_one(std::string c1, std::string c2, std::string c3, std::string c4, std::string c5, std::string c6, std::string c7, std::string c8, std::string c9);
  std::string pick_one(std::string c1, std::string c2, std::string c3, std::string c4, std::string c5, std::string c6, std::string c7, std::string c8, std::string c9, std::string c10);
};

#endif // RANDOMGEN_H_INCLUDED
