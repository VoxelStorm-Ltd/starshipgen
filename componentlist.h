#ifndef COMPONENTLIST_H_INCLUDED
#define COMPONENTLIST_H_INCLUDED

#include <vector>
#include "componenttype.h"
// This file must NOT be included by any other in-project files

void populate_componentlist(std::vector<componenttype*> componenttypelist, civilisation *thisciv) {
  componenttype *thiscomponent;
  thiscomponent = new componenttype(thisciv);
  componenttypelist.push_back(thiscomponent);
}

#endif // COMPONENTLIST_H_INCLUDED
