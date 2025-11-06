#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
int main() {
   
    struct Matrix *A =malloc(sizeof(struct Matrix));
    *A = *create_matrix(2, 2);
    return 0;
}