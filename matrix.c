#include "matrix.h"

Matrix *create_matrix(int rows, int cols){
    Matrix *mat = malloc(sizeof(Matrix));
    int i=0;
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
    
    for(;i<rows; i++){
        mat->data[i] =malloc(cols * sizeof(int));
        int j=0;
        if (mat->data[i] == NULL) {
            int k = 0;
            fprintf(stderr, "Memory allocation failed for row %d.\n", i);

            /* free previously allocated rows before exiting */
            for (;k < i; k++) free(mat->data[k]);
            free(mat->data);
            free(mat);
            exit(1);
        }       
        for(;j<cols;j++){
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
}