#ifndef TANGLE_CLIFFORD_TABLES_H_
#define TANGLE_CLIFFORD_TABLES_H_

namespace tangle::clifford
{

extern int multiplication_table[24][24];
extern int cz_table[2][24][24][3];
extern int conjugation_table[24];
extern int measure_table[4][24][2];

enum DecompositionGate
{
    NegSqrtIX,
    SqrtIZ
};

extern DecompositionGate decomposition_table[24][5];

} // namespace tangle::clifford

#endif
