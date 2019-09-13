#include "clifford.h"
#include <vector>

namespace tangle::clifford
{

GraphState::GraphState(int num_qubits)
{
    graph.initialize_graph(num_qubits);
}

void GraphState::apply(int vop, int target)
{
    graph.vertices[target].apply(vop);
}

void GraphState::h(int target) { this->apply(10, target); }
void GraphState::x(int target) { this->apply(1, target); }
void GraphState::y(int target) { this->apply(2, target); }
void GraphState::z(int target) { this->apply(3, target); }
void GraphState::id(int target) {}
void GraphState::s(int target) { this->apply(6, target); }
void GraphState::s_dagger(int target) { this->apply(5, target); }

void GraphState::cz(int control, int target)
{
    if (graph.vertices[control].is_isolated(target))
    {
        this->reduce_vop(control, target);
    }

    if (graph.vertices[target].is_isolated(control))
    {
        this->reduce_vop(target, control);
    }

    if (graph.vertices[control].is_isolated(target))
    {
        this->reduce_vop(control, target);
    }

    bool has_edge = graph.has_edge(control, target);
    int control_vop = graph.vertices[control].vop_code;
    int target_vop = graph.vertices[target].vop_code;

    int *cz_table_entry = cz_table[has_edge][control_vop][target_vop];

    graph.vertices[control].set_vop(cz_table_entry[1]);
    graph.vertices[target].set_vop(cz_table_entry[2]);

    if (has_edge != cz_table_entry[0])
    {
        graph.toggle_edge(control, target);
    }
}

void GraphState::cx(int control, int target)
{
    this->h(target);
    this->cz(control, target);
    this->h(target);
}

int GraphState::measure(int target, MeasurementBasis basis)
{
    int vop_conjugate = conjugation_table[graph.vertices[target].vop_code];
    int *measure_table_entry = measure_table[basis][vop_conjugate];

    int bare_basis = measure_table_entry[0];
    int phase = measure_table_entry[1];

    int choice = rand() % 2;

    if (bare_basis == MeasurementBasis::X)
    {
        choice = this->bare_measure_x(target, choice);
    }
    else if (bare_basis == MeasurementBasis::Y)
    {
        choice = this->bare_measure_y(target, choice);
    }
    else if (bare_basis == MeasurementBasis::Z)
    {
        choice = this->bare_measure_z(target, choice);
    }

    if (phase == -1)
    {
        choice = !choice;
    }

    return choice;
}

void GraphState::reduce_vop(int a, int b)
{
    // First select a swapping partner c
    int c;

    std::set<int> external = graph.vertices[a].non_isolated(b);
    if (external.size() > 0)
    {
        c = *external.begin();
        external.erase(c);
    }
    else
    {
        c = b;
    }

    DecompositionGate *d = decomposition_table[graph.vertices[a].vop_code];
    for (int i = 4; i >= 0; i--)
    {
        if (d[i] == DecompositionGate::NegSqrtIX)
        {
            this->local_complementation(a);
        }
        else if (d[i] == DecompositionGate::SqrtIZ)
        {
            this->local_complementation(b);
        }
    }

    // Now the vertex operator of `a` is 0, the identity.
}

void GraphState::local_complementation(int a)
{
    std::vector<int> ngbh(graph.vertices[a].neighbors.begin(), graph.vertices[a].neighbors.end());

    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            graph.toggle_edge(i, j);
        }
    }

    graph.vertices[a].apply_opposite(14);

    for (auto i : graph.vertices[a].neighbors)
    {
        graph.vertices[i].apply_opposite(6);
    }
}

int GraphState::bare_measure_x(int target, int choice)
{
    return 0;
}

int GraphState::bare_measure_y(int target, int choice) { return 0; }
int GraphState::bare_measure_z(int target, int choice) { return 0; }
// };

} // namespace tangle::clifford
