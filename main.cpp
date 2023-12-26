#include "Output.h"
#include "Parcer.h"

int main(int argc, char *argv[]) {
  std::vector<std::string> args;
  for (int i = 1; i < argc; i++) {
    args.push_back(argv[i]);
  }

  std::string path;
  std::vector<std::string> flags;

  auto pf = parser(args);
  if (!pf.has_value()) {
    std::cout << "Error"
              << "\n";
  } else {
    path = pf.value().path;
    flags = pf.value().flags;
  }
  std::vector<Output> output_list = output(path, flags);

  std::unordered_map<char, bool> options = process_flags(flags);

  for (auto o : output_list) {
    o.print(options);
  }
}
