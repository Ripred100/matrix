#include "utils.h"
#define DEBUG
/*
Function m_add
--------------
takes the pointer to 2 matricies, m1 and m2 (defined in matrix.h), and preforms an elementwise addition of m2 on m1.
m2 is unchanged.

Returns: Adress of m1.
*/
Matrix *m_add(Matrix *m1, Matrix *m2)
{
    if (m1->cols == m2->cols && m1->rows == m2->rows)
    {
        // Structure of Matrix stype is flat (1D). Adition can be done elementwise
        for (int i = 0; i < m1->cols * m1->rows; i++)
        {
            m1->data[i] = m1->data[i] + m2->data[i];
        }
        return m1;
    }
    else
    {
        printf("ERROR: Dimension mismatch in m_add \n");
        m_print(m1);
        m_print(m2);

        exit(2);
    }
}

/*
Function m_multiply
---------------
takes pointer to 2 matricies, m1 and m2 (Defined in matrix.h), and preforms matrix multiplication.

Returns: pointer to new matrix
*/
Matrix *m_multiply(Matrix *m1, Matrix *m2)
{
    if (m1->cols == m2->rows)
    {
        Matrix *mSol = m_create(m1->rows, m2->cols);
        m_fill(mSol, 0);

        for (int i = 0; i < mSol->cols; i++)
        {

            for (int j = 0; j < mSol->rows; j++)
            {
                // For each loop of i and j, mSol<i,j> is being filled.

                for (int itter = 0; itter < m1->cols; itter++)
                {
                    mSol->data[DIM(mSol->cols, i, j)] += (m1->data[DIM(m1->cols, i, itter)]) * (m2->data[DIM(m2->cols, itter, j)]);
                }
            }
        }
        return mSol;
    }
    else
    {
        printf("ERROR: Dimension mismatch in m_multiply \n");
        m_print(m1);
        m_print(m2);

        exit(2);
    }
}

Matrix *m_subtract(Matrix *m1, Matrix *m2)
{
    if (m1->cols == m2->cols && m1->rows == m2->rows)
    {
        // Structure of Matrix stype is flat (1D). Subtraction can be done elementwise
        for (int i = 0; i < m1->cols * m1->rows; i++)
        {
            m1->data[i] = m1->data[i] - m2->data[i];
        }
        return m1;
    }
    else
    {
        printf("ERROR: Dimension mismatch in m_add \n");
        m_print(m1);
        m_print(m2);

        exit(2);
    }
}

// DO NOT USE. WIP
Matrix *m_dot(Matrix *m1, Matrix *m2)
{
    if (m1->cols == m2->rows == 1)
    {
        Matrix *mSol = m_create(m1->rows, m2->cols);
        m_fill(mSol, 0);

        for (int i = 0; i < mSol->cols; i++)
        {

            for (int j = 0; j < mSol->rows; j++)
            {
                // For each loop of i and j, mSol<i,j> is being filled.

                for (int itter = 0; itter < m1->cols; itter++)
                {
                    mSol->data[DIM(mSol->cols, i, j)] += (m1->data[DIM(m1->cols, i, itter)]) * (m2->data[DIM(m2->cols, itter, j)]);
                }
            }
        }
        return mSol;
    }
    else
    {
        printf("ERROR: Dimension mismatch in m_multiply \n");
        m_print(m1);
        m_print(m2);

        exit(2);
    }
}

/*
Function m_apply
----------------
Takes a pointer to a function *func that takes an argument of type MAT_t and returns a variable of type MAT_t, and a pointer to a matrix *m.
It calls the function on each element of matrix m.

Returns: pointer to matrix m
*/
Matrix *m_apply(MAT_t (*func)(MAT_t), Matrix *m)
{
    for (int i = (m->cols * m->rows) - 1; i >= 0; i--)
    {
        m->data[i] = func(m->data[i]);
    }
    return m;
}

Matrix *m_scale(MAT_t n, Matrix *m)
{
    for (int i = (m->cols * m->rows) - 1; i >= 0; i--)
    {
        m->data[i] = (m->data[i]) * n;
    }
    return m;
}

Matrix *m_addBias(MAT_t n, Matrix *m)
{
    for (int i = (m->cols * m->rows) - 1; i >= 0; i--)
    {
        m->data[i] = (m->data[i]) + n;
    }
    return m;
}

Matrix *m_transpose(Matrix *m)
{
    // Special case for when matrix is a 1xn or nx1 matrix
    if (m->cols == 1 || m->rows == 1)
    {
        int temp = m->cols;
        *(int *)&m->cols = m->rows;
        *(int *)&m->rows = temp;
        return m;
    }
    else
    {
        Matrix *mTrans = m_create(m->cols, m->rows);

#pragma omp parallel for
        for (int n = 0; n < (m->cols * m->rows); n++)
        {
            int i = n / m->rows;
            int j = n % m->rows;
            mTrans->data[n] = m->data[m->cols * j + i];
        }
        m_free(m);
    }   
}
