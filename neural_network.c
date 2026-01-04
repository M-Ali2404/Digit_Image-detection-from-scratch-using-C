#include "matrix.h"
#include "neural_network.h"
#include <stdlib.h>
#include <stdio.h>
#include "datasetloader.h"

struct matrix* nn_forward_press(struct matrix *input, layer *l,float (*func)(float)){
   dense* d = (dense*)l->param; 
   matrix_dot(input,d->weights,l->output);
   matrix_add(l->output,d->bias);
   matrix_apply(l->output,func);  // allows us to pick which activation function we want
   return l->output;
}

layer* nn_layer_dense_init(int input, int output) {
    layer *l = malloc(sizeof(layer)); //
    dense *p = malloc(sizeof(dense)); //
    p->weights  = matrix_new(input,output); //
    p->bias = matrix_new(1,output); //
    matrix_randomise(p->weights);
    matrix_randomise(p->bias);
    l-> param = p; //
    l->inputsize = input;
    l->outputsize = output;
    l->output = matrix_new(1, output); //
    return l;
}
float loss_square(float x){
    float output = x * x;
        return output;
}
float cost_binary_cross_entropy(){
    return;
}
float activation_error_functions(float guess, float target){
    float diff = (target - guess)*(target - guess);
    return diff;
}
float activation_ReLu(float x){
    if (x < 0) {
        x = 0.0;
    } 
    return x;
}
float activation_leaky_ReLu(float x) {
    if (x < 0) {
        return 0.01 * x; 
    }
    return x;
}
float activation_sigmoid(float x){
    float output = 1/(1 + exp(x*-1));
    return output;
}
// void matrix_errorfunction(struct matrix*m, int target){ // will not be used yet
//     for(int i = 0;i<m->row;i++){
//         for(int j= 0;j<m->column;j++){ //row major
//             int index = (i * m->column) + j;
//         float output = (m->data[index] - output)*(m->data[index] - output);
//         }
//     }
// }

