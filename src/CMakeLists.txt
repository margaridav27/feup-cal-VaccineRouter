cmake_minimum_required(VERSION 3.17)
project(src)

set(CMAKE_CXX_STANDARD 14)

add_executable(src main.cpp algorithms/AStar.cpp algorithms/AStar.h ui/Interface.cpp ui/Interface.h utilities/Time.cpp utilities/Time.h utilities/Coordinates.cpp utilities/Coordinates.h graph/Graph.cpp graph/Graph.h graph/GraphProcessor.cpp graph/GraphProcessor.h graph/Node.cpp graph/Node.h graph/NodeD.cpp graph/NodeD.h graph/NodeA.cpp graph/NodeA.h graph/Edge.cpp graph/Edge.h model/VaccineRouter.cpp model/VaccineRouter.h model/ApplicationCenter.cpp model/ApplicationCenter.h model/StorageCenter.cpp model/StorageCenter.h model/Vehicle.cpp model/Vehicle.h)