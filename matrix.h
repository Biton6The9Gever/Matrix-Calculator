#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int rows;
    int cols;
    double **data;
} Matrix;

// Allocates an empty matrix (no user input)
Matrix *allocate_matrix(int rows, int cols);

// Creates a matrix and fills it with user input
Matrix *create_matrix(int rows, int cols);

// Adds two matrices
Matrix *matrix_addition(Matrix *A, Matrix *B);

// Subtracts two matrices
Matrix *matrix_subtruction(Matrix *A, Matrix *B);

// Multiplies two matrices
Matrix *matrix_multiplication(Matrix *A, Matrix *B);

// Multiplies a matrix by a scalar
Matrix *matrix_scalar_multiplication(Matrix *A, double scalar);

// Creates a copy of a matrix
Matrix *copy_matrix(Matrix *mat);

// Calculates the determinant of a matrix
double matrix_determinant(Matrix *mat);

// Print a matrix to the console
void print_matrix(Matrix *mat);

// Frees all memory used by a matrix
void free_matrix(Matrix *mat);


#endif
