#include "matrix.h"
#include <stdlib.h>

struct matrix *matrix_new(int r, int c){
    struct matrix *m = malloc(sizeof(struct matrix));
    m->row = r;
    m->column = c; 
    m->data = malloc(r*c*sizeof(float));
    return m;
}
void clean(struct matrix *m){ // we need this as the memory block contains harmful data so it needs to be cleaned
    int total = m->row*m->column;
    for(int i=0;i< total;i++){
        m->data[i] = 0;
    }
}