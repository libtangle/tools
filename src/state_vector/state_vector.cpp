#include "state_vector.h"

#include <iostream>
#include <stdlib.h>

StateVector::StateVector(int num_qubits)
{
    this->num_qubits = num_qubits;
    this->num_amps = 1L << num_qubits;

    // Allocate the required memory for the state vector
    std::size_t bytes = num_amps * sizeof(complex);
    state = (complex *)malloc(bytes);

    // Initialize the state vector
    state[0] = complex(1);

    for (std::size_t i = 1; i < num_amps; i++)
    {
        state[i] = complex(0);
    }
}

void StateVector::print()
{
    for (std::size_t i = 0; i < num_amps; i++)
    {
        complex amp = state[i];
        std::cout
            << i << ": "
            << std::real(amp)
            << (std::imag(amp) >= 0.0 ? " + " : " - ")
            << std::abs(std::imag(amp))
            << "i"
            << std::endl;
    }
}
