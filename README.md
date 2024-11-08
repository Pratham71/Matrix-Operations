# Matrix Operations Utility(testing branch)

This project provides a set of functions for performing various matrix operations on 2D arrays. It includes functions for checking matrix properties, performing arithmetic operations, calculating determinants, and finding the inverse of matrices. These operations are implemented in C and include input validation for error handling.

## Functions

### `int is_valid(int row, int col)`
- **Purpose:** Checks if the matrix is square (i.e., the number of rows equals the number of columns).
- **Parameters:**
  - `row`: The number of rows in the matrix.
  - `col`: The number of columns in the matrix.
- **Return:** Returns `1` if the matrix is not square (invalid), `0` otherwise.

### `int is_identity(int arr[][Max_Size], int row, int col)`
- **Purpose:** Checks if the given matrix is an identity matrix (a square matrix with 1 on the diagonal and 0 elsewhere).
- **Parameters:**
  - `arr[][Max_Size]`: The matrix to check.
  - `row`: The number of rows in the matrix.
  - `col`: The number of columns in the matrix.
- **Return:** Returns `1` if the matrix is an identity matrix, `0` otherwise.

### `void print_matrix(int arr[][Max_Size], int row, int col)`
- **Purpose:** Prints the given matrix to standard output.
- **Parameters:**
  - `arr[][Max_Size]`: The matrix to print.
  - `row`: The number of rows in the matrix.
  - `col`: The number of columns in the matrix.
- **Return:** None. Prints the matrix directly to the console.

### `void add_matrix(int arr1[][Max_Size], int arr2[][Max_Size], int result[][Max_Size], int row, int col)`
- **Purpose:** Adds two matrices of the same size and stores the result in a third matrix.
- **Parameters:**
  - `arr1[][Max_Size]`: The first matrix.
  - `arr2[][Max_Size]`: The second matrix.
  - `result[][Max_Size]`: The matrix to store the result.
  - `row`: The number of rows in the matrices.
  - `col`: The number of columns in the matrices.
- **Return:** None. The result matrix is updated with the sum.

### `void subtract_matrix(int arr1[][Max_Size], int arr2[][Max_Size], int result[][Max_Size], int row, int col)`
- **Purpose:** Subtracts one matrix from another and stores the result in a third matrix.
- **Parameters:**
  - `arr1[][Max_Size]`: The matrix to subtract from.
  - `arr2[][Max_Size]`: The matrix to subtract.
  - `result[][Max_Size]`: The matrix to store the result.
  - `row`: The number of rows in the matrices.
  - `col`: The number of columns in the matrices.
- **Return:** None. The result matrix is updated with the difference.

### `void dot_product(int arr1[][Max_Size], int arr2[][Max_Size], int result[][Max_Size], int row, int col)`
- **Purpose:** Performs matrix multiplication (dot product) on two matrices and stores the result in a third matrix.
- **Parameters:**
  - `arr1[][Max_Size]`: The first matrix.
  - `arr2[][Max_Size]`: The second matrix.
  - `result[][Max_Size]`: The matrix to store the result.
  - `row`: The number of rows in the matrices.
  - `col`: The number of columns in the matrices.
- **Return:** None. The result matrix is updated with the dot product.

### `void transpose(int arr[][Max_Size], int result[][Max_Size], int row, int col)`
- **Purpose:** Transposes the given matrix (swaps rows and columns) and stores the result in another matrix.
- **Parameters:**
  - `arr[][Max_Size]`: The matrix to transpose.
  - `result[][Max_Size]`: The matrix to store the transposed result.
  - `row`: The number of rows in the matrix.
  - `col`: The number of columns in the matrix.
- **Return:** None. The result matrix is updated with the transposed matrix.

### `double determinant(int arr[][Max_Size], int row, int col)`
- **Purpose:** Calculates the determinant of a square matrix.
- **Parameters:**
  - `arr[][Max_Size]`: The matrix for which the determinant is calculated.
  - `row`: The number of rows in the matrix.
  - `col`: The number of columns in the matrix.
- **Return:** The determinant of the matrix. Returns `-1` for errors or invalid matrices.

### `void get_submatrix(int arr[][Max_Size], int submatrix[][Max_Size], int row, int col, int exclude_row, int exclude_col)`
- **Purpose:** Extracts a submatrix from a given matrix by excluding a specified row and column.
- **Parameters:**
  - `arr[][Max_Size]`: The original matrix.
  - `submatrix[][Max_Size]`: The matrix to store the submatrix.
  - `row`: The number of rows in the original matrix.
  - `col`: The number of columns in the original matrix.
  - `exclude_row`: The row to exclude from the submatrix.
  - `exclude_col`: The column to exclude from the submatrix.
- **Return:** None. The submatrix is updated with the extracted values.

### `void cofactor_matrix(int arr[][Max_Size], int cofactor[][Max_Size], int row, int col)`
- **Purpose:** Computes the cofactor matrix for a given square matrix. The cofactor matrix is used in finding the adjoint and inverse of a matrix.
- **Parameters:**
  - `arr[][Max_Size]`: The matrix to compute the cofactor for.
  - `cofactor[][Max_Size]`: The matrix to store the cofactor matrix.
  - `row`: The number of rows in the matrix.
  - `col`: The number of columns in the matrix.
- **Return:** None. The cofactor matrix is updated with the computed values.

### `void adjoint(int arr[][Max_Size], int result[][Max_Size], int row, int col)`
- **Purpose:** Computes the adjoint matrix of a given matrix by calculating the cofactor matrix and then transposing it.
- **Parameters:**
  - `arr[][Max_Size]`: The matrix to compute the adjoint for.
  - `result[][Max_Size]`: The matrix to store the adjoint matrix.
  - `row`: The number of rows in the matrix.
  - `col`: The number of columns in the matrix.
- **Return:** None. The adjoint matrix is updated with the computed values.

### `void inverse(int arr[][Max_Size], double result[][Max_Size], int row, int col)`
- **Purpose:** Computes the inverse of a given matrix by calculating its adjoint and dividing by the determinant.
- **Parameters:**
  - `arr[][Max_Size]`: The matrix to compute the inverse for.
  - `result[][Max_Size]`: The matrix to store the inverse matrix.
  - `row`: The number of rows in the matrix.
  - `col`: The number of columns in the matrix.
- **Return:** None. The inverse matrix is updated. If the matrix is singular (determinant is zero), an error message is printed.

## Constants
- **`Max_Size`:** The maximum size of the matrix (for both rows and columns). This constant is used to ensure that the matrix does not exceed the defined size during operations.

## Error Handling
Several checks are performed throughout the functions to ensure the validity of the matrix:
- **Square Matrix:** Ensures the matrix is square (for operations like determinant, cofactor matrix, inverse, etc.).
- **Matrix Size:** Ensures that the matrix size does not exceed the defined maximum size (`Max_Size`).
- **Singular Matrix:** The inverse function checks for a zero determinant, which would make the matrix singular and not invertible.

## Conclusion
This utility file provides robust functions for basic matrix operations, including matrix addition, subtraction, multiplication, and more advanced operations like finding determinants, adjoints, and inverses. Input validation ensures that errors are caught early, making the functions reliable for matrix calculations.
