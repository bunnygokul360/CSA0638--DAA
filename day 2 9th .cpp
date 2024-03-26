#include <stdio.h>

#define MAX_ITEMS 100
struct Item {
    int weight;
    int value;
};
int knapsack(struct Item items[], int n, int capacity) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double ratio1 = (double) items[i].value / items[i].weight;
            double ratio2 = (double) items[j].value / items[j].weight;
            if (ratio1 < ratio2) {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    int totalValue = 0;
    int currentWeight = 0;
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingWeight = capacity - currentWeight;
            totalValue += (double) remainingWeight / items[i].weight * items[i].value;
            break;
        }
    }

    return totalValue;
}

int main() {
    struct Item items[MAX_ITEMS];
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    int maxValue = knapsack(items, n, capacity);
    printf("Maximum value that can be put into the knapsack = %d\n", maxValue);

    return 0;
}

