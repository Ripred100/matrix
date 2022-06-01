#ifndef MATRIX_H
#define MATRIX_H

typedef struct
{
    double *data;
    int rows;
    int cols;
} Matrix;

Matrix *m_create(int row, int col);
void m_fill(Matrix *m, int n);
void m_free(Matrix *m);
void m_print(Matrix *m);
Matrix *m_copy(Matrix *m);
void m_save(Matrix *m, char *file_string);
Matrix *m_load(char *file_string);
// Matrix *m_identity(int n);
//  void m_randomize(Matrix *m, int n);
//  int m_argmax(Matrix *m);
//  Matrix *m_flatten(Matrix *m, int axis);

#endif /* matrix.h */