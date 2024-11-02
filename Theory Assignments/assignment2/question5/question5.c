/*
Name = Rameez Ahmed Khan
Roll number = 24k-1043
Section = BCS-1C
Problem 5: 
You are tasked with creating a program that generates a histogram based on user input. The user will
provide a set of values, and your program will use loops to create a visual representation of these values.
1. Input Handling: Write a function that takes an array of integers (the values) and the count of
those integers as input.
2. Horizontal Histogram Function: Use loops to generate and print a histogram, where each
value is represented by asterisks (*).
3. Vertical Histogram Function: Use loops to generate and print a vertical histogram, where
each value is represented by asterisks (*).
Expected Values:
int values [] = {3, 5, 1, 4};
int count = 4;
Horizontal Histogram
Value 1: ***
Value 2: *****
Value 3: *
Value 4: ****
Vertical Histogram
  *
  *   *
* *   *
* *   *
* * * *
3 5 1 4
*/
#include <stdio.h>

void vertical_histogram(int values[], int count) {
    int max_value = values[0];
    for (int i = 1; i < count; i++) {
        if (values[i] > max_value) {
            max_value = values[i];
        }
    }
    for (int i = max_value; i >= 1; i--) {
        for (int j = 0; j < count; j++) {
            if (values[j] >= i) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    for (int i = 0; i < count; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
}

void horizontal_histogram(int values[], int count) {
    int max_value = values[0];
    for (int i = 1; i < count; i++) {
        if (values[i] > max_value) {
            max_value = values[i];
        }
    }
    for (int i = 0; i < count; i++) {
        printf("%d: ", values[i]);
        for (int j = 0; j < values[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the number of values: ");
    scanf("%d", &n);

    int values[n];

    printf("Enter the values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }
    printf("\nHorizontal Histogram:\n");
    horizontal_histogram(values, n);

    printf("\nVertical Histogram:\n");
    vertical_histogram(values, n);

    return 0;
}