#ifndef TANGLE_STATE_VECTOR_H_
#define TANGLE_STATE_VECTOR_H_

#include <complex>

typedef std::complex<float> complex;

class StateVector
{
public:
    int num_qubits;
    std::size_t num_amps;
    complex *state;

    StateVector(int num_qubits);

    // Utility Functions
    void print();
};

// } // namespace tangle::state_vector

#endif
