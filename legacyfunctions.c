// void matrix_sigmoid(struct matrix*m){
//     for(int i = 0;i<m->row;i++){
//         for(int j= 0;j<m->column;j++){ //row major
//             int index = (i * m->column) + j;
//             if (m->data[index] < 0){
//             m->data[index] = 0;
//         }
//              m->data[index] = 1/(1 + exp(x*-1));
//         }
//     }
// }
// void matrix_squared(struct matrix*m){
//     for(int i = 0;i<m->row;i++){
//         for(int j= 0;j<m->column;j++){ //row major
//             int index = (i * m->column) + j;
//             m->data[index] = m->[data]*m->[data];
//     }
// }
// void matrix_errorfunction(struct matrix*m, int target){ // will not be used yet
//     for(int i = 0;i<m->row;i++){
//         for(int j= 0;j<m->column;j++){ //row major
//             int index = (i * m->column) + j;
//         float output = (m->data[index] - output)*(m->data[index] - output);
//     }
// }