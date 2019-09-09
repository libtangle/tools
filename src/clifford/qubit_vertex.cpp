#include <algorithm>
#include <iostream>
#include <set>
#include "clifford.h"

namespace tangle::clifford {

QubitVertex::QubitVertex() { vop_code = 10; }

QubitVertex::QubitVertex(int vop) { vop_code = vop; }

void QubitVertex::apply(int vop) {
  this->vop_code = *multiplication_table[vop, vop_code];
}

void QubitVertex::apply_opposite(int vop) {
  this->vop_code = *multiplication_table[vop_code, vop];
}

void QubitVertex::set_vop(int vop) { this->vop_code = vop; }

std::set<int> QubitVertex::non_isolated(int b) {
  std::set<int> result = neighbors;
  result.erase(b);

  return result;
}

bool QubitVertex::is_isolated(int b) {
  std::set<int> isolated = this->non_isolated(b);
  return isolated.size() == 0;
}

void QubitVertex::print() {
  std::cout << "vop: " << vop_code << ", ngbh: { ";

  for (auto i : neighbors) {
    std::cout << i << ' ';
  }

  std::cout << "}" << std::endl;
}

}  // namespace tangle::clifford
