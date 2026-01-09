#include "matrix.h"
#include "neural_network.h"
#include <stdlib.h>
#include <stdio.h>
#include "datasetloader.h"

struct matrix* nn_forward_press(struct matrix *input, layer *l,float (*func)(float)){ // 
   dense* d = (dense*)l->param; 
   matrix_dot(input,d->weights,l->output);
   matrix_add(l->output,d->bias);
   matrix_apply(l->output,func);  // allows us to pick which activation function we want
   return l->output;
}

layer* nn_layer_dense_init(int input, int output) { // 
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
// float cost_binary_cross_entropy(){
//     return;
// }
// float activation_error_functions(float guess, float target){
//     float diff = (target - guess)*(target - guess);
//     return diff;
// }
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
float matrix_errorfunction(struct matrix*m, int target){ // (output-expected)^2 later divided by all the n
    float mse = 0;
    for(int i = 0;i<m->total;i++){
        float val = m->data[i];
        mse += (val - target)*(val - target);
    }
    for(int i = 0; i < 10; i++) {
        float expected;
        if(i == target) {
            expected = 1.0; 
        } else {
            expected = 0.0; // This creates the "0"
        }

    return;
}
float derivative_ReLu(float x){
    if (x < 0) {
        x = 0.0;
    } 
    return 1;
}
float derivative_leaky_ReLu(float x) {
    if (x < 0) {
        return 0.01 * x; 
    }
    return 1;
}
float derivative_sigmoid(float x){
    float output = 1/(1 + exp(x*-1));
    return output;
}

void layer_print(layer* l) {
    printf("Layer (In: %d, Out: %d)\n", l->inputsize, l->outputsize);
    printf("Output Matrix:\n");
    matrix_print(l->output); // Reuse your matrix tool!
}
// void error_signal{
//     // 2 instances if its a hidden layer or if its not 

// }
