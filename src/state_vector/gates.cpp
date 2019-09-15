#include "state_vector.h"

Mat2x2 _x{0, 1, 1, 0};
Mat2x2 _h{0.70710678118654752440, 0.70710678118654752440, 0.70710678118654752440, -0.70710678118654752440};

void StateVector::z(int target)
{
    this->apply_phase_shift_gate(target, -1);
}

void StateVector::x(int target)
{
    this->apply_antidiagonal_gate(target, _x);
}

void StateVector::h(int target)
{
    this->apply_gate(target, _h);
}