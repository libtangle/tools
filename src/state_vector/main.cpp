#include "state_vector.h"

int main()
{
    StateVector v(28);

    for (int i = 0; i < 28; i++)
    {
        v.z(i);
    }

    return 0;
}