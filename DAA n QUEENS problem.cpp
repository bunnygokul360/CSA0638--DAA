#include <stdio.h>
#include <stdbool.h>

#define N 8 

int board[N][N]; 
bool isSafe(int row, int col);
bool solveNQueens(int col);
void printSolution();

bool isSafe(int row, int col) {
    int i, j;

    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }


    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}


bool solveNQueens(int col) {
  
    if (col >= N) {
        return true;
    }

    for (int i = 0; i < N; i++) {
        
        if (isSafe(i, col)) {
          
            board[i][col] = 1;

            if (solveNQueens(col + 1)) {
                return true;
            }

            board[i][col] = 0;
        }
    }
    return false;
}

void printSolution() {
    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    if (solveNQueens(0)) {
        printSolution();
    } else {
        printf("No solution exists for the given N.\n");
    }

    return 0;
}

