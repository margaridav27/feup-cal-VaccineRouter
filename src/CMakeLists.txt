
cmake_minimum_required(VERSION 3.17)
project(VaccineRouter)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories("lib/GraphViewerCpp/SFML/include")
link_directories("lib/GraphViewerCpp/SFML/lib")
add_subdirectory("lib/GraphViewerCpp")
include_directories("lib/GraphViewerCpp/include")

file(GLOB_RECURSE SRC "VaccineRouter/*.cpp" "VaccineRouter/*.h" )
add_executable(VaccineRouter ${SRC})
target_link_libraries(${PROJECT_NAME} graphviewer)
