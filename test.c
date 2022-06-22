#include "test.h"
#include "matrix.h"
#include "utils.h"
#include <time.h>

#define DEBUG

int verifyAlgo()
{
    for (int i = 1; i < 10000; i++)
    {
        for (int j = 1; j < 10000; j++)
        {

            printf("New test for matrix size %dx%d \n", i, j);

            // Create a matrix of varying size
            Matrix *ptr = m_create(i, j);
            m_fill(ptr, 9);

            // printf("Matrix Before: ");
            // m_print(ptr);

            clock_t t;
            t = clock();
            Matrix *t_ptr = m_transpose(ptr);
            t = clock() - t;
            double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

            // printf("Matrix Before: ");
            // m_print(ptr);

            printf("transpose took %f seconds to execute \n", time_taken);

            m_free(ptr);
        }
    }
}