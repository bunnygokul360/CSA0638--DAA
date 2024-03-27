#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100 

int set[MAX_SIZE]; 
int n;
bool subsetSum(int sum, int index) {
    if (sum == 0) {
        return true; 
    }

    if (index >= n || sum < 0) {
        return false; 
    }

  
    if (subsetSum(sum - set[index], index + 1)) {
        return true;
    }

    return subsetSum(sum, index + 1);
}

int main() {
    int sum; 
    printf("Enter the size of the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }


    printf("Enter the target sum: ");
    scanf("%d", &sum);

    if (subsetSum(sum, 0)) {
        printf("Subset with the sum %d exists.\n", sum);
    } else {
        printf("Subset with the sum %d does not exist.\n", sum);
    }

    return 0;
}

