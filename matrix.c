#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

#define MAX(a,b) ((a) > (b) ? (a) : (b))

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

// Create a copy of a matrix
Matrix *copy_matrix(Matrix *mat)
{
    Matrix *copy = allocate_matrix(mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) 
    {
        for (int j = 0; j < mat->cols; j++) 
        {
            copy->data[i][j] = mat->data[i][j];
        }
    }
    return copy;
}

// Calculate the determinant of a matrix
double matrix_determinant(Matrix *mat)
{
    // Calculate the determinant using PLU decomposition
    if(mat->rows != mat->cols)
    {
        fprintf(stderr, "Determinant is only defined for square matrices\n");
        exit(1);
    }
    int pDetSign =1,n= mat->rows;
    Matrix *copy = copy_matrix(mat);
    for(int i=0;i<n;i++)
    {
        double pivot = copy->data[i][i];
        //finding pivot
        for(int j=i+1;j<n;j++)
        {
            if(fabs(pivot) < fabs(copy->data[j][i]))
            {
                pivot = copy->data[j][i];
                //swap rows
                double * temp = copy->data[i];
                copy->data[i] = copy->data[j];
                copy->data[j] = temp;
                pDetSign = -pDetSign;

                pivot = copy->data[i][i];  
            }
        }

        // Collumn of zeros return 0
        if (fabs(pivot) < 1e-12)
            return 0.0;
        
        // Elimination
        for(int j=i+1;j<n;j++)
        {
            double factor = copy->data[j][i] / pivot;
            for(int k=i;k<n;k++)
            {
                copy->data[j][k] -= factor * copy->data[i][k];
            }
        }
    }
    double det = (double)pDetSign;
    for(int i=0;i<n;i++)
    {
        det *= copy->data[i][i];
    }
    free_matrix(copy);
    return det;
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
