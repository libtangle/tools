#ifndef TANGLE_CLIFFORD_H_
#define TANGLE_CLIFFORD_H_

#include <set>
#include <vector>
#include "tables.h"

namespace tangle::clifford
{

class QubitVertex
{
public:
  int vop_code;
  std::set<int> neighbors;

  QubitVertex();
  QubitVertex(int vop);

  void set_vop(int vop);

  void apply(int vop);
  void apply_opposite(int vop);

  std::set<int> non_isolated(int b);
  bool is_isolated(int b);

  void print();
};

class QubitGraph
{
public:
  std::vector<QubitVertex> vertices;

  QubitGraph() {}

  void initialize_graph(int n);
  void toggle_edge(int a, int b);
  bool has_edge(int a, int b);
  void add_edge(int a, int b);
  void remove_edge(int a, int b);

  void print();
};

enum MeasurementBasis
{
  X = 1,
  Y = 2,
  Z = 3
};

class GraphState
{
  int n_qubits;
  QubitGraph graph;

public:
  GraphState(int num_qubits);

  void apply(int vop, int target);
  void h(int target);
  void x(int target);
  void y(int target);
  void z(int target);
  void id(int target);
  void s(int target);
  void s_dagger(int target);

  void cz(int control, int target);
  void cx(int control, int target);

  int measure(int target, MeasurementBasis basis = MeasurementBasis::Z);

  void reduce_vop(int a, int b);
  void local_complementation(int a);

  int bare_measure_x(int target, int choice);
  int bare_measure_y(int target, int choice);
  int bare_measure_z(int target, int choice);
};

} // namespace tangle::clifford

#endif
