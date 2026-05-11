#include "global.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Path not found\n";
    return -1;
  }
  entry_point(argv[1]);
  return 0;
}
