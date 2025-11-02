#include <iostream>
using namespace std;

void readMatrix(int A[3][50], int &rows, int &cols, int &n) {
    cout << "Enter rows, columns and number of non-zero elements: ";
    cin >> rows >> cols >> n;
    cout << "Enter row, column, and value for each non-zero element:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> A[0][i] >> A[1][i] >> A[2][i];
    }
}

void displayMatrix(int A[3][50], int n) {
    cout << "Row\tCol\tVal" << endl;
    for (int i = 0; i < n; i++) {
        cout << A[0][i] << "\t" << A[1][i] << "\t" << A[2][i] << endl;
    }
}

int transposeMatrix(int A[3][50], int T[3][50], int rows, int cols, int n) {
    int k = 0;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < n; j++) {
            if (A[1][j] == i) {
                T[0][k] = A[1][j];
                T[1][k] = A[0][j];
                T[2][k] = A[2][j];
                k++;
            }
        }
    }
    return k;
}

int addMatrices(int A[3][50], int B[3][50], int C[3][100], int n1, int n2, int rows1, int cols1, int rows2, int cols2) {
    if (rows1 != rows2 || cols1 != cols2) {
        cout << "Addition not possible." << endl;
        return 0;
    }
    int i = 0, j = 0, x = 0;
    while (i < n1 && j < n2) {
        if (A[0][i] < B[0][j] || (A[0][i] == B[0][j] && A[1][i] < B[1][j])) {
            C[0][x] = A[0][i];
            C[1][x] = A[1][i];
            C[2][x] = A[2][i];
            i++;
        } else if (B[0][j] < A[0][i] || (B[0][j] == A[0][i] && B[1][j] < A[1][i])) {
            C[0][x] = B[0][j];
            C[1][x] = B[1][j];
            C[2][x] = B[2][j];
            j++;
        } else {
            C[0][x] = A[0][i];
            C[1][x] = A[1][i];
            C[2][x] = A[2][i] + B[2][j];
            i++;
            j++;
        }
        x++;
    }
    while (i < n1) {
        C[0][x] = A[0][i];
        C[1][x] = A[1][i];
        C[2][x] = A[2][i];
        i++; x++;
    }
    while (j < n2) {
        C[0][x] = B[0][j];
        C[1][x] = B[1][j];
        C[2][x] = B[2][j];
        j++; x++;
    }
    return x;
}

int multiplyMatrices(int A[3][50], int B[3][50], int C[3][100], int rows1, int cols1, int rows2, int cols2, int n1, int n2) {
    if (cols1 != rows2) {
        cout << "Multiplication not possible." << endl;
        return 0;
    }
    int x = 0;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            int sum = 0;
            for (int p = 0; p < n1; p++) {
                if (A[0][p] == i) {
                    for (int q = 0; q < n2; q++) {
                        if (B[0][q] == A[1][p] && B[1][q] == j)
                            sum += A[2][p] * B[2][q];
                    }
                }
            }
            if (sum != 0) {
                C[0][x] = i;
                C[1][x] = j;
                C[2][x] = sum;
                x++;
            }
        }
    }
    return x;
}

int main() {
    int A[3][50], B[3][50], T[3][50], C[3][100];
    int rows1, cols1, n1, rows2, cols2, n2;

    cout << "Enter details for first matrix:" << endl;
    readMatrix(A, rows1, cols1, n1);

    cout << "Enter details for second matrix:" << endl;
    readMatrix(B, rows2, cols2, n2);

    cout << endl << "First Matrix:" << endl;
    displayMatrix(A, n1);

    cout << endl << "Second Matrix:" << endl;
    displayMatrix(B, n2);

    cout << endl << "Transpose of First Matrix:" << endl;
    int tn = transposeMatrix(A, T, rows1, cols1, n1);
    displayMatrix(T, tn);

    cout << endl << "Addition of Matrices:" << endl;
    int an = addMatrices(A, B, C, n1, n2, rows1, cols1, rows2, cols2);
    if (an > 0) displayMatrix(C, an);

    cout << endl << "Multiplication of Matrices:" << endl;
    int mn = multiplyMatrices(A, B, C, rows1, cols1, rows2, cols2, n1, n2);
    if (mn > 0) displayMatrix(C, mn);

    return 0;
}

