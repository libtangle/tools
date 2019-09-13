#include "clifford.h"

using namespace tangle::clifford;

#include <iostream>
#include <time.h>

int main()
{
  srand(time(NULL));

  /* Example of a GHZ State */

  GraphState g(2);

  // g.h(0);
  g.cz(0, 1);

  // std::cout << g.measure(0) << g.measure(1) << std::endl;

  // int a = rand() % 2;

  // std::cout << a << std::endl;

  return 0;
}
