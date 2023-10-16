#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Function to calculate the sum of elements in an array
int calculateSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to calculate the product of elements in an array
int calculateProduct(int arr[], int size) {
    int product = 1;
    for (int i = 0; i < size; i++) {
        product *= arr[i];
    }
    return product;
}

int main() {
    int arr[5]; // Declare an integer array of size 5

    // Input elements of the array
    printf("Enter 5 integers:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate and display the sum of elements
    int sum = calculateSum(arr, 5);
    printf("Sum of elements: %d\n", sum);

    // Calculate and display the product of elements
    int product = calculateProduct(arr, 5);
    printf("Product of elements: %d\n", product);

    return 0;
}
