#include <functional>
#include <string>
#include <vector>

struct Output {
  std::string name;
  std::string type;
  std::string icon;
  bool is_hidden;
  std::string colour;

  Output(std::string _name, bool _is_directory);
  void print(std::unordered_map<char, bool>);
};

std::vector<Output> output(std::string, std::vector<std::string>);

std::unordered_map<char, bool> process_flags(std::vector<std::string>);
