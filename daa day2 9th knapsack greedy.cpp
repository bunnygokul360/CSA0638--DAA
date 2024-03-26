	#include <stdio.h>
struct Item {
    int value;
    int weight;
};
int compare(const void *a, const void *b) {
    double ratio_a = (double)((struct Item *)a)->value / ((struct Item *)a)->weight;
    double ratio_b = (double)((struct Item *)b)->value / ((struct Item *)b)->weight;
    return (ratio_b > ratio_a) - (ratio_b < ratio_a);
}
double fractionalKnapsack(int W, struct Item arr[], int n) {
    // Sort items based on their value-to-weight ratio
    qsort(arr, n, sizeof(struct Item), compare);

    int currentWeight = 0; // Current weight in knapsack
    double finalValue = 0.0; // Final value of items selected

    // Loop through sorted items and fill knapsack
    for (int i = 0; i < n; i++) {
        // If adding the current item doesn't exceed the capacity, add it fully
        if (currentWeight + arr[i].weight <= W) {
            currentWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        // If adding the current item exceeds the capacity, add fraction of it
        else {
            int remainingWeight = W - currentWeight;
            finalValue += arr[i].value * ((double)remainingWeight / arr[i].weight);
            break; // Knapsack is full
        }
    }
    return finalValue;
}

int main() {
    int W, n;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    double maxValue = fractionalKnapsack(W, items, n);
    printf("The maximum value that can be obtained is: %.2lf\n", maxValue);
    return 0;
}

}
