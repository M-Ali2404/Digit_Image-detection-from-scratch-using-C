#include "matrix.h"
#include "neural_network.h"
#include <stdlib.h>
#include <stdio.h>
void matrix_free(struct matrix*m){
    free(m->data);
    free(m);
}
void matrix_randomise(struct matrix*m){
    int total = m->column*m->row;
    for(int i = 0; i < total; i++){
        m->data[i] = (float)rand() / (float)RAND_MAX;
    }
}
void matrix_print(struct matrix*m){
    for(int i = 0;i<m->row;i++){
        for(int j= 0;j<m->column;j++){
            int index = (i * m->column) + j;
            printf("%.2f ", m->data[index]);
        }
        printf("\n");
    }
}
void matrix_multiplication(struct matrix*m){
    return;
}
int matrix_add(struct matrix*m, struct matrix*n){
    if(m->column == n->column && m->row == n->row){
        return 1; 
    }
        return 0;
}

int main() {
    // 1. Create a 3x3 matrix
    struct matrix *m = matrix_new(2,2);
    struct matrix *n = matrix_new(2,2);
    struct matrix *i = matrix_new(8,8);

    // 2. Wipe it clean
    clean(m);
    clean(n);

    // 3. Try to print it
    matrix_randomise(i);
    matrix_print(i);
    printf("\n");
    matrix_randomise(n);
    

    printf("Test 1: matrix_add same size -> ");
    if (matrix_add(m, n)) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    printf("Test 2: matrix_add correctly fails different size -> ");
    if (!matrix_add(n, i)) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

   
}
