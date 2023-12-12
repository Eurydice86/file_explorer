#include <string>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {

  fs::path p = "./";
  if (argc > 1) {
    p += argv[1];
  }

  std::cout << p << "\n";
  for (const auto &entry : fs::directory_iterator(p)) {
    std::cout << entry.path() << "\n";
  }
  
}
