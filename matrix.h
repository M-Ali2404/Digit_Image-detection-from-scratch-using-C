#ifndef MATRIX
#define MATRIX
struct matrix{  // this is a blueprint for the matrix
    int row;
    int total;
    int column;    
    float *data;
};
// Below are prototypes so that the compiler doesnt throw errors 
struct matrix* matrix_new(int r, int c);
void clean(struct matrix *m);
void matrix_print(struct matrix *m);
#endif