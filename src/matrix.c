#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "time.h"
#include "matrix.h"

#define RAND_MAX 15

Matrix *m_create(const int row, const int col)
{
    Matrix *temp = (Matrix *)malloc(sizeof(Matrix));
    *(int *)&temp->rows = row;
    *(int *)&temp->cols = col;
    temp->data = (double *)malloc(row * col * sizeof(double));
    // m_fill(temp, 0);
    return temp;
}

void m_fill(Matrix *m, int n)
{
    for (int i = 0; i < m->rows; i++)
    {
        for (int j = 0; j < m->cols; j++)
        {
            m->data[(i * m->cols) + j] = n;
        }
    }
}

void m_free(Matrix *m)
{
    free(m->data);
    free(m);
    m = NULL;
}

void m_print(Matrix *m)
{
    printf("Rows: %d Columns: %d\n", m->rows, m->cols);
    for (int i = 0; i < m->rows; i++)
    {
        for (int j = 0; j < m->cols; j++)
        {
            printf("%1.0f ", m->data[i * m->cols + j]); // used to be %1.3f
        }
        printf("\n");
    }
}

Matrix *m_copy(Matrix *m)
{
    Matrix *temp = m_create(m->rows, m->cols);
    for (int i = 0; i < m->rows; i++)
    {
        for (int j = 0; j < m->cols; j++)
        {
            (temp->data)[i * m->cols + j] = (m->data)[i * m->cols + j];
        }
    }

    return temp;
}

void m_save(Matrix *m, char *file_name)
{
    FILE *fptr;
    int rows = m->rows;
    if ((fptr = fopen(file_name, "w")) == NULL)
    {
        printf("Error Opening File in m_save");
        exit(1);
    }

    fwrite(&m->rows, sizeof(int), 1, fptr);
    fwrite(&(m->cols), sizeof(int), 1, fptr);
    if (m->cols * m->rows != fwrite(m->data, sizeof(double), m->cols * m->rows, fptr))
    {
        printf("Error writing \n");
    }

    printf("Matrix saved \n");
    fclose(fptr);
}

Matrix *m_load(char *file_name)
{
    FILE *fptr;
    Matrix *temp;
    int read_rows;
    int read_cols;

    if ((fptr = fopen(file_name, "r")) == NULL)
    {
        printf("Error opening file in m_load");
        exit(1);
    }

    fread(&read_rows, sizeof(int), 1, fptr);
    fread(&read_cols, sizeof(int), 1, fptr);

    // Read size of rows and columns to make the matrix
    temp = m_create(read_rows, read_cols);
    if (temp->cols * temp->rows != fread(temp->data, sizeof(double), temp->cols * temp->rows, fptr))
    {
        printf("Something went wrong reading file \n");
        exit(1);
    }

    fclose(fptr);

    return temp;
}

void m_randomize(Matrix *m, int n)
{

    for (int i = 0; i < m->cols * m->rows; i++)
    {
        m->data[i] = rand();
    }
}

// Matrix *m_identity(int n)
// {
//     Matrix
// }
