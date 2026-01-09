#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

struct matrix *matrix_new(int r, int c){  //
    struct matrix *m = malloc(sizeof(struct matrix));
    m->row = r;
    m->column = c; 
    m->total = r *c;
    m->data = malloc(r*c*sizeof(float));
    return m;
}
void matrix_clean(struct matrix *m){ // we need this as the memory block can contain harmful data so it needs to be cleaned
    for(int i=0;i< m->total;i++){
        m->data[i] = 0;
    }
}
void matrix_free(struct matrix*m){  // This function is here to free the memory use to create a matrix
    free(m->data);
    free(m);
}
void matrix_randomise(struct matrix*m){  // Selects random numbers for the matrix, serves as a starting point later these numbers will 
    for(int i = 0; i < m->total; i++){     // be corrected through brackpropagation
        // m->data[i] = (((float)rand() / (float)RAND_MAX)*2)-1;
        m->data[i] = ((((float)rand() / (float)RAND_MAX)*2)-1)*0.01;
    }
}
void matrix_print(struct matrix*m){  // Prints out the matrix
    for(int i = 0;i<m->row;i++){
        for(int j= 0;j<m->column;j++){ //row major
            int index = (i * m->column) + j;
            printf("%.4f ", m->data[index]);
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
struct matrix* matrix_multiplication(struct matrix*m, struct matrix*n){ // Matrix multiplication general purpose, different to matrix_dot 
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
struct matrix* matrix_dot(struct matrix *m, struct matrix *n, struct matrix *res){ // different from mult, this writes to the buffer 
    if (m->column!=n->row){ 
        printf("multiplication error, dimensions are off");
        return 0;
        }
    for (int i = 0; i < m->row; i++) {
        for (int j = 0; j < n->column; j++) {
            float sum = 0;
            for (int k = 0; k < m->column; k++) {
                sum += m->data[i * m->column + k] * n->data[k * n->column + j];
            }
            sum = res->data[i * res->column + j];
        }
        
    }
    return 0;
}
void matrix_apply(struct matrix*m, float (*func)(float)){ 
    for(int i = 0;i<m->total;i++){
         m->data[i] = func(m->data[i]);
    }
}