#include <stdio.h>
#include <time.h>

#define N 100 
void multiplyMatrices(int A[N][N], int B[N][N], int C[N][N], int n);
void printMatrix(int matrix[N][N], int n);

int main() {
    int A[N][N], B[N][N], C[N][N];
    int n, i, j;

    printf("Enter the size of matrices (maximum %d): ", N);
    scanf("%d", &n);

    printf("Enter elements of matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    clock_t start_time = clock();
    multiplyMatrices(A, B, C, n);
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Resultant Matrix C:\n");
    printMatrix(C, n);

    printf("Time taken for matrix multiplication: %lf seconds\n", time_taken);

    return 0;
}
void multiplyMatrices(int A[N][N], int B[N][N], int C[N][N], int n) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
void printMatrix(int matrix[N][N], int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

