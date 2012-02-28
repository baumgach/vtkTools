
#ifndef FIBERPARSER_H_
#define FIBERPARSER_H_

#include <vector>
#include <string>
#include "fiber.h"


class FiberParser {  
   
 public:
  
  void SetFibers(std::vector<Fiber> & fibers);
  void SetMode(std::string mode);
  void SetOutput(std::string output);
 
  bool Run();

 private:
  
  std::string _mode;
  std::string _output;
 
  std::vector<Fiber> * _fibers; 

  bool OutputValues(std::string & field_name);  
  bool OutputAverage(std::string & field_name);

} ;

#endif
