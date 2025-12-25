#ifndef NEURAL_NETWORK
#define NEURAL_NETWORK
#include "matrix.h"
#include <math.h>

// Sigmoid activation function to squeeze numbers between 0 and 1

float sigmoid_activation(float x){
    float output = 1/(1 + exp(x*-1));
    return output;
}

float square(float x){
    float output = x * x;
        return output;
}

float error_functions(float x, float target){
    float output = (target - output)*(target - output);
    return output;
}
float ReLu(float x){
    if (x < 0) {
        x = 0.0;
    } 
    return x;
}
#endif