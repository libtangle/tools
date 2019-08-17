#ifndef TANGLE_FOO_H_
#define TANGLE_FOO_H_

#include <iostream>

namespace tangle {

auto answer(int n) -> bool;

auto foo(int n) -> int;

auto bar(std::string const&) -> size_t;

} /* end namespace tangle */

#endif
