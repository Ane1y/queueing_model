cmake_minimum_required(VERSION 3.14)
project(na3kurse)

set(CMAKE_CXX_STANDARD 14)

add_executable(na3kurse main.cpp Source.hpp Device.cpp Device.hpp Source.cpp Buffer.cpp Buffer.hpp Record.hpp Maschine.cpp Maschine.hpp Randomizer.cpp Randomizer.hpp)