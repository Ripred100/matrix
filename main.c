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

    // FILE *fp;cl 
    // char str[] = "This is tutorialspoint.com y";
    // int x = 1233;
    // fp = fopen("Test.txt", "w");
    // fwrite(str, 1, sizeof(str), fp);
    // fwrite(&x, sizeof(int), 1, fp);
    // fclose(fp);

    verifyAlgo();

    // Matrix *nw = m_load("SecondTest.txt");
    // m_print(nw);

    return 0;
}