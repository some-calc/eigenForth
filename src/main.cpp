#include "runProgram.h"

#include <iostream>
#include <cassert>

int main(int argc, char *argv[]) {
  assert(argc == 1);
  assert(argv);

  run(std::cin, std::cout, std::cerr);
  return 0;
}
