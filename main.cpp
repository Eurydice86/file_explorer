#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <functional>
#include <algorithm>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {

  std::vector<std::string> flags;

  fs::path p = "./";
  if (argc > 1) {
    p += argv[1];
  }

  for (int i = 1; i < argc; i++) {
    std::string s(argv[i]);
    if (s[0] == '-') {
      flags.push_back(s.substr(1));
    }
  }

  std::string path(p);
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
