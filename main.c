#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
int main() {
    int i=0;
    Matrix *A =malloc(sizeof(Matrix));
    Matrix *B =malloc(sizeof(Matrix));
    Matrix *C =malloc(sizeof(Matrix));
    *A = *create_matrix(2, 2);
    *B = *create_matrix(2, 2);
    *C = *matrix_addition(A, B);
    printf("Resultant Matrix after Addition:\n");
    for(; i<C->rows; i++){
        int j=0;
        for(; j<C->cols; j++){
            printf("%d ", C->data[i][j]);
        }
        printf("\n");
    }
    return 0;
}