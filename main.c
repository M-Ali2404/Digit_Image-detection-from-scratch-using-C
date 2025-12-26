#include "matrix.h"
#include "neural_network.h"
#include <stdlib.h>
#include <stdio.h>
void matrix_free(struct matrix*m){  // This function is here to free the memory use to create a matrix
    free(m->data);
    free(m);
}
void matrix_randomise(struct matrix*m){  // Selects random numbers for the matrix, serves as a starting point later these numbers will 
    for(int i = 0; i < m->total; i++){     // be corrected through brackpropagation
        m->data[i] = (float)rand() / (float)RAND_MAX;
    }
}
void matrix_print(struct matrix*m){  // Prints out the matrix
    for(int i = 0;i<m->row;i++){
        for(int j= 0;j<m->column;j++){ //row major
            int index = (i * m->column) + j;
            printf("%.2f ", m->data[index]);
        }
        printf("\n");
    }
}

int matrix_add(struct matrix*m, struct matrix*n){ // This is for adding matrixes 
    if(m->column != n->column || m->row != n->row){ // Matrix must be the same row and columns to add
        printf("%s","unfit");
        return -1;
    } else{
        for(int i = 0; i < m->total;i++){
            m->data[i] = m->data[i] + n->data[i];
        }
    }
    return 0;
}
struct matrix* matrix_multiplication(struct matrix*m, struct matrix*n){ // Matrix multiplication 
    if (m->column!=n->row){ // the first matrix columns must be the same as the the seconds row
        printf("multiplication error, dimensions are off");
        return 0;
        }
    struct matrix *result = matrix_new(m->row,n->column); 
    for (int i = 0; i < m->row; i++) {
        for (int j = 0; j < n->column; j++) {
            float sum = 0;
            for (int k = 0; k < m->column; k++) {
                sum += m->data[i * m->column + k] * n->data[k * n->column + j];
            }
            result->data[i * result->column + j] = sum;
        }
    }
    return result;
}

float square(float x){
    float output = x * x;
        return output;
}

float error_functions(float guess, float target){
    float diff = (target - guess)*(target - guess);
    return diff;
}
float ReLu(float x){
    if (x < 0) {
        x = 0.0;
    } 
    return x;
}
void matrix_errorfunction(struct matrix*m, int target){ // will not be used yet
    for(int i = 0;i<m->row;i++){
        for(int j= 0;j<m->column;j++){ //row major
            int index = (i * m->column) + j;
        float output = (m->data[index] - output)*(m->data[index] - output);
        }
    }
}
void matrix_apply(struct matrix*m, float (*func)(float)){ 
    for(int i = 0;i<m->row;i++){
         m->data[i] = func(m->data[i]);
    }
}
int main() {
    
    struct matrix *m = matrix_new(2,2);
    struct matrix *n = matrix_new(2,2);
    struct matrix *i = matrix_new(8,8);

    
    clean(m);
    clean(n);
    clean(i);
    
    matrix_randomise(i);
    matrix_randomise(m);

    // matrix_print(i);
    printf("\n");
    matrix_randomise(n);

    matrix_add(i,m);
    printf("\n");
    
    matrix_add(i,m);
    printf("\n");
    matrix_print(m);
    
    matrix_add(m,m);
    printf("\n");
    matrix_print(m);

    matrix_add(m,m);
    matrix_apply(m,ReLu);
    printf("\n");
    matrix_print(m);
    
    
   
}
