#include "state_vector.h"

int main()
{
    StateVector q(28);

    for (int i = 0; i < 28; i++)
    {
        q.h(i);
    }

    return 0;
}