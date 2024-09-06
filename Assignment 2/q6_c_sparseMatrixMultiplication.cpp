#include<iostream>
using namespace std;

// Function to calculate the number of non-zero elements in the matrix
int calc_size(int** a, int rows, int cols) {
    int s = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (a[i][j] != 0) {
                s++;
            }
        }
    }
    return s;
}

// Function to generate the triplet matrix representation of the sparse matrix
void generateTripletMatrix(int** a, int rows, int cols, int **t, int size) {
    t[0][0] = rows;
    t[0][1] = cols;
    t[0][2] = size;

    int k = 1;  // Start filling from index 1
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (a[i][j] != 0) {
                t[k][0] = i;    // row index
                t[k][1] = j;    // column index
                t[k][2] = a[i][j];  // non-zero value
                k++;
            }
        }
    }
}

// Function to multiply two triplet matrices
void multiplyTripletMatrix(int** a, int** b, int** c, int size1, int size2, int rowsA, int colsB) {
    // Traverse through non-zero elements of first matrix
    for (int i = 1; i <= size1; i++) {
        for (int j = 1; j <= size2; j++) {
            // If the column of A matches the row of B, multiply and add to result C
            if (a[i][1] == b[j][0]) {
                // C[rowA][colB] += A[rowA][common] * B[common][colB]
                int rowA = a[i][0];
                int colB = b[j][1];
                c[rowA][colB] += a[i][2] * b[j][2];
            }
        }
    }
}

int main() {
    // Matrix A (3x3 sparse matrix)
    int A[3][3] = {
        {1, 0, 0},
        {0, 0, 2},
        {0, 3, 0}
    };

    // Matrix B (3x3 sparse matrix)
    int B[3][3] = {
        {0, 4, 0},
        {0, 0, 5},
        {6, 0, 0}
    };

    int rows = 3, cols = 3;

    // Convert 2D arrays to pointer arrays
    int** A_ptr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        A_ptr[i] = A[i];
    }
    
    int** B_ptr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        B_ptr[i] = B[i];
    }

    // Calculate the number of non-zero elements in both matrices
    int size1 = calc_size(A_ptr, rows, cols);
    int size2 = calc_size(B_ptr, rows, cols);

    // Allocate memory for triplet matrices
    int** t1 = new int*[size1 + 1];
    int** t2 = new int*[size2 + 1];
    for (int i = 0; i <= size1; i++) {
        t1[i] = new int[3];
    }
    for (int i = 0; i <= size2; i++) {
        t2[i] = new int[3];
    }

    // Generate the triplet matrices for A and B
    generateTripletMatrix(A_ptr, rows, cols, t1, size1);
    generateTripletMatrix(B_ptr, rows, cols, t2, size2);

    // Allocate memory for the result matrix C (3x3) and initialize it with 0
    int C[3][3] = {0};
    int** C_ptr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        C_ptr[i] = C[i];
    }

    // Perform matrix multiplication using the triplet matrix representation
    multiplyTripletMatrix(t1, t2, C_ptr, size1, size2, rows, cols);

    // Output the result matrix C
    cout << "-----------------Result of Sparse Matrix Multiplication----------------" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------------------------------------------------------------------------" << endl;
    int size3=calc_size(C_ptr,rows,cols);
    //Further we can convert this C Matrix to Triplet
    int** t3 = new int*[size3 + 1];
    for (int i = 0; i <= size3; i++) {
        t3[i] = new int[3];
    }
    generateTripletMatrix(C_ptr,rows,cols,t3,size3);

    cout << "-----------------Triplet of Sparse Matrix Multiplication----------------" << endl;
    for (int i = 0; i <= size3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << t3[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------------------------------------------------------------------------" << endl;

}
