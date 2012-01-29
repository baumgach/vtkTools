#ifndef FIBER_H_
#define FIBER_H_

#include <vector>
#include "linalg.h"
#include <iostream>
#include <map>

typedef std::map<std::string, std::vector<std::vector<double> > > FieldMapType;
typedef std::map<std::string, std::vector<mat_t> > TensorMapType;

struct Fiber {  
   
 public:
   
  typedef std::map<std::string, std::vector< float > > FieldMapType;
  std::vector<vec_t> Points;
  FieldMapType Fields;
  TensorMapType Tensors;
  
} ;

#endif
