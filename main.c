#include "matrix.h"
#include "neural_network.h"
#include <stdlib.h>
#include <stdio.h>
#include "datasetloader.h"
#include <time.h>

int main() {
    srand(time(NULL));
    // in = matrix_new(28,28);
    layer *l = nn_layer_dense_init(784, 10);
    struct matrix *test_input = matrix_new(1, 784);
    matrix_randomise(test_input);
    nn_forward_press(test_input, l, activation_leaky_ReLu);
    printf("Network Output:\n");
    matrix_print(l->output);

}
