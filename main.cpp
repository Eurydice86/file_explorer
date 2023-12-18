#include <iostream>
#include <functional>
#include <expected>
#include <tuple>
#include <string>

struct path_flags {
  std::string path;
  std::vector<std::string> flags;
};

enum class error {
  compile_time_error,
  parse_error
};

//path_flags parser(std::vector<std::string> args);
auto parser(std::vector<std::string> args) -> std::expected<path_flags, error>;


std::vector<std::string> output(std::string, std::vector<std::string>);

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
  auto output_list = output(path, flags);

  for (auto o : output_list) {
    std::cout << o << "\n";
  }
  for (auto f : flags)
    std::cout << f << "\n";
}
