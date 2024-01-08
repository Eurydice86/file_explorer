#pragma once

#include <string>
#include <unordered_map>
#include <vector>

struct Path_Flags {
  std::string path;
  std::vector<std::string> flags;
};

std::unordered_map<char, bool> process_flags(std::vector<std::string> flags);

Path_Flags parser(std::vector<std::string> args);
