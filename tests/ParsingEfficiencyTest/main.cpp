#include <iostream>
#include "Graph.h"
#include <vector>
#include <chrono>
#include <thread>

Graph<int> BigGraph() {
    Graph<int> myGraph;

    for(int i = 1; i <= 81; i++)
        myGraph.addVertex(i);

    myGraph.addEdge(1, 2, 2);
    myGraph.addEdge(1, 3, 7);
    myGraph.addEdge(3, 2, 3);
    myGraph.addEdge(2, 3, 3);
    myGraph.addEdge(4, 5, 5);
    myGraph.addEdge(4, 6, 2);
    myGraph.addEdge(5, 6, 5);
    myGraph.addEdge(6, 5, 4);

    myGraph.addEdge(7, 8, 2);
    myGraph.addEdge(7, 9, 7);
    myGraph.addEdge(9, 8, 3);
    myGraph.addEdge(8, 9, 3);
    myGraph.addEdge(10, 11, 5);
    myGraph.addEdge(10, 12, 2);
    myGraph.addEdge(11, 12, 5);
    myGraph.addEdge(12, 11, 4);

    myGraph.addEdge(13, 14, 2);
    myGraph.addEdge(13, 15, 7);
    myGraph.addEdge(15, 14, 3);
    myGraph.addEdge(14, 15, 3);
    myGraph.addEdge(16, 17, 5);
    myGraph.addEdge(16, 18, 2);
    myGraph.addEdge(17, 18, 5);
    myGraph.addEdge(18, 17, 4);

    myGraph.addEdge(19, 20, 2);
    myGraph.addEdge(19, 21, 7);
    myGraph.addEdge(21, 20, 3);
    myGraph.addEdge(20, 21, 3);
    myGraph.addEdge(22, 23, 5);
    myGraph.addEdge(22, 24, 2);
    myGraph.addEdge(23, 24, 5);
    myGraph.addEdge(24, 23, 4);

    myGraph.addEdge(25, 26, 2);
    myGraph.addEdge(25, 27, 7);
    myGraph.addEdge(27, 26, 3);
    myGraph.addEdge(26, 27, 3);
    myGraph.addEdge(28, 29, 5);
    myGraph.addEdge(28, 30, 2);
    myGraph.addEdge(29, 30, 5);
    myGraph.addEdge(30, 29, 4);

    myGraph.addEdge(31, 32, 2);
    myGraph.addEdge(31, 33, 7);
    myGraph.addEdge(33, 32, 3);
    myGraph.addEdge(32, 33, 3);
    myGraph.addEdge(34, 35, 5);
    myGraph.addEdge(34, 36, 2);
    myGraph.addEdge(35, 36, 5);
    myGraph.addEdge(36, 35, 4);

    myGraph.addEdge(37, 38, 2);
    myGraph.addEdge(37, 38, 7);
    myGraph.addEdge(39, 38, 3);
    myGraph.addEdge(38, 39, 3);
    myGraph.addEdge(40, 41, 5);
    myGraph.addEdge(40, 42, 2);
    myGraph.addEdge(41, 42, 5);
    myGraph.addEdge(42, 41, 4);

    myGraph.addEdge(43, 44, 2);
    myGraph.addEdge(43, 45, 7);
    myGraph.addEdge(45, 44, 3);
    myGraph.addEdge(44, 45, 3);
    myGraph.addEdge(46, 47, 2);
    myGraph.addEdge(46, 48, 7);
    myGraph.addEdge(48, 47, 3);

    myGraph.addEdge(47, 48, 3);
    myGraph.addEdge(49, 50, 5);
    myGraph.addEdge(49, 51, 2);
    myGraph.addEdge(50, 51, 5);
    myGraph.addEdge(51, 50, 4);
    myGraph.addEdge(52, 53, 2);
    myGraph.addEdge(52, 54, 7);
    myGraph.addEdge(54, 53, 3);
    myGraph.addEdge(53, 54, 3);

    myGraph.addEdge(55, 56, 2);
    myGraph.addEdge(55, 57, 7);
    myGraph.addEdge(57, 56, 3);
    myGraph.addEdge(56, 57, 3);
    myGraph.addEdge(58, 59, 5);
    myGraph.addEdge(58, 60, 2);
    myGraph.addEdge(59, 60, 5);
    myGraph.addEdge(60, 59, 4);

    myGraph.addEdge(61, 62, 2);
    myGraph.addEdge(61, 63, 7);
    myGraph.addEdge(63, 62, 3);
    myGraph.addEdge(62, 63, 3);
    myGraph.addEdge(64, 65, 2);
    myGraph.addEdge(64, 66, 7);
    myGraph.addEdge(66, 65, 3);
    myGraph.addEdge(65, 66, 3);

    myGraph.addEdge(67, 68, 5);
    myGraph.addEdge(67, 69, 2);
    myGraph.addEdge(68, 69, 5);
    myGraph.addEdge(69, 68, 4);
    myGraph.addEdge(70, 71, 2);
    myGraph.addEdge(70, 72, 7);
    myGraph.addEdge(72, 71, 3);
    myGraph.addEdge(71, 72, 3);

    myGraph.addEdge(73, 74, 2);
    myGraph.addEdge(73, 75, 7);
    myGraph.addEdge(75, 74, 3);
    myGraph.addEdge(74, 75, 3);
    myGraph.addEdge(76, 77, 5);
    myGraph.addEdge(76, 78, 2);
    myGraph.addEdge(77, 78, 5);
    myGraph.addEdge(78, 77, 4);
    myGraph.addEdge(79, 80, 2);
    myGraph.addEdge(79, 81, 7);
    myGraph.addEdge(81, 80, 3);
    myGraph.addEdge(80, 81, 3);


    return myGraph;
}

