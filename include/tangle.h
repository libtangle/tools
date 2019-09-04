#ifndef TANGLE_H_
#define TANGLE_H_

namespace tangle {

/* TYPES */
using uint = unsigned int;

/* QUANTUM SIMULATION BACKENDS */
class TangleBackend {
public:
    uint num_qubits;
};

} /* end namespace tangle */

#endif
