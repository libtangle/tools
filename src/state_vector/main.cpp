#include "state_vector.h"

int main()
{
    StateVector v(29);

    for (int i = 0; i < 29; i++)
    {
        v.z(i);
    }

    return 0;
}