std::vector<Graph<int>> getParsedGraphs() {
    Graph<int> myGraph1;
    Graph<int> myGraph2;
    Graph<int> myGraph3;
    Graph<int> myGraph4;
    Graph<int> myGraph5;
    Graph<int> myGraph6;
    Graph<int> myGraph7;
    Graph<int> myGraph8;
    Graph<int> myGraph9;
    Graph<int> myGraph10;
    Graph<int> myGraph11;
    Graph<int> myGraph12;


    for(int i = 1; i <= 81; i++) {
        if (i<=6)  myGraph1.addVertex(i);
        else if (i <= 12) myGraph2.addVertex(i);
        else if (i <= 18) myGraph3.addVertex(i);
        else if (i <= 24) myGraph4.addVertex(i);
        else if (i <= 30) myGraph5.addVertex(i);
        else if (i <= 36) myGraph6.addVertex(i);
        else if (i <= 42) myGraph7.addVertex(i);
        else if (i <= 48) myGraph8.addVertex(i);
        else if (i <= 54) myGraph9.addVertex(i);
        else if (i <= 60) myGraph10.addVertex(i);
        else if (i <= 66) myGraph11.addVertex(i);
        else   myGraph12.addVertex(i);



    }
    myGraph1.addEdge(1, 3, 7);
    myGraph1.addEdge(1, 2, 2);
    myGraph1.addEdge(3, 2, 3);
    myGraph1.addEdge(2, 3, 3);
    myGraph1.addEdge(4, 6, 2);
    myGraph1.addEdge(4, 5, 5);
    myGraph1.addEdge(5, 6, 5);
    myGraph1.addEdge(6, 5, 4);

    myGraph2.addEdge(7, 8, 2);
    myGraph2.addEdge(7, 9, 7);
    myGraph2.addEdge(9, 8, 3);
    myGraph2.addEdge(8, 9, 3);
    myGraph2.addEdge(10, 11, 5);
    myGraph2.addEdge(10, 12, 2);
    myGraph2.addEdge(11, 12, 5);
    myGraph2.addEdge(12, 11, 4);

    myGraph3.addEdge(13, 14, 2);
    myGraph3.addEdge(13, 15, 7);
    myGraph3.addEdge(15, 14, 3);
    myGraph3.addEdge(14, 15, 3);
    myGraph3.addEdge(16, 17, 5);
    myGraph3.addEdge(16, 18, 2);
    myGraph3.addEdge(17, 18, 5);
    myGraph3.addEdge(18, 17, 4);

    myGraph4.addEdge(19, 20, 2);
    myGraph4.addEdge(19, 21, 7);
    myGraph4.addEdge(21, 20, 3);
    myGraph4.addEdge(20, 21, 3);
    myGraph4.addEdge(22, 23, 5);
    myGraph4.addEdge(22, 24, 2);
    myGraph4.addEdge(23, 24, 5);
    myGraph4.addEdge(24, 23, 4);

    myGraph5.addEdge(25, 26, 2);
    myGraph5.addEdge(25, 27, 7);
    myGraph5.addEdge(27, 26, 3);
    myGraph5.addEdge(26, 27, 3);
    myGraph5.addEdge(28, 29, 5);
    myGraph5.addEdge(28, 30, 2);
    myGraph5.addEdge(29, 30, 5);
    myGraph5.addEdge(30, 29, 4);

    myGraph6.addEdge(31, 32, 2);
    myGraph6.addEdge(31, 33, 7);
    myGraph6.addEdge(33, 32, 3);
    myGraph6.addEdge(32, 33, 3);
    myGraph6.addEdge(34, 35, 5);
    myGraph6.addEdge(34, 36, 2);
    myGraph6.addEdge(35, 36, 5);
    myGraph6.addEdge(36, 35, 4);

    myGraph7.addEdge(37, 38, 2);
    myGraph7.addEdge(37, 38, 7);
    myGraph7.addEdge(39, 38, 3);
    myGraph7.addEdge(38, 39, 3);
    myGraph7.addEdge(40, 41, 5);
    myGraph7.addEdge(40, 42, 2);
    myGraph7.addEdge(41, 42, 5);
    myGraph7.addEdge(42, 41, 4);

    myGraph8.addEdge(43, 44, 2);
    myGraph8.addEdge(43, 45, 7);
    myGraph8.addEdge(45, 44, 3);
    myGraph8.addEdge(44, 45, 3);
    myGraph8.addEdge(46, 47, 2);
    myGraph8.addEdge(46, 48, 7);
    myGraph8.addEdge(48, 47, 3);

    myGraph9.addEdge(47, 48, 3);
    myGraph9.addEdge(49, 50, 5);
    myGraph9.addEdge(49, 51, 2);
    myGraph9.addEdge(50, 51, 5);
    myGraph9.addEdge(51, 50, 4);
    myGraph9.addEdge(52, 53, 2);
    myGraph9.addEdge(52, 54, 7);
    myGraph9.addEdge(54, 53, 3);
    myGraph9.addEdge(53, 54, 3);

    myGraph10.addEdge(55, 56, 2);
    myGraph10.addEdge(55, 57, 7);
    myGraph10.addEdge(57, 56, 3);
    myGraph10.addEdge(56, 57, 3);
    myGraph10.addEdge(58, 59, 5);
    myGraph10.addEdge(58, 60, 2);
    myGraph10.addEdge(59, 60, 5);
    myGraph10.addEdge(60, 59, 4);

    myGraph11.addEdge(61, 62, 2);
    myGraph11.addEdge(61, 63, 7);
    myGraph11.addEdge(63, 62, 3);
    myGraph11.addEdge(62, 63, 3);
    myGraph11.addEdge(64, 65, 2);
    myGraph11.addEdge(64, 66, 7);
    myGraph11.addEdge(66, 65, 3);
    myGraph11.addEdge(65, 66, 3);

    myGraph12.addEdge(67, 68, 5);
    myGraph12.addEdge(67, 69, 2);
    myGraph12.addEdge(68, 69, 5);
    myGraph12.addEdge(69, 68, 4);
    myGraph12.addEdge(70, 71, 2);
    myGraph12.addEdge(70, 72, 7);
    myGraph12.addEdge(72, 71, 3);
    myGraph12.addEdge(71, 72, 3);
    myGraph12.addEdge(73, 74, 2);
    myGraph12.addEdge(73, 75, 7);
    myGraph12.addEdge(75, 74, 3);
    myGraph12.addEdge(74, 75, 3);
    myGraph12.addEdge(76, 77, 5);
    myGraph12.addEdge(76, 78, 2);
    myGraph12.addEdge(77, 78, 5);
    myGraph12.addEdge(78, 77, 4);
    myGraph12.addEdge(79, 80, 2);
    myGraph12.addEdge(79, 81, 7);
    myGraph12.addEdge(81, 80, 3);
    myGraph12.addEdge(80, 81, 3);

    std::vector<Graph<int>> vect = { myGraph1, myGraph2, myGraph3,myGraph4,myGraph5,myGraph6, myGraph7, myGraph8, myGraph9,myGraph10,myGraph11,myGraph12};
    return vect;
}

