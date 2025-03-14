

project(brainfuck)

add_executable(brainfuck main.cpp compile.cpp run.cpp)


set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Weffc++")
set(CMAKE_CXX_FLAGS_DEBUG "-ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-O1 -s")
set_property(TARGET brainfuck PROPERTY CXX_STANDARD 20)
