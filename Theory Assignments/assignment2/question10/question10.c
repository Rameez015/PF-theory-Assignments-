/*
Name = Rameez Ahmed Khan
Roll number = 24k-1043
Section = BCS-1C
Problem 10: In the figures below, a star pattern is illustrated for the values N = 3 and N = 5. Your task is to create
a C program that can print this pattern for odd values of N. Your solution should include the following
components:
1. Include meaningful, properly written English comments that explain the steps of your
program. (Worth 2 points)
2. In the header of the file, describe the pattern. Include information about the length of sides,
the position of the center, and any other relevant details. (Worth 1 points)
3. Prompt the user to enter the value of N. (Worth 1 points)
4. Run your program with an input value of 7. Capture a screenshot and save it as
'K23xxxx_Q01a.png.' (Worth 1 points)
5. Run your program again with an input value of 21. Capture a screenshot and save it as
'K23xxxx_Q01b.png.' (Worth 1 points)
6. For this question, submit only three files, 2 png image files and 1 .c file containing your code,
and there's no need to create a separate folder for Q01. (Worth 1 point)
The remaining marks will be based on the correctness, completeness, and the approach you take in
implementing the program.
*/
#include <stdio.h>

/*
 * This program prints a star pattern for odd values of N.
 * The pattern is a square with a centered star.
 * The side length of the square is N.
 * The center of the square is at (N/2, N/2).
 */

int main() {
    int N;

    printf("Enter an odd value for N: ");
    scanf("%d", &N);

    // Check if N is odd
    if (N % 2 == 0) {
        printf("N must be odd.\n");
        return 1;
    }

    // Calculate the center point
    int center = N / 2;

    // Print the top half of the pattern
    for (int i = 0; i <= center; i++) {
        for (int j = 0; j < N; j++) {
            if (i == center && j == center) {
                printf("*"); // Print the center star
            } else if (i == 0 || i == center || j == 0 || j == N - 1) {
                printf("*"); // Print the border
            } else {
                printf(" "); // Print a space
            }
        }
        printf("\n");
    }

    // Print the bottom half of the pattern (mirror image of the top half)
    for (int i = center - 1; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            if (i == center && j == center) {
                printf("*"); // Print the center star
            } else if (i == 0 || i == center || j == 0 || j == N - 1) {
                printf("*"); // Print the border
            } else {
                printf(" "); // Print a space
            }
        }
        printf("\n");
    }

    return 0;
}