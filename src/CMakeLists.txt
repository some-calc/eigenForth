add_executable(eigenforth
  main.cpp
  Grammar.cpp
  Builtins.cpp
  runProgram.cpp)
target_include_directories(eigenforth PRIVATE ../include)
target_link_libraries(eigenforth giac gmp)
