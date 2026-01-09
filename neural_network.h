#ifndef NEURAL_NETWORK
#define NEURAL_NETWORK
#include "matrix.h"
#include <math.h>

float cost_binary_cross_entropy();   //  <----- Implement this soon

float activation_sigmoid(float x); // Sigmoid activation function to squeeze numbers between 0 and 1
float loss_square(float x); // squares the value resulting in a positive value
// float activation_error_functions(float x, float target); //produces and error function
float activation_ReLu(float x); // if x is below 0, it becomes 0
float activation_leaky_ReLu(float x);
float matrix_errorfunction(struct matrix*m, int target);
typedef struct {
    struct matrix* weights; 
    struct matrix* bias;
} dense; 

typedef struct {
    int inputsize;
    int outputsize;
    struct matrix *input;
    struct matrix *output;
    void* param; 
} layer;

layer* nn_layer_dense_init(int input, int output);
struct matrix* nn_forward_press(struct matrix *input, layer *l, float (*func)(float));
void layer_print(layer* l);
#endif