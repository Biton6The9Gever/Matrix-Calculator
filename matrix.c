#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

// Allocate memory for a matrix of given dimensions
Matrix *allocate_matrix(int rows, int cols) 
{
    Matrix *mat = malloc(sizeof(Matrix));
    if (mat == NULL) 
    {
        fprintf(stderr, "Memory allocation failed for matrix struct\n");
        exit(1);
    }

    mat->rows = rows;
    mat->cols = cols;

    mat->data = malloc(rows * sizeof(double *));
    if (mat->data == NULL) 
    {
        fprintf(stderr, "Memory allocation failed for matrix data pointers\n");
        free(mat);
        exit(1);
    }

    for (int i = 0; i < rows; i++) 
    {
        mat->data[i] = malloc(cols * sizeof(int));
        if (mat->data[i] == NULL) 
        {
            fprintf(stderr, "Memory allocation failed for row %d\n", i);
            for (int k = 0; k < i; k++) free(mat->data[k]);
            free(mat->data);
            free(mat);
            exit(1);
        }
    }

    return mat;
}

// Create a matrix by reading elements from user input
Matrix *create_matrix(int rows, int cols) {
    Matrix *mat = allocate_matrix(rows, cols);

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%le", &(mat->data[i][j]));
        }
    }

    return mat;
}

// Add two matrices and return the result
Matrix *matrix_addition(Matrix *A, Matrix *B)
{ 
    if (A->rows != B->rows || A->cols != B->cols)
    {
        fprintf(stderr, "Matrix dimensions do not match for addition\n");
        exit(1);
    }

    Matrix *result = allocate_matrix(A->rows, A->cols);

    for (int i = 0; i < A->rows; i++)
    {
        for (int j = 0; j < A->cols; j++) 
        {
            result->data[i][j] = A->data[i][j] + B->data[i][j];
        }
    }

    return result;
}

// Subtract two matrices and return the result
Matrix *matrix_subtruction(Matrix *A, Matrix *B)
{ 
    if (A->rows != B->rows || A->cols != B->cols)
    {
        fprintf(stderr, "Matrix dimensions do not match for subtraction\n");
        exit(1);
    }

    Matrix *result = allocate_matrix(A->rows, A->cols);
    for (int i = 0; i < A->rows; i++)
    {
        for (int j = 0; j < A->cols; j++) 
        {
            result->data[i][j] = A->data[i][j] - B->data[i][j];
        }
    }

    return result;
}

// Multiply two matrices and return the result
Matrix *matrix_multiplication(Matrix *A, Matrix *B)
{

    if(A->cols !=B->rows)
    {
        fprintf(stderr, "Matrix dimensions do not match for multiplication\n");
        exit(1);
    }

    Matrix *result = allocate_matrix(A->rows, B->cols);

    for(int i=0; i <A->rows; i++)
    {
        for(int j=0; j< B->cols; j++)
        {
            result->data[i][j]=0;
            for(int k=0; k< A->cols; k++)
            {
                result->data[i][j] +=A->data[i][k] * B->data[k][j];
            }
        }
    }

    return result;
}

// Multiply a matrix by a scalar and return the result
Matrix *matrix_scalar_multiplication(Matrix *A, double scalar)
{
    Matrix *result = allocate_matrix(A->rows,A->cols);
    for(int i=0;i<A->cols;i++)
    {
        for(int j=0;j<A->rows;j++)
        {
            result->data[i][j]= A->data[i][j] * scalar;
        }
    }
}

// Print a matrix to the console
void print_matrix(Matrix *mat) 
{
    for (int i = 0; i < mat->rows; i++) 
    {
        for (int j = 0; j < mat->cols; j++) 
        {
            printf("%f ", mat->data[i][j]);
        }
        printf("\n");
    }
}

// Free all memory used by a matrix
void free_matrix(Matrix *mat) 
{
    if (mat == NULL) return;
    for (int i = 0; i < mat->rows; i++)
        free(mat->data[i]);
    free(mat->data);
    free(mat);
}
