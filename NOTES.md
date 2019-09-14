```
#include "clifford.h"

using namespace tangle::clifford;

#include <iostream>
#include <time.h>
#include <vector>
#include <utility>
// #include <functional>

int main()
{

  srand(time(NULL));

  /* Example of a GHZ State */
  int n = 5000;

  GraphState g(n);

  // g.h(0);
  // g.cx(0, 1);
  g.x(n / 2);

  std::cout << "Measured Value: ";

  for (int i = n - 1; i >= 0; i--)
  {
    std::cout << g.measure(i);
  }

  std::cout << std::endl;

  return 0;
}

```