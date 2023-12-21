#include <string>
#include <expected>
#include <vector>
#include <iostream>

enum class Error {
  compile_time_error,
  parse_error
};

struct Path_Flags {
  std::string path;
  std::vector<std::string> flags;
};

auto parser(std::vector<std::string> args) -> std::expected<Path_Flags, Error>;
