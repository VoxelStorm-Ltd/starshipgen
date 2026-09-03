#pragma once

#include <string>
#include <vector>

class componenttype;
class civilisation;

class componentlist {
public:
  std::vector<componenttype*> *typelist;
  civilisation *civ;

  explicit componentlist(civilisation *thisciv);
  ~componentlist();
  void populate_componentlist();
  componenttype *getcomponent(std::string thisid);
};
