#include <stdio.h>

// Define the horner function
int horner(int x, int a[], int n) {
    int result = a[n];
    for (int i = n - 1; i >= 0; i--) {

        result = (result * x) + a[i];

    }
    return result;
}

int main() {
    int a[] = {3, -2, 1, -3, 2};
    int n = 4; // Corrected to n-1
    int x = 2;
    printf("The value of polynomial at x = %i is %i\n", x, horner(x, a, n));
    return 0;
}