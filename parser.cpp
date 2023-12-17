#include <string>
#include <vector>
#include <tuple>
// The parser function reads the arguments given and returns:
// - a string, which is the path for which the contents will be shown
// - a vector of strings, which are the flags (i.e. options), which start with '-'

std::tuple<std::string, std::vector<std::string>> parser(std::vector<std::string> args) {
  std::string path = "./";
  std::vector<std::string> flags;
  
  for (auto arg : args) {
    if (arg[0] == '-') {
      flags.push_back(arg.substr(1));
    } else {
      path += arg;
    }
  }

  return std::make_tuple(path, flags);
}

// path
// flags
// visual flags
