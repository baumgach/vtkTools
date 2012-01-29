#include <iostream>
#include <string>
#include "vtkReader.h"
#include "fiber.h"


int main(int argc, char* argv[]) {
    
  std::string help_string =
    std::string("Usage:\n") + argv[0] +
    " INPUTFILE COMMAND VARIABLE\n INPUTFILE: *.vtk\n COMMAND: output, average\n VARIABLE: points, fa, trace, freewater";
      
  bool error = false;
  bool Verbose = false;

  std::string mode;
  std::string output_variable;
  std::string in_file;

  if (argc != 4) {
    error = true;
  } else {
    in_file         = argv[1];
    mode            = argv[2];
    output_variable = argv[3];
  }

  // Handle erroneous input.
  if (error) {
    std::cout << "Error!" << std::endl << std::endl;
    std::cout << help_string << std::endl;
    return 1;
  }

  
  // Check input TODO
  
  // ALLOCATE THE FIBERS ///////////////////////////////////////////////////
  std::vector<Fiber> in_fibers;
  
  // SET THINGS UP AND RUN ////////////////////////////////////////////////
    
  // Read the VTK Fiber
  if (Verbose) std::cout << "** Reading VTK file...\n";
  vtkReader * reader = new vtkReader();
  reader->SetInputPath(in_file);
  reader->SetOutputFibers(in_fibers);
  reader->SetReadFieldData(true);
  reader->SetVerbose(Verbose);
  reader->Run();
  delete reader;
  if (Verbose) std::cout << "-Number of fibers in the input: " << in_fibers.size() << std::endl;

  if (Verbose) std::cout << "** done\n";

  int nMaxFiberLength = 0;
  for (int i=0; i<in_fibers.size(); ++i) {
    if (in_fibers[i].Points.size() > nMaxFiberLength)
      nMaxFiberLength = in_fibers[i].Points.size();
  }

  //std::cout << "max fiber length: " << nMaxFiberLength << std::endl;

  for (int j=0; j<nMaxFiberLength; j++) {
    for (int i=0; i<in_fibers.size(); ++i) {
      if (j<in_fibers[i].Points.size()) {
        std::cout << in_fibers[i].Points[j]._[0] << ",";
        std::cout << in_fibers[i].Points[j]._[1] << ",";
        std::cout << in_fibers[i].Points[j]._[2];
      } else {
        std::cout << " , , ";
      }
      // only add the last colon if its not the end of the line
      if (i != in_fibers.size()-1)
        std::cout << ",";
    }
    std::cout << std::endl;
  }
  
  return 0;

}
