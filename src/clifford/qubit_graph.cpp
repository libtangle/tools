#include <iostream>
#include "clifford.h"

namespace tangle::clifford {

// QubitGraph::QubitGraph() {
  
// }

void QubitGraph::initialize_graph(int n) {
  for (int i = 0; i < n; i++) {
    QubitVertex *vertex = new QubitVertex();
    vertices.push_back(*vertex);
  }
}

void QubitGraph::toggle_edge(int a, int b) {
  if (this->has_edge(a, b)) {
    this->remove_edge(a, b);
  } else {
    this->add_edge(a, b);
  }
}

bool QubitGraph::has_edge(int a, int b) {
  return vertices[a].neighbors.count(b) || vertices[b].neighbors.count(a);
}

void QubitGraph::add_edge(int a, int b) {
  vertices[a].neighbors.insert(b);
  vertices[b].neighbors.insert(a);
}

void QubitGraph::remove_edge(int a, int b) {
  vertices[a].neighbors.erase(b);
  vertices[b].neighbors.erase(a);
}

void QubitGraph::print() {
  for (auto i : vertices) {
    i.print();
  }
}

}  // namespace tangle::clifford
