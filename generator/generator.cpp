#include <fstream>
#include <iostream>
#include <string>

#include "generator/generator.h"
#include "generator/usage.h"

int main(int argc, char** argv) {
  if (argc < 2) {
    usage();
    return 1;
  }
  std::string name(argv[1]);
  std::ofstream os((name + ".java").c_str());
  os << "package " << PACKAGE << ";\n"
     << "\n"
     << "class " << name << " { }\n";
  return 0; 
}
