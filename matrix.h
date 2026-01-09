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
void matrix_clean(struct matrix *m);
void matrix_print(struct matrix *m);
void matrix_free(struct matrix* m);
void matrix_randomise(struct matrix* m);
void matrix_print(struct matrix* m);
int matrix_add(struct matrix* m, struct matrix* n);
struct matrix* matrix_multiplication(struct matrix* m, struct matrix* n);
struct matrix* matrix_dot(struct matrix* m, struct matrix* n, struct matrix* res);
void matrix_apply(struct matrix* m, float (*func)(float));

#endif