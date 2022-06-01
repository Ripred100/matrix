#include "matrix.h"
#include "stdio.h"

int main()
{

    printf("hello. \n");
    Matrix *m = m_create(2, 3);
    m_fill(m, 3);
    m_print(m);

    return 0;
}