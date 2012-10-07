#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "Usage: generator name\n";
    return 1;
  }
  std::string name(argv[1]);
  std::ofstream os((name + ".java").c_str());
  os << "package foo;\n"
     << "\n"
     << "class " << name << " { }\n";
  return 0; 
}
