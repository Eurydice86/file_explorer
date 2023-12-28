#include <iostream>

#include "Output.hpp"
#include "Parcer.hpp"

int main(int argc, char *argv[]) {
  std::vector<std::string> args;
  for (int i = 1; i < argc; i++) {
    args.push_back(argv[i]);
  }

  std::string path;
  std::vector<std::string> flags;
  
  Path_Flags pf = parser(args);
  if (pf.path == "") {
    std::cout << "Error: ambiguous path.\n";
    return 1;
  }
  path = pf.path;
  flags = pf.flags;
  std::vector<Output> output_list = output(path, flags);

  std::unordered_map<char, bool> options = process_flags(flags);

  for (auto o : output_list) {
    o.print(options);
  }
  std::cout << std::endl;
}
