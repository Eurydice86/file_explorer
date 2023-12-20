#include <iostream>
#include <functional>
#include <expected>
#include <tuple>
#include <string>

struct path_flags {
  std::string path;
  std::vector<std::string> flags;
};

struct Output {
  std::string name;
  std::string type;
  bool is_hidden;
  std::string colour;

  Output(std::string _name,  bool _is_directory) {
    this->name = _name;
    this->type = "file";
    this->colour = "0";
    if (_is_directory) {
      this->type = "directory";
      this->colour = "7";
    }
    this->is_hidden = false;
    if (_name[0] == '.') {
      this->is_hidden = true;
      this->colour = "32";
    }
  }

  void print() {
    std::cout << "\033[1;" << this->colour << "m" << this->name << "\033[0m\n";
  }
};

enum class error {
  compile_time_error,
  parse_error
};

//path_flags parser(std::vector<std::string> args);
auto parser(std::vector<std::string> args) -> std::expected<path_flags, error>;
std::vector<Output> output(std::string, std::vector<std::string>);

int main(int argc, char* argv[]) {
  std::vector<std::string> args;
  for (int i = 1; i < argc; i++) {
    args.push_back(argv[i]);
  }

  std::string path;
  std::vector<std::string> flags;
  
  auto pf = parser(args);
  if (!pf.has_value())
    std::cout << "Error"  << "\n";
  else {
    path = pf.value().path;
    flags = pf.value().flags;
  }
  std::vector<Output> output_list = output(path, flags);

  for (auto o : output_list) {
    o.print();
  }
  
  for (auto f : flags)
    std::cout << f << "\n";
}
