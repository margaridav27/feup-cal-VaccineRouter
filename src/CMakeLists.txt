
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

<<<<<<< HEAD
file(GLOB_RECURSE SRC "VaccineRouter/*.cpp" "VaccineRouter/*.h" )
add_executable(VaccineRouter ${SRC})
target_link_libraries(${PROJECT_NAME} graphviewer)
=======
add_executable(src main.cpp
        VaccineRouter/algorithms/AStar.cpp
        VaccineRouter/algorithms/AStar.h
        VaccineRouter/ui/Interface.cpp
        VaccineRouter/ui/Interface.h
        VaccineRouter/utilities/Time.cpp
        VaccineRouter/utilities/Time.h
        VaccineRouter/utilities/Coordinates.cpp
        VaccineRouter/utilities/Coordinates.h
        VaccineRouter/utilities/MutablePriorityQueue.cpp
        VaccineRouter/utilities/MutablePriorityQueue.h
        VaccineRouter/graph/Graph.cpp
        VaccineRouter/graph/Graph.h
        VaccineRouter/graph/GraphProcessor.cpp
        VaccineRouter/graph/GraphProcessor.h
        VaccineRouter/graph/node/Node.cpp
        VaccineRouter/graph/node/Node.h
        VaccineRouter/graph/node/NodeD.cpp
        VaccineRouter/graph/node/NodeD.h
        VaccineRouter/graph/node/NodeA.cpp
        VaccineRouter/graph/node/NodeA.h
        VaccineRouter/graph/edge/Edge.cpp
        VaccineRouter/graph/edge/Edge.h
        VaccineRouter/model/VaccineRouter.cpp
        VaccineRouter/model/VaccineRouter.h
        VaccineRouter/model/ApplicationCenter.cpp
        VaccineRouter/model/ApplicationCenter.h
        VaccineRouter/model/StorageCenter.cpp
        VaccineRouter/model/StorageCenter.h
        VaccineRouter/model/Vehicle.cpp
        VaccineRouter/model/Vehicle.h
        VaccineRouter/algorithms/Tarjan.cpp
        VaccineRouter/algorithms/Tarjan.h
        VaccineRouter/algorithms/Dijkstra.cpp
        VaccineRouter/algorithms/Dijkstra.h)
>>>>>>> 94760f31974e891f177ce4374e0d8a7c5b09a03f
