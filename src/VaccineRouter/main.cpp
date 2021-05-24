#include "graphviewer/graphViewer.h"
#include "ui/Interface.h"
#include <iostream>


int main() {

  auto start = std::chrono::high_resolution_clock::now();
  Interface ui;
  ui.initInterface();
  auto finish = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count();
  std::cout << "Dijkstra processing   average time (micro-seconds)=" << (elapsed) << std::endl;
}
