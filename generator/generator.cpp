#include "generator/generator.h"

#include <fstream>
#include <iostream>
#include <string>

#include "generator/usage.h"
#include "library/library.h"

int main(int argc, char** argv) {
  if (argc < 2) {
    usage();
    return 1;
  }
  callMe();
  std::string name(argv[1]);
  std::ofstream os((name + ".java").c_str());
  os << "package " << PACKAGE << ";\n"
     << "\n"
     << "class " << name << " { }\n";
  return 0; 
}
