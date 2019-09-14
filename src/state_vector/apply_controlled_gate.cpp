#include "state_vector.h"
#include "omp.h"
#include <iostream>

void StateVector::apply_gate(int target, Mat2x2 const &m)
{
    complex a = m.xx;
    complex b = m.xy;
    complex c = m.yx;
    complex d = m.yy;

    int max_threads = omp_get_max_threads();

    if (num_amps / 1L << (target + 1L) >= max_threads)
    {
        // #pragma omp parallel for
        for (std::size_t i = 0; i < num_amps; i += 1 << (target + 1))
        {
            for (std::size_t j = i; j < i + (1 << (target)); j++)
            {
                std::size_t zero_idx = j;
                std::size_t one_idx = j + (1 << target);

                complex zero_amp = state[zero_idx];
                complex one_amp = state[one_idx];

                state[zero_idx] = a * zero_amp + b * one_amp;
                state[one_idx] = c * zero_amp + d * one_amp;
            }
        }
    }
    else
    {
        for (std::size_t i = 0; i < num_amps; i += 1 << (target + 1))
        {
            // #pragma omp parallel for
            for (std::size_t j = i; j < i + (1 << (target)); j++)
            {
                std::size_t zero_idx = j;
                std::size_t one_idx = j + (1 << target);

                complex zero_amp = state[zero_idx];
                complex one_amp = state[one_idx];

                state[zero_idx] = a * zero_amp + b * one_amp;
                state[one_idx] = c * zero_amp + d * one_amp;
            }
        }
    }
}