#include <iostream>
#include <filesystem>
#include <functional>
#include <algorithm>

std::tuple<std::string, std::vector<std::string>> parser(int argc, char* argv[]);

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
  auto [path, flags] = parser(argc, argv);

  fs::path p = path;

  int path_buffer = 1;
  if (path[path.size() - 1] == '/') {
    path_buffer = 0;
  }
  

  std::vector<std::string> output_list;
  for (const auto &entry : fs::directory_iterator(p)) {
    std::string file_or_directory = entry.path();
    file_or_directory = file_or_directory.substr(path.size() + path_buffer); // removing the path from the beginning
    output_list.push_back(file_or_directory);
  }
  std::sort(output_list.begin(), output_list.end());

  for (auto o : output_list) {
    std::cout << o  << "\n";
  }
} 
