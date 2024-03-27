#include <stdio.h>

void printPascalTriangle(int numRows) {
    int triangle[numRows][numRows];
  
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= i; j++) {
            triangle[i][j] = 0;
        }
    }
    
    
    for (int i = 0; i < numRows; i++) {
        triangle[i][0] = 1; 
        triangle[i][i] = 1; 
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    
   
    for (int i = 0; i < numRows; i++) {
        for (int k = 0; k < numRows - i - 1; k++) {
            printf(" ");
        }
        
        for (int j = 0; j <= i; j++) {
            printf("%d ", triangle[i][j]);
        }
        
        printf("\n");
    }
}

int main() {
    int numRows;

    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &numRows);

    if (numRows <= 0) {
        printf("Number of rows must be greater than zero.\n");
        return 1;
    }

    printPascalTriangle(numRows);

    return 0;
}