int NotParsingTime(){
    Graph<int> bigGraph;
    bigGraph = BigGraph();

    auto start = std::chrono::high_resolution_clock::now();
    std::thread t1 ([&](){
      bigGraph.dijkstraShortestPath(6);
    });
    std::thread t2 ([&](){
      bigGraph.dijkstraShortestPath(12);
    });
    std::thread t3 ([&](){
      bigGraph.dijkstraShortestPath(18);
    });
    std::thread t4 ([&](){
      bigGraph.dijkstraShortestPath(24);
    });
    std::thread t5 ([&](){
      bigGraph.dijkstraShortestPath(30);
    });
    std::thread t6 ([&](){
      bigGraph.dijkstraShortestPath(36);
    });
    std::thread t7 ([&](){
      bigGraph.dijkstraShortestPath(42);
    });
    std::thread t8 ([&](){
      bigGraph.dijkstraShortestPath(48);
    });
    std::thread t9 ([&](){
      bigGraph.dijkstraShortestPath(54);
    });
    std::thread t10 ([&](){
      bigGraph.dijkstraShortestPath(60);
    });
    std::thread t11 ([&](){
      bigGraph.dijkstraShortestPath(66);
    });
    std::thread t12 ([&](){
      bigGraph.dijkstraShortestPath(81);
    });
    t1.join(); t2.join(); t3.join();
    t4.join(); t5.join(); t6.join();
    t7.join(); t8.join(); t9.join();
    t10.join(); t11.join(); t12.join();

    auto finish = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count();
    std::cout << "Dijkstra processing   average time (micro-seconds)=" << (elapsed) << std::endl;
}

