#include <string>
#include <vector>
#include <tuple>

std::tuple<std::string, std::vector<std::string>> parser(int argc, char* argv[]) {
  std::string path = "./";
  std::vector<std::string> flags;
  
  for (int i = 1; i < argc; i++) {
    std::string s(argv[i]);
    if (s[0] == '-') {
      flags.push_back(s.substr(1));
    } else {
      path += s;
    }
  }

  return std::make_tuple(path, flags);
}

// path
// flags
// visual flags
