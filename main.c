#include "matrix.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "test.h"

int main()
{
    srand(time(NULL));

    printf("hello. \n");
    // Matrix *m = m_create(4, 3);
    // m_fill(m, 3);
    // m_print(m);
    // m_save(m, "SecondTest.txt");

    verifyAlgo();

    // Matrix *nw = m_load("SecondTest.txt");
    // m_print(nw);

    return 0;
}