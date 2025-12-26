#ifndef NEURAL_NETWORK
#define NEURAL_NETWORK
#include "matrix.h"
#include <math.h>

// Sigmoid activation function to squeeze numbers between 0 and 1

float sigmoid_activation(float x);
float square(float x);
float error_functions(float x, float target);
float ReLu(float x);

#endif