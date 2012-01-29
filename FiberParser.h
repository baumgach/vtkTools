
#ifndef FIBERPARSER_H_
#define FIBERPARSER_H_

#include <iostream>
#include <vector>
#include <string>
#include "fiber.h"

enum mode_type { OUTPUT, AVERAGE };
enum ouput_type { POINTS, FA, TRACE, FREEWATER }; 

class FiberParser {  
   
 public:
  void SetMode(mode_type mode) { _mode = mode; }
  void SetOutput(output_type output) { _output = output; }
 
  bool Run();

 private:
  mode_type _mode;
  output_type _output;
 
  std::vector<Fiber> * _fibers; 

  bool OutputValues(std::string & field_name);  

} ;

#endif
