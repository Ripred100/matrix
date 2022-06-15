#ifndef UTILS_H
#define UTILS_H

#include "matrix.h"


Matrix * m_add(Matrix * m1, Matrix * m2);
Matrix * m_multiply(Matrix * m1, Matrix * m2);
Matrix * m_subtract(Matrix * m1, Matrix * m2);
Matrix * m_dot(Matrix * m1, Matrix * m2);
Matrix * m_apply(MAT_t (*func)(MAT_t), Matrix * m);
Matrix * m_scale(MAT_t n, Matrix * m);
Matrix * m_addBias(MAT_t n, Matrix * m);
Matrix * m_transpose(Matrix * m);

#endif /* utils.h */