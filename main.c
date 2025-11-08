#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
int main() {
    Matrix *A =create_matrix(2, 2);
    Matrix *B =create_matrix(2, 2);
    Matrix *C =matrix_multiplication(A, B);
    printf("Resultant Matrix after Addition:\n");
    print_matrix(C);
    return 0;
}