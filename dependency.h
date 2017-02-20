#ifndef DEPENDENCY_H_INCLUDED
#define DEPENDENCY_H_INCLUDED

#include <vector>
class component;

class dependency {
public:
  enum dependencytype {
    DEPENDENCY_POWER,                                                           // the dependant gets power from the dependee
    DEPENDENCY_FUEL,                                                            // the dependant gets fuel from the dependee
    DEPENDENCY_CONTROL,                                                         // the dependant is controlled by the dependee
    DEPENDENCY_INFO,                                                            // the dependant receives information from the dependee
  };

  component *dependee;
  component *dependant;
  dependencytype type;
  std::vector<component*> conduitparts;                                         // every component making up this conduit

  dependency();
  dependency(component thisdependee, component thisdependant);
  dependency(component thisdependee, component thisdependant, dependencytype thistype);
  ~dependency();
  void add_conduit();
  bool check_conduit();
  std::vector<component*> get_broken_conduits();
};

#endif // DEPENDENCY_H_INCLUDED
