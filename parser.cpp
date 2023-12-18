#include <string>
#include <expected>
#include <vector>
#include <tuple>
#include <iostream>

struct path_flags {
  std::string path;
  std::vector<std::string> flags;
};

enum class error {
  compile_time_error,
  parse_error
};

// The parser function reads the arguments given and returns:
// - a string, which is the path for which the contents will be shown
// - a vector of strings, which are the flags (i.e. options), which start with '-'
auto parser(std::vector<std::string> args) -> std::expected<path_flags, error> {
  //path_flags parser(std::vector<std::string> args) {
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
	return std::unexpected(error::parse_error);
    }
  }

  path_flags pf;
  pf.path = path;
  pf.flags = flags;

  return pf;
}

// path
// flags
// visual flags
