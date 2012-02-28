
cmake_minimum_required(VERSION 2.4)
if(COMMAND CMAKE_POLICY)
  cmake_policy(SET CMP0003 NEW)
endif(COMMAND CMAKE_POLICY)

# Generate InterfaceCLP.h
SET(vtkFilter_SOURCE vtkTools.cxx vtkReader.cc FiberParser.cc)

# Add Executables and Link
ADD_EXECUTABLE(vtkTools ${vtkFilter_SOURCE} )
