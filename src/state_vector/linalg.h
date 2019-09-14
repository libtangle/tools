#ifndef TANGLE_LINEAR_ALGEBRA_H_
#define TANGLE_LINEAR_ALGEBRA_H_

#include <complex>

typedef std::complex<float> complex;

/*
 * This header defines linear algebraic structures which are
 * used throughout Tangle. There will be many missing features.
 * 
 * The reason for avoiding existing linear algebra libraries is
 * to avoid an extra third-party dependency, and to allow for
 * flexibility within the tangle library.
 */

// A struct representing a 2 x 2 dimensional matrix.
// The storage convension is row-major ordering.
// https://github.com/ilyak/linalg/blob/master/linalg.h
struct Mat2x2
{
    complex xx, xy;
    complex yx, yy;
};

#endif
