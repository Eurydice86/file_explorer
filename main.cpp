#include "Parcer.h"
#include "Output.h"


int main(int argc, char* argv[]) {
  std::vector<std::string> args;
  for (int i = 1; i < argc; i++) {
    args.push_back(argv[i]);
  }

  std::string path;
  std::vector<std::string> flags;
  
  auto pf = parser(args);
  if (!pf.has_value()) {
    std::cout << "Error"  << "\n";
  }
  else {
    path = pf.value().path;
    flags = pf.value().flags;
  }
  std::vector<Output> output_list = output(path, flags);

  std::string separator = "  ";
  for (auto o : output_list) {
    o.print();
    std::cout << separator;
  }
  std::cout << "\nFlags:\n";
  for (auto f : flags)
    std::cout << f << "\n";
}
