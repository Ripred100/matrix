#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix *m_create(int row, int col)
{
    Matrix *temp = (Matrix *)malloc(sizeof(Matrix));
    temp->rows = row;
    temp->cols = col;
    temp->data = (double *)malloc(row * col * sizeof(double));
    m_fill(temp, 0);
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
            printf("%1.3f ", m->data[i * m->cols + j]);
        }
        print("\n");
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
    if ((fptr = fopen(file_name, "wb")) == NULL)
    {
        printf("Error Opening File in m_save");
        exit(1);
    }

    if (m->cols * m->rows != fwrite(m->data, sizeof(double), m->cols * m->rows, fptr))
    {
        printf("Error writing \n");
    }
    fwrite(&m->rows, sizeof(int), 1, fptr);
    fwrite(&m->cols, sizeof(int), 1, fptr);

    printf("Matrix saved \n");
    fclose(fptr);
}

Matrix *m_load(char *file_name)
{
    FILE *fptr;
    Matrix *temp;
    int read_rows;
    int read_cols;

    if ((fptr = fopen(file_name, "rb")) == NULL)
    {
        printf("Error opening file in m_load");
        exit(1);
    }

    read_cols = fread(temp, sizeof(int), 1, fptr);
    read_rows = fread(temp, sizeof(int), 1, fptr);

    // Read size of rows and columns to make the matrix
    temp = m_create(read_rows, read_cols);

    temp->data = fread(temp->data, sizeof(double), temp->cols * temp->rows, fptr);

    return temp;
}
