#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

#include <stdio.h>
#include <math.h>

#define Max_Size 10


int is_valid(int row, int col);
int is_identity(int arr[][Max_Size], int row, int col);
void print_matrix(int arr[][Max_Size], int row, int col);
void add_matrix(int arr1[][Max_Size], int arr2[][Max_Size], int result[][Max_Size], int row, int col);
void subtract_matrix(int arr1[][Max_Size], int arr2[][Max_Size], int result[][Max_Size], int row, int col);
void dot_product(int arr1[][Max_Size], int arr2[][Max_Size], int result[][Max_Size], int row, int col);
void transpose(int arr[][Max_Size], int result[][Max_Size], int row, int col);
double determinant(int arr[][Max_Size], int row, int col);
void get_submatrix(int arr[][Max_Size], int submatrix[][Max_Size], int row, int col, int exclude_row, int exclude_col);
void cofactor_matrix(int arr[][Max_Size], int cofactor[][Max_Size], int row, int col);
void adjoint(int arr[][Max_Size], int result[][Max_Size], int row, int col);
void inverse(int arr[][Max_Size], double result[][Max_Size], int row, int col);

#endif 