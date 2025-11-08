#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

// Allocates an empty matrix (no user input)
Matrix *allocate_matrix(int rows, int cols);

// Creates a matrix and fills it with user input
Matrix *create_matrix(int rows, int cols);

// Adds two matrices
Matrix *matrix_addition(Matrix *A, Matrix *B);

Matrix *matrix_multiplication(Matrix *A, Matrix *B);

// Print a matrix to the console
void print_matrix(Matrix *mat);

// Frees all memory used by a matrix
void free_matrix(Matrix *mat);

#endif
