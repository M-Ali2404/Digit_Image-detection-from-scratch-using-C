#include "matrix.h"
#include "neural_network.h"
#include <stdlib.h>
#include <stdio.h>

// so my task is top load these data set we know its aw+b 
// we already have a matrix multiplier all we need is the a
// we have the training data set and its corresponding labels
// we have the grading set and its corresponding labels
// I will load the training set 
unsigned char buffer[784];
struct matrix * training(){
    FILE *trainInp = fopen("dataset/train-images.idx3-ubyte", "rb");
    if (trainInp == NULL){
        printf("empty training input");
        return 0;
    }
    else{
        fseek(trainInp, 16, SEEK_SET); // skip the MNIST header
        fread(buffer,1,784, trainInp);
        struct matrix *m = matrix_new(1, 784);
        for(int i = 0; i < 784; i++) {
            m->data[i] = (float)buffer[i] / 255.0f;
        }
        fclose(trainInp);
        return m; // Hand the matrix over to main
    }
}
// current progress are able to read the pixel value from these images now we just need 
//to transform them intro a matrix, I did this earlier so it should be fine