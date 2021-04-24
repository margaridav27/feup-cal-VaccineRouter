cmake_minimum_required(VERSION 3.17)
project(src)

set(CMAKE_CXX_STANDARD 14)

add_executable(src main.cpp
        algorithms/AStar.cpp
        algorithms/AStar.h
        ui/Interface.cpp
        ui/Interface.h
        utilities/Time.cpp
        utilities/Time.h
        utilities/Coordinates.cpp
        utilities/Coordinates.h
        utilities/MutablePriorityQueue.h
        graph/Graph.cpp
        graph/Graph.h
        graph/GraphProcessor.cpp
        graph/GraphProcessor.h
        graph/node/Node.cpp
        graph/node/Node.h
        graph/node/NodeD.cpp
        graph/node/NodeD.h
        graph/node/NodeA.cpp
        graph/node/NodeA.h
        graph/edge/Edge.cpp
        graph/edge/Edge.h
        model/VaccineRouter.cpp
        model/VaccineRouter.h
        model/ApplicationCenter.cpp
        model/ApplicationCenter.h
        model/StorageCenter.cpp
        model/StorageCenter.h
        model/Vehicle.cpp
        model/Vehicle.h
        algorithms/Tarjan.cpp
        algorithms/Tarjan.h
        algorithms/Dijkstra.cpp
        algorithms/Dijkstra.h)