#include <filesystem>
#include <vector>
#include <algorithm>
#include <iostream>

namespace fs = std::filesystem;

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
