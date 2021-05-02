cmake_minimum_required(VERSION 3.17)
project(DijkstraAlgorithmTest)

set(CMAKE_CXX_STANDARD 14)

# Build the Google tests
set(GOOGLETEST_PATH ../lib/googletest-master)
add_subdirectory(${GOOGLETEST_PATH} build)

add_executable(DijkstraAlgorithmTest main.cpp)