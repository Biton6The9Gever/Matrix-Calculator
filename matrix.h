#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <stdlib.h>
typedef struct Matrix {
    int rows;
    int cols;
    int **data;
}Matrix;

Matrix *create_matrix(int rows, int cols);

Matrix *matrix_addition(Matrix *A, Matrix *B);
#endif /* MATRIX_H */