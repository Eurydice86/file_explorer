#include <filesystem>
#include <vector>
#include <algorithm>


namespace fs = std::filesystem;

std::vector<std::string> output(std::string path, std::vector<std::string> flags) {

  // fix for paths including the / character after the last directory name
  int path_buffer = 1;
  if (path[path.size() - 1] == '/') {
    path_buffer = 0;
  }
  
  fs::path p = path;
  std::vector<std::string> output_list;
  for (const auto &entry : fs::directory_iterator(p)) {
    std::string file_or_directory = entry.path();
    file_or_directory = file_or_directory.substr(path.size() + path_buffer); // removing the path from the beginning
    output_list.push_back(file_or_directory);
  }
  std::sort(output_list.begin(), output_list.end());

  return output_list;
}
