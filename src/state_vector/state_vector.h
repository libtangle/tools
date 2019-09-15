#ifndef TANGLE_STATE_VECTOR_H_
#define TANGLE_STATE_VECTOR_H_

#include <complex>
#include "linalg.h"

typedef std::complex<float> complex;

class StateVector
{
public:
    int num_qubits;
    std::size_t num_amps;
    complex *state;

    StateVector(int num_qubits);

    // Quantum Gates
    void apply_gate(int target, Mat2x2 const &m);
    void apply_diagonal_gate(int target, Mat2x2 const &m);
    void apply_antidiagonal_gate(int target, Mat2x2 const &m);
    void apply_phase_shift_gate(int target, complex phase);
    void apply_controlled_gate(int control, int target, Mat2x2 const &m);

    void x(int target);
    void z(int target);
    void h(int target);

    // Utility Functions
    void print();
};

// Gate Definitions
extern Mat2x2 _x;
extern Mat2x2 _h;

// } // namespace tangle::state_vector

#endif
