#include <functional>

struct Output {
  std::string name;
  std::string type;
  std::string icon;
  bool is_hidden;
  std::string colour;

  Output(std::string _name,  bool _is_directory);
  void print();
};

std::vector<Output> output(std::string, std::vector<std::string>);

