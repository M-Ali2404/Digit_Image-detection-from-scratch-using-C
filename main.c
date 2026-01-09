#include "matrix.h"
#include "neural_network.h"
#include <stdlib.h>
#include <stdio.h>
#include "datasetloader.h"
#include <time.h>

int main() {
    srand(time(NULL));
    struct matrix *img_data;
    img_data = training();
    // matrix_print(img_data);
    // for(int i = 140;i<300; i++){
    //     printf("\n");
    //     printf("Index %d = %.2f\n", i, img_data->data[i]);
    // }
    // printf("\n","\n");
    // printf("%.2f",img_data->data[156]);
    layer* input =nn_layer_dense_init(784,10);
    nn_forward_press(img_data,input,activation_sigmoid);
    // for (int i = 0;i <10; i++){
    //     printf("%.5f",input->output->data[i]);
    //     printf("\n");
    // }
    matrix_errorfunction(input->output,5);
    

    // nn_layer_dense_init()
}

// mechanism, so we start and randomise right which is covered in dense_init
// then we do 