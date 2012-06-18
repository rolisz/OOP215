#include "helper.h"

 bool sortByName(const Task &t1, const Task &t2)
 {
     return t1.getName() < t2.getName();
 }