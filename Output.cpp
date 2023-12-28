#include <filesystem>
#include <iostream>
#include <functional>

#include "Output.hpp"

namespace fs = std::filesystem;

// Class implementation for an Output object, containing the info of the found item (file or folder)
Output::Output(std::string _name,  bool _is_directory) {
  this->name = _name;
  this->type = "file";
  this->colour = "33";
  this->icon = "";
  if (_is_directory) {
    this->type = "directory";
    this->colour = "37";
    this->icon = "";
  }
  this->is_hidden = false;
  if (_name[0] == '.') {
    this->is_hidden = true;
    this->colour = "35";
    if (this->type == "directory") {
      this->colour = "31";
    }
  }
}

std::unordered_map<char, bool> process_flags(std::vector<std::string> flags) {
  std::unordered_map<char, bool> valid_flags {
    {'a', false},
    {'i', false},
    {'l', false}
  };
  
  for (auto f : flags) {
    for (char a : f) {
      if (valid_flags.find(a) != valid_flags.end()) {
	valid_flags[a] = true;
      }
    }
  }

  return valid_flags;
}

void Output::print(std::unordered_map<char, bool> options) {
  std::string separator = "     ";
  if (options['l']) {
    separator = "\n";
  }
  if (not options['i']) {
    this->icon = "";
  }
  if (not options['a']) {
    if (this->is_hidden)
      return;
  }
  std::cout << this->icon << " \033[1;" << this->colour << "m" << this->name << "\033[0m";
  std::cout << separator;
}

std::vector<Output> output(std::string path, std::vector<std::string> flags) {

  std::unordered_map<char, bool> options = process_flags(flags);

fs::path p = path;

  std::vector<Output> output_list;
  for (const auto &entry : fs::directory_iterator(p)) {
    std::string file_or_directory = entry.path();
    file_or_directory = file_or_directory.substr(path.size()); // removing the path from the beginning
    Output o(file_or_directory, entry.is_directory());
    output_list.push_back(o);
  }
  // std::sort(output_list.begin(), output_list.end());

  return output_list;
}
