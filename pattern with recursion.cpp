#include <stdio.h>

void printPattern(int n, int i, int j) {
    if (i > n) {
        return;
    }

    printf("%d ", j);

    if (i == j) {
        printf("\n");
        printPattern(n, i + 1, 1);
    } else {
        printPattern(n, i, j + 1);
    }
}

int main() {
    int n = 4; 
    printPattern(n, 1, 1);

    return 0;
}

