#include <stdio.h>
#include <math.h>
int power(int base, int exponent) {
    if (exponent == 0)
        return 1;
    else
        return base * power(base, exponent - 1);
}
int countDigits(int number) {
    if (number == 0)
        return 0;
    else
        return 1 + countDigits(number / 10);
}
int isArmstrong(int number, int n) {
    if (number == 0)
        return 0;
    else
        return power(number % 10, n) + isArmstrong(number / 10, n);
}
int main() {
    int number, digitCount, sum, originalNumber;
    printf("Enter a number: ");
    scanf("%d", &number);
    digitCount = countDigits(number);
    sum = isArmstrong(number, digitCount);
    if (sum == number)
        printf("%d is an Armstrong number.\n", number);
    else
        printf("%d is not an Armstrong number.\n", number);
    
    return 0;
}

