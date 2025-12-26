// #include <math.h>

// // Sigmoid activation function to squeeze numbers between 0 and 1

// float sigmoid_Activation(float x){
//     float output = 1/(1 + exp(x*-1));
//     return output;
// }

// float square(float x){
//     float output = x * x;
//         return output;
// }

// float error_functions(float x, float target){
//     float output = (target - output)*(target - output);
// }
// float ReLu(float x){
//     if (x < 0) {
//         x = 0.0;
//     } 
//     return x;
// }
// // struct neuron
// // {
// //     float value;
// // }
// struct Point{
//     float x;
//     float y;
// };
// float distance(struct Point p1, struct Point p2){
//     float delta_x = p2.x - p1.x;
//     float delta_y = p2.y - p1.y;
//     float distance = sqrt(square(delta_x) + square(delta_y));
//     return distance;
// }

// struct matrix{  // this is a blueprint for the matrix
//     int row;
//     int column;    
//     float *data;
// };

// struct matrix *matrix_new(int r, int c){
//     struct matrix *m = malloc(sizeof(struct matrix));
//     m->row = r;
//     m->column = c; 
//     m->data = malloc(r*c*sizeof(float));
//     return m;
// }
// void clean(struct matrix *m){ // we need this as the memory block contains harmful data so it needs to be cleaned
//     int total = m->row*m->column;
//     for(int i=0;i< total;i++){
//         m->data[i] = 0;
//     }
// }