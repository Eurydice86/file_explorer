#include "Parser.hpp"
#include <iostream>


Path_Flags parser(std::vector<std::string> args) {
  std::string path = "./";
  std::vector<std::string> flags;

  int path_counter = 0;
  
  for (std::string arg : args) {
    if (arg[0] == '-') {
      flags.push_back(arg.substr(1));
    } else {
      path += arg;
      path_counter++;
      if (path_counter > 1) {
	Path_Flags pf;
	pf.path = "";
	pf.flags = flags;
	return pf;
      }
    }
  }
  


  // adding the '/' character in the path if missing
  if (path.back() != '/') {
    path.push_back('/');
  }
    
  Path_Flags pf;
  pf.path = path;
  pf.flags = flags;

  return pf;
}
