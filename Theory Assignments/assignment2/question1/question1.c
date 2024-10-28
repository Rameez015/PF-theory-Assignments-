/*
Name = Rameez Ahmed Khan
Roll number = 24k-1043
Section = BCS-1C
Problem 1: Write a c program to find the second smallest element in an array.
Input 5 elements in the array (value must be <9999):
element - 0: 0
element - 1: 9
element - 2: 4
element - 3: 6
element - 4: 5
Expected Output:
The Second smallest element in the array is: 4
*/
#include <stdio.h>

int main() {
    int arr[5], i, j, temp; // temp = temporary variable container:)

    printf("Enter 5 elements in the array not bigger then 9999:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] >= 9999) {
            printf("Invalid input. Please enter a value less than 9999.\n");
            i--;
        }
    }
    for (i = 0; i < 5; i++) {
        for (j = i + 1; j < 5; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("The Second smallest element in the array is: %d\n", arr[1]);

    return 0;
}