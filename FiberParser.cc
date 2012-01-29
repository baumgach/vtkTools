
  bool FiberParser::Run() {
    return 0;
  }

  template <class T>
  bool FiberParser::OutputValues(std::string & field_name) {
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
  }
