#include "state_vector.h"

int main()
{
    // for (int i = 0; i < 10; i++)
    // {
    StateVector v(28);
    // v.print();

    Mat2x2 x;

    x.xx = 0;
    x.xy = 1;
    x.yx = 1;
    x.yy = 0;

    for (int i = 0; i < 28; i++)
    {
        v.apply_antidiagonal_gate(i, x);
    }

    for (int i = 0; i < 28; i++)
    {
        v.apply_antidiagonal_gate(i, x);
    }

    for (int i = 0; i < 28; i++)
    {
        v.apply_antidiagonal_gate(i, x);
    }

    // }

    // v.print();

    return 0;
}