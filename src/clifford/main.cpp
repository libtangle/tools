#include "clifford.h"

using namespace tangle::clifford;

#include <iostream>
#include <time.h>

int main()
{
  srand(time(NULL));

  QubitGraph g;
  g.initialize_graph(4);
  g.add_edge(0, 3);
  g.print();

  int a = rand() % 2;

  std::cout << a << std::endl;

  return 0;
}
