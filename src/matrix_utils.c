#include "matrix_utils.h"

int is_valid(int row, int col){
    return row != col ;
}

int is_identity(int arr[][Max_Size], int row, int col){
    if( is_valid(row, col) ){
        printf("InvalidMatrixError: Matrix should be of square type.\n");
        return 0;
    }

    for(int i = 0; i < row; i++){

        for(int j = 0; j < row; j++){
            
            if( (i == j && arr[i][j] != 1) || ( i != j && arr[i][j] != 0 )){
                return 0; //  Not a identity matrix
            }

        }

    }

    return 1; // It is A Identity Matrix
}


void print_matrix(int arr[][Max_Size], int row, int col){

    // checking if m and n under the size limit.
    if(row > Max_Size || col > Max_Size){
        printf("InvalidMatrixSizeError: Matrix Should be of size less than or equal to %dx%d.\n", Max_Size,Max_Size); 
        return;
    }

    // printing the matrix to stdout.
    for(int i = 0; i < abs(row); i++){

        for(int  j = 0; j < abs(col); j++){
            printf("%d\t", arr[i][j]); 
        }
        printf("\n");

    }
    
}


void add_matrix(int arr1[][Max_Size], int arr2[][Max_Size], int result[][Max_Size], int row, int col){
    // checking if its a square matrix.
    if( is_valid(row, col) ){
        printf("InvalidMatrixError: Matrix should be of square type.\n");
        return;
    }

    // checking if m and n under the size limit.
    if(row > Max_Size || col > Max_Size){
        printf("InvalidMatrixSizeError: Matrix Should be of size less than or equal to %dx%d.\n", Max_Size,Max_Size); 
        return;
    } 

    // main logic
    for(int i = 0; i <  abs(row); i++){

        for(int j = 0; j < abs(col); j++){
            result[i][j] = arr1[i][j] + arr2[i][j];
        }

    }
}

void subtract_matrix(int arr1[][Max_Size], int arr2[][Max_Size], int result[][Max_Size], int row, int col){
    // checking if its a square matrix.
    if( is_valid(row, col) ){
        printf("InvalidMatrixError: Matrix should be of square type.\n");
        return;
    }

    // checking if m and n under the size limit.
    if(row > Max_Size || col > Max_Size){
        printf("InvalidMatrixSizeError: Matrix Should be of size less than or equal to %dx%d.\n", Max_Size,Max_Size); 
        return;
    } 

    // main logic
    for(int i = 0; i <  abs(row); i++){

        for(int j = 0; j < abs(col); j++){
            result[i][j] = arr1[i][j] - arr2[i][j];
        }

    }
}

void dot_product(int arr1[][Max_Size], int arr2[][Max_Size], int result[][Max_Size], int row, int col){
    if( is_valid(row, col) ){
        printf("InvalidMatrixError: Matrix should be of square type.\n");
        return;
    }

    // checking if m and n under the size limit.
    if(row > Max_Size || col > Max_Size){
        printf("InvalidMatrixSizeError: Matrix Should be of size less than or equal to %dx%d.\n", Max_Size,Max_Size); 
        return;
    }

    //initialize Result matrix
    for(int i = 0; i < row; i++){

        for(int j = 0; j < col; j++){
            result[i][j] = 0; // creating an Null Matrix
        }

    }

    for(int i = 0; i < row; i++){

        for(int j = 0; j < col; j++){

            for(int k = 0; k < col; k++){
                result[i][j] += ( arr1[i][k] * arr2[k][j] ); // dot product
            }
        
        }
    
    }

}

void transpose(int arr[][Max_Size], int result[][Max_Size], int row, int col){
    if (row > Max_Size || col > Max_Size){
        printf("InvalidMatrixSizeError: Matrix should be of size less than or equal to %dx%d.\n", Max_Size, Max_Size); 
        return;
    } 

    for (int i = 0; i < row; i++){

        for (int j = 0; j < col; j++){
            result[j][i] = arr[i][j];
        }

    }
}

double determinant(int arr[][Max_Size], int row, int col){
    if (is_valid(row, col)){
        printf("InvalidMatrixError: Matrix should be of square type.\n");
        return -1;
    }

    if (row > Max_Size || col > Max_Size) {
        printf("InvalidMatrixSizeError: Matrix should be of size less than or equal to %dx%d.\n", Max_Size, Max_Size);
        return -1;
    }

    double temp[Max_Size][Max_Size];
    for (int i = 0; i < row; i++){

        for (int j = 0; j < col; j++){
            temp[i][j] = arr[i][j];
        }

    }

    double det = 1;
    for (int i = 0; i < row; i++) {

        if (temp[i][i] == 0) {
            int swapRow = i + 1;
            
            while (swapRow < row && temp[swapRow][i] == 0){
                swapRow++;
            }

            if (swapRow == row){
                return 0;
            }

            for (int k = 0; k < row; k++){
                double t = temp[i][k];
                temp[i][k] = temp[swapRow][k];
                temp[swapRow][k] = t;
            }

            det = -det;
        }

        for (int j = i + 1; j < row; j++){

            double factor = temp[j][i] / temp[i][i];

            for (int k = i; k < row; k++){
                temp[j][k] -= factor * temp[i][k];
            }

        }
        det *= temp[i][i];
    }

    return det;
}

void get_submatrix(int arr[][Max_Size], int submatrix[][Max_Size], int row, int col, int exclude_row, int exclude_col){
    int sub_i = 0;
    for (int i = 0; i < row; i++){

        if (i == exclude_row) continue;

        int sub_j = 0;

        for (int j = 0; j < col; j++){

            if (j == exclude_col) continue;

            submatrix[sub_i][sub_j] = arr[i][j];
            sub_j++;

        }

        sub_i++;
    }
}

void cofactor_matrix(int arr[][Max_Size], int cofactor[][Max_Size], int row, int col){
    int submatrix[Max_Size][Max_Size];

    if (is_valid(row , col)){
        printf("Matrix must be square for cofactor matrix.\n");
        return;
    }

    for (int i = 0; i < row; i++){

        for (int j = 0; j < col; j++){
            get_submatrix(arr, submatrix, row, col, i, j);
            double minor_det = determinant(submatrix, row - 1, col - 1); 
            cofactor[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * minor_det;
        }
        
    }
}

void adjoint(int arr[][Max_Size], int result[][Max_Size], int row, int col){
    int res[Max_Size][Max_Size];
    cofactor_matrix(arr, res, row, col);
    transpose(res, result, row, col);
}

void inverse(int arr[][Max_Size], double result[][Max_Size], int row, int col){
    if (is_valid(row, col)){
        printf("InvalidMatrixError: Matrix should be of square type.\n");
        return;
    }

    if (row > Max_Size || col > Max_Size){
        printf("InvalidMatrixSizeError: Matrix should be of size less than or equal to %dx%d.\n", Max_Size, Max_Size);
        return;
    }

    double det = determinant(arr, row, col);

    if (det == 0){
        printf("Inverse of matrix is not possible due to it being a singular matrix.\n");
        return;
    }

    int adj[Max_Size][Max_Size];
    adjoint(arr, adj, row, col);

    for (int i = 0; i < row; i++){

        for (int j = 0; j < col; j++){
            result[i][j] =  adj[i][j] / det;
        }

    }
}