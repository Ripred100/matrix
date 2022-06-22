#include "test.h"
#include "matrix.h"
#include "utils.h"
#include <time.h>

int verifyAlgo(void (*algo)())
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {

            // Create a matrix of varying size
            Matrix *ptr = m_create(i, j);
            m_fill(ptr, 9);

            clock_t t;
            t = clock();
            m_transpose(ptr);
            t = clock() - t;
            double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

            printf("transpose took %f seconds to execute \n", time_taken);

            m_free(ptr);
        }
    }
}