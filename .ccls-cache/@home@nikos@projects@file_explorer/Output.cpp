#include <filesystem>
#include <vector>
#include <algorithm>
#include <iostream>

#include "Output.h"

namespace fs = std::filesystem;

// Class implementation for an Output object, containing the info of the found item (file or folder)
Output::Output(std::string _name,  bool _is_directory) {
  this->name = _name;
  this->type = "file";
  this->colour = "0";
  this->icon = "";
  if (_is_directory) {
    this->type = "directory";
    this->colour = "36";
    this->icon = "";
  }
  this->is_hidden = false;
  if (_name[0] == '.') {
    this->is_hidden = true;
    this->colour = "32";
    if (this->type == "directory") {
      this->colour = "38";
    }
  }
}

void Output::print() {
  std::cout  << this->icon << " \033[1;" << this->colour << "m" << this->name << "\033[0m";
}

std::vector<Output> output(std::string path, std::vector<std::string> flags) {

  // fix for paths including the / character after the last directory name
  int path_buffer = 1;
  if (path[path.size() - 1] == '/') {
    path_buffer = 0;
  }
  fs::path p = path;

  std::vector<Output> output_list;
  for (const auto &entry : fs::directory_iterator(p)) {
    std::string file_or_directory = entry.path();
    file_or_directory = file_or_directory.substr(path.size() + path_buffer); // removing the path from the beginning
    Output o(file_or_directory, entry.is_directory());
    output_list.push_back(o);
  }
  // std::sort(output_list.begin(), output_list.end());

  return output_list;
}
