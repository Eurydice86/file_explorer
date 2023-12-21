#include "Parcer.h"

// The parser function reads the arguments given and returns:
// - a string, which is the path for which the contents will be shown
// - a vector of strings, which are the flags (i.e. options), which start with '-'
auto parser(std::vector<std::string> args) -> std::expected<Path_Flags, Error> {
  std::string path = "./";
  std::vector<std::string> flags;

  int path_counter = 0;
  
  for (auto arg : args) {
    if (arg[0] == '-') {
      flags.push_back(arg.substr(1));
    } else {
      path += arg;
      path_counter++;
      if (path_counter > 1)
	return std::unexpected(Error::parse_error);
    }
  }

  Path_Flags pf;
  pf.path = path;
  pf.flags = flags;

  return pf;
}
