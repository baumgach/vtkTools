
#include "FiberParser.h"
#include "fiber.h"
#include <iostream>
#include <map>

bool FiberParser::Run() {
  
  Fiber::FieldMapType::iterator it;

  // Sanity checks and running the script
  if (!(_output == "points" || _output == "Points")) {
    it = (*_fibers)[0].Fields.find(_output);
    if ( it == (*_fibers)[0].Fields.end()) {
        std::cerr << "Field '" << _output << "' doesn't exist\n" ;
        return 1;
    } 
  }

  if (_mode == "average" && (_output == "points" || _output == "Points")) {
    std::cerr << "Averaging points doesn't make sense, check syntax\n";
    return 1;
  }

  if (_mode == "output") {
    OutputValues(_output);  
  } else if (_mode == "average") {
    OutputAverage(_output);
  } else {
    std::cerr << "Unknown mode, Check syntax\n";
    return 1;
  }
  return 0;
}

void FiberParser::SetFibers(std::vector<Fiber> & fibers) { 
  _fibers = &fibers; 
}

void FiberParser::SetOutput(std::string output) { 
  _output = output; 
}

void FiberParser::SetMode(std::string mode) { 
  _mode = mode; 
}

bool FiberParser::OutputValues(std::string & field_name) {

  int nMaxFiberLength = 0;
  for (int i=0; i<_fibers->size(); ++i) {
    if ((*_fibers)[i].Points.size() > nMaxFiberLength)
      nMaxFiberLength = (*_fibers)[i].Points.size();
  }

  for (int j=0; j<nMaxFiberLength; j++) {
    for (int i=0; i< _fibers->size(); ++i) {
      if (field_name == "points" || field_name == "Points" ) {
        if (j< (*_fibers)[i].Points.size()) {
          std::cout << (*_fibers)[i].Points[j]._[0] << ",";
          std::cout << (*_fibers)[i].Points[j]._[1] << ",";
          std::cout << (*_fibers)[i].Points[j]._[2];
        } else {
          std::cout << ",,";
        }
        // only add the last colon if its not the end of the line
        if (i != _fibers->size()-1)
         std::cout << ",";
      } else {
        // TODO have a sanity check in the beginning to make sure the field is there.
        if (j< (*_fibers)[i].Points.size()) {
          std::cout << (*_fibers)[i].Fields[field_name][j];
        } else {
          std::cout << ""; // no seperator needed
        }
        if (i != _fibers->size()-1)
          std::cout << ",";
      }

    }
    std::cout << std::endl;
  }
  return 0;
}

bool FiberParser::OutputAverage(std::string & field_name) {

  double sum = 0;
  int divider = 0;

  int nMaxFiberLength = 0;
  for (int i=0; i<_fibers->size(); ++i) {
    if ((*_fibers)[i].Points.size() > nMaxFiberLength)
      nMaxFiberLength = (*_fibers)[i].Points.size();
  }

  for (int j=0; j<nMaxFiberLength; j++) {
    for (int i=0; i< _fibers->size(); ++i) {
        // TODO have a sanity check in the beginning to make sure the field is there.
        if (j< (*_fibers)[i].Points.size()) {
          sum += (*_fibers)[i].Fields[field_name][j];
          divider++;
        }
    }
  }
  std::cout << sum/divider << std::endl;
  return 0;
}