int ParsingTime(){
    Graph<int>  miniGraph1, miniGraph2, miniGraph3,miniGraph4, miniGraph5,miniGraph6,miniGraph7,miniGraph8, miniGraph9, miniGraph10, miniGraph11, miniGraph12;
    std::vector<Graph<int>> vect = getParsedGraphs();
    miniGraph1 = vect[0]; miniGraph2 = vect[1]; miniGraph3 = vect[2];
    miniGraph4 = vect[3]; miniGraph5 = vect[4]; miniGraph6 = vect[5];
    miniGraph7 = vect[6]; miniGraph8 = vect[7]; miniGraph9 = vect[8];
    miniGraph10 = vect[9]; miniGraph11 = vect[10]; miniGraph12 = vect[11];

    auto start = std::chrono::high_resolution_clock::now();
    std::thread t1 ([&](){
      miniGraph1.dijkstraShortestPath(6);
    });
    std::thread t2 ([&](){
      miniGraph2.dijkstraShortestPath(12);
    });
    std::thread t3 ([&](){
      miniGraph3.dijkstraShortestPath(18);
    });
    std::thread t4 ([&](){
      miniGraph4.dijkstraShortestPath(24);
    });
    std::thread t5 ([&](){
      miniGraph5.dijkstraShortestPath(30);
    });
    std::thread t6 ([&](){
      miniGraph6.dijkstraShortestPath(36);
    });
    std::thread t7 ([&](){
      miniGraph7.dijkstraShortestPath(42);
    });
    std::thread t8 ([&](){
      miniGraph8.dijkstraShortestPath(48);
    });
    std::thread t9 ([&](){
      miniGraph9.dijkstraShortestPath(54);
    });
    std::thread t10 ([&](){
      miniGraph10.dijkstraShortestPath(60);
    });
    std::thread t11 ([&](){
      miniGraph11.dijkstraShortestPath(66);
    });
    std::thread t12 ([&](){
      miniGraph12.dijkstraShortestPath(81);
    });
    t1.join(); t2.join(); t3.join();
    t4.join(); t5.join(); t6.join();
    t7.join(); t8.join(); t9.join();
    t10.join(); t11.join(); t12.join();

    auto finish = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count();
    std::cout << "Dijkstra processing   average time (micro-seconds)=" << (elapsed) << std::endl;
}

template <class T> c
lass Edge;
int main() {
    std::cout<<"NOT PARSING:\n";
    NotParsingTime();
    std::cout<<"\nPARSING:\n";
    ParsingTime();

    return 0;
}
