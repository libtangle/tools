#include "tangle/tangle.h"

namespace tangle
{

auto answer(int n) -> bool
{
  return n == 42;
}

auto foo(int n) -> int
{
  return 42 + n;
}

auto bar(std::string const &x) -> size_t
{
  return x.size();
}

} /* end namespace tangle */
