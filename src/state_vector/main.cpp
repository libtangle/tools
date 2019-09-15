#include "state_vector.h"
#include <iostream>
#include <bitset>

int main()
{
    StateVector v(28);
    // v.print();

    Mat2x2 z;

    z.xx = 1;
    z.xy = 0;
    z.yx = 0;
    z.yy = -1;

    // for (int j = 0; j < 10; j++)
    // {
    for (int i = 0; i < 28; i++)
    {
        v.apply_diagonal_gate(i, z);
    }
    // }

    return 0;
}