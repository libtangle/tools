#include "tangle/foo.h"

namespace tangle {

auto bar(std::string const& x) -> size_t {
  return x.size();
}

} /* end namespace tangle */
