#ifndef MATRIX
#define MATRIX
struct matrix{  // this is a blueprint for the matrix
    int row;
    int column;    
    float *data;
};
struct matrix* matrix_new(int r, int c);
void clean(struct matrix *m);
void matrix_print(struct matrix *m);
#endif