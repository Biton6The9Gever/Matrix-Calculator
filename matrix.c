#include "matrix.h"

Matrix *create_matrix(int rows, int cols){
    Matrix *mat = malloc(sizeof(Matrix));
    
    if(mat == NULL){
        fprintf(stderr, "Memory allocation failed for matrix struct \n");
        exit(1);
    }

    mat->rows = rows;
    mat->cols = cols;

    mat->data = (int **)malloc(rows * sizeof(int *));

     if (mat->data == NULL) {
        fprintf(stderr, "Memory allocation failed for matrix data \n");
        free(mat);
        exit(1);
    }
    
    for(int i=0;i<rows; i++){
        mat->data[i] =malloc(cols * sizeof(int));
        
        if (mat->data[i] == NULL) {
            int k = 0;
            fprintf(stderr, "Memory allocation failed for row %d.\n", i);

            /* free previously allocated rows before exiting */
            for (;k < i; k++) free(mat->data[k]);
            free(mat->data);
            free(mat);
            exit(1);
        }       
        for(int j=0;j<cols;j++){
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &(mat->data[i][j]));
        }
    }
    return mat;
}

Matrix *matrix_addition(Matrix *A, Matrix *B){   
    if(A->rows != B->rows || A->cols != B->cols){
        fprintf(stderr, "Matrix dimensions do not match for addition \n");
        exit(1);
    }

    Matrix *result=malloc(sizeof(Matrix));
    if(result==NULL){
        fprintf(stderr, "Memory allocation failed for matrix struct \n");
        exit(1);
    }

    result->rows = A->rows;
    result->cols = A->cols;

    result->data = malloc(result->rows * sizeof(int *));
    if (result->data == NULL) {
        fprintf(stderr, "Memory allocation failed for data pointers\n");
        free(result);
        exit(1);
    }

    for(int i=0;i<A->rows;i++){
        
        result->data[i] =malloc(A->cols * sizeof(int));
        if (result->data[i] == NULL) {
            int k = 0;
            fprintf(stderr, "Memory allocation failed for row %d.\n", i);
            /* free previously allocated rows before exiting */
            for (;k < i; k++) free(result->data[k]);
            free(result->data);
            free(result);
            exit(1);
        }   
        for(int j=0;j<A->cols;j++){
            result->data[i][j]= A->data[i][j] + B->data[i][j];
        }
    }
    return result;
}