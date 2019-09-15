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
#pragma omp parallel for
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
#pragma omp parallel for
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

void StateVector::apply_antidiagonal_gate(int target, Mat2x2 const &m)
{
    complex b = m.xy;
    complex c = m.yx;

    int max_threads = omp_get_max_threads();

    if (num_amps / 1L << (target + 1L) >= max_threads)
    {
#pragma omp parallel for
        for (std::size_t i = 0; i < num_amps; i += 1 << (target + 1))
        {
            for (std::size_t j = i; j < i + (1 << (target)); j++)
            {
                std::size_t zero_idx = j;
                std::size_t one_idx = j + (1 << target);

                complex zero_amp = state[zero_idx];
                complex one_amp = state[one_idx];

                state[zero_idx] = b * one_amp;
                state[one_idx] = c * zero_amp;
            }
        }
    }
    else
    {
        for (std::size_t i = 0; i < num_amps; i += 1 << (target + 1))
        {
#pragma omp parallel for
            for (std::size_t j = i; j < i + (1 << (target)); j++)
            {
                std::size_t zero_idx = j;
                std::size_t one_idx = j + (1 << target);

                complex zero_amp = state[zero_idx];
                complex one_amp = state[one_idx];

                state[zero_idx] = b * one_amp;
                state[one_idx] = c * zero_amp;
            }
        }
    }
}

// inline bool check_bit(std::size_t x, std::size_t t)
// {
//     std::size_t one = (std::size_t)1;
//     return x & (one << t);
// }

std::size_t insert_zero(int n, int target)
{
    int mask = (1 << target) - 1;
    return (n & mask) | ((n & (~mask)) << 1);
}

std::size_t insert_one(int n, int target)
{
    return insert_zero(n, target) | (1 << target);
}

void StateVector::apply_diagonal_gate(int target, Mat2x2 const &m)
{
    complex a = m.xx;
    complex d = m.yy;

#pragma omp parallel for
    for (std::size_t i = 0; i < num_amps / 2; i++)
    {
        int idx = insert_zero(i, target);
        state[idx] *= a;
    }

#pragma omp parallel for
    for (std::size_t i = 0; i < num_amps / 2; i++)
    {
        int idx = insert_one(i, target);
        state[idx] *= d;
    }
}

void StateVector::apply_phase_shift_gate(int target, complex phase)
{

#pragma omp parallel for
    for (std::size_t i = 0; i < num_amps / 2; i++)
    {
        int idx = insert_one(i, target);
        state[idx] *= phase;
    }
}
