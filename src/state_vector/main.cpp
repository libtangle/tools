#include "state_vector.h"

int main()
{
    StateVector v(3);
    // v.print();

    Mat2x2 x;

    x.xx = 0;
    x.xy = 1;
    x.yx = 1;
    x.yy = 0;

    v.apply_gate(1, x);
    v.apply_gate(, x);
    v.apply_gate(0, x);

    v.print();

    return 0;
}