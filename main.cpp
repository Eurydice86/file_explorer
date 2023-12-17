#include <iostream>
#include <functional>


std::tuple<std::string, std::vector<std::string>> parser(std::vector<std::string>);
std::vector<std::string> output(std::string, std::vector<std::string>);

int main(int argc, char* argv[]) {
  std::vector<std::string> args;
  for (int i = 1; i < argc; i++) {
    args.push_back(argv[i]);
  }
  
  auto [path, flags] = parser(args);
  
  auto output_list = output(path, flags);
  
  for (auto o : output_list) {
    std::cout << o << "\n";
  }
} 
