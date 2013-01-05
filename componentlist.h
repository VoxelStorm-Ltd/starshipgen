#ifndef COMPONENTLIST_H_INCLUDED
#define COMPONENTLIST_H_INCLUDED

#include <vector>
#include <string>
class componenttype;
class civilisation;

class componentlist {
public:
  std::vector<componenttype*> *typelist;
  civilisation *civ;

  componentlist(civilisation *thisciv);
  ~componentlist();
  void populate_componentlist();
  componenttype *getcomponent(std::string thisid);
};

#endif // COMPONENTLIST_H_INCLUDED
