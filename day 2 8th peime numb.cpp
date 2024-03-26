#include <stdio.h>
#include <stdbool.h>
bool isPrime(int n, int divisor);
void generatePrimes(int n, int current) {
    if (current <= n) {
        if (isPrime(current, 2)) {
            printf("%d ", current);
        }
        generatePrimes(n, current + 1);
    }
}
bool isPrime(int n, int divisor) {
    if (n <= 2) {
        return (n == 2) ? true : false;
    }
    if (divisor * divisor > n) {
        return true;
    }
    if (n % divisor == 0) {
        return false;
    }
    return isPrime(n, divisor + 1);
}
int main() {
    int n;
    printf("Enter the limit to generate prime numbers up to: ");
    scanf("%d", &n);
    printf("Prime numbers up to %d are: ", n);
    generatePrimes(n, 2);
    printf("\n");
    return 0;
}

