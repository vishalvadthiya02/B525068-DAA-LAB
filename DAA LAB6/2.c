#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define N 3

void addMatrix(int A[N][N], int B[N][N], int C[N][N]) {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void multiplyMatrix(int A[N][N], int B[N][N], int C[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            C[i][j] = 0;
            for(int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}

bool isZeroMatrix(int A[N][N]) {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(A[i][j] != 0)
                return false;
    return true;
}

bool isSymmetric(int A[N][N]) {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < i; j++)
            if(A[i][j] != A[j][i])
                return false;
    return true;
}

double determinant(double mat[N][N], int n) {
    double det = 1;

    for(int i = 0; i < n; i++) {
        if(mat[i][i] == 0)
            return 0;

        for(int j = i + 1; j < n; j++) {
            double ratio = mat[j][i] / mat[i][i];

            for(int k = 0; k < n; k++)
                mat[j][k] -= ratio * mat[i][k];
        }
    }

    for(int i = 0; i < n; i++)
        det *= mat[i][i];

    return det;
}

void transposeInPlace(int A[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }
}

double dominantEigen(double A[N][N], double v[N], int iterations) {
    double v_new[N], lambda = 0;

    for(int iter = 0; iter < iterations; iter++) {
        for(int i = 0; i < N; i++) {
            v_new[i] = 0;

            for(int j = 0; j < N; j++)
                v_new[i] += A[i][j] * v[j];
        }

        lambda = 0;

        for(int i = 0; i < N; i++)
            if(fabs(v_new[i]) > fabs(lambda))
                lambda = v_new[i];

        for(int i = 0; i < N; i++)
            v[i] = v_new[i] / lambda;
    }

    return lambda;
}

int main() {
    return 0;
}