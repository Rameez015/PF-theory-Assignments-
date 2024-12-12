/*You are creating a system to track employee performance ratings over multiple evaluation periods.
The system will dynamically allocate memory to store ratings and perform various analysis tasks,
including finding the top-performing employee and the best-rated evaluation period.
Define the Employee Structure:
Create a structure called Employee with the following fields:
● ratings: A dynamically allocated array to store the ratings for each evaluation period.
● totalScore: An integer to store the employee's total score across all evaluation periods.
Define the following function:
1. Input Ratings Function:
○ Implement a function void inputEmployees(int** ratings, int numEmployees, int
numPeriods) to allow the user to enter ratings for each employee across all
evaluation periods.
○ Each rating should be between 1 and 10 (inclusive). Input validation should be
implemented to enforce this.
2. Display Performance Function:
○ Implement a function void displayPerformance(int** ratings, int numEmployees,
int numPeriods) that displays the performance ratings for each employee across all
evaluation periods.

3. Find Employee of the Year Function:
○ Implement a function int findEmployeeOfTheYear(int** ratings, int
numEmployees, int numPeriods) to calculate and return the index of the employee
with the highest average rating.
4. Find Highest Rated Period Function:
○ Implement a function int findHighestRatedPeriod(int** ratings, int
numEmployees, int numPeriods) to calculate and return the evaluation period with
the highest average rating across all employees.

5. Find Worst Performing Employee Function:
○ Implement a function int findWorstPerformingEmployee(int** ratings, int
numEmployees, int numPeriods) to calculate and return the index of the employee
with the lowest average rating.

Memory Management:
● Dynamically allocate memory for each employee's ratings based on the number of
evaluation periods.
● After completing all tasks, ensure that the dynamically allocated memory is properly freed to
prevent memory leaks.*/
#include <stdio.h>
#include <stdlib.h>

void inputEmployees(int** ratings, int numEmployees, int numPeriods);
void displayPerformance(int** ratings, int numEmployees, int numPeriods);
int findEmployeeOfTheYear(int** ratings, int numEmployees, int numPeriods);
int findHighestRatedPeriod(int** ratings, int numEmployees, int numPeriods);
int findWorstPerformingEmployee(int** ratings, int numEmployees, int numPeriods);

int main() {
    int numEmployees, numPeriods;

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    printf("Enter the number of evaluation periods: ");
    scanf("%d", &numPeriods);

    int** ratings = (int**)malloc(numEmployees * sizeof(int*));
    for (int i = 0; i < numEmployees; i++) {
        ratings[i] = (int*)malloc(numPeriods * sizeof(int));
    }

    inputEmployees(ratings, numEmployees, numPeriods);

    displayPerformance(ratings, numEmployees, numPeriods);

    int employeeOfTheYear = findEmployeeOfTheYear(ratings, numEmployees, numPeriods);
    printf("\nEmployee of the Year: Employee %d\n", employeeOfTheYear + 1);

    int highestRatedPeriod = findHighestRatedPeriod(ratings, numEmployees, numPeriods);
    printf("Highest Rated Evaluation Period: Period %d\n", highestRatedPeriod + 1);

    int worstPerformingEmployee = findWorstPerformingEmployee(ratings, numEmployees, numPeriods);
    printf("Worst Performing Employee: Employee %d\n", worstPerformingEmployee + 1);

    for (int i = 0; i < numEmployees; i++) {
        free(ratings[i]);
    }
    free(ratings);

    return 0;
}

void inputEmployees(int** ratings, int numEmployees, int numPeriods) {
    for (int i = 0; i < numEmployees; i++) {
        printf("Enter ratings for Employee %d:\n", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            do {
                printf("  Period %d: ", j + 1);
                scanf("%d", &ratings[i][j]);
                if (ratings[i][j] < 1 || ratings[i][j] > 10) {
                    printf("    Invalid rating! Please enter a value between 1 and 10.\n");
                }
            } while (ratings[i][j] < 1 || ratings[i][j] > 10);
        }
    }
}

void displayPerformance(int** ratings, int numEmployees, int numPeriods) {
    printf("\nEmployee Performance:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Employee %d: ", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            printf("%d ", ratings[i][j]);
        }
        printf("\n");
    }
}

int findEmployeeOfTheYear(int** ratings, int numEmployees, int numPeriods) {
    int bestEmployee = 0;
    double highestAverage = 0;

    for (int i = 0; i < numEmployees; i++) {
        int total = 0;
        for (int j = 0; j < numPeriods; j++) {
            total += ratings[i][j];
        }
        double average = (double)total / numPeriods;
        if (average > highestAverage) {
            highestAverage = average;
            bestEmployee = i;
        }
    }
    return bestEmployee;
}

int findHighestRatedPeriod(int** ratings, int numEmployees, int numPeriods) {
    int bestPeriod = 0;
    double highestAverage = 0;

    for (int j = 0; j < numPeriods; j++) {
        int total = 0;
        for (int i = 0; i < numEmployees; i++) {
            total += ratings[i][j];
        }
        double average = (double)total / numEmployees;
        if (average > highestAverage) {
            highestAverage = average;
            bestPeriod = j;
        }
    }
    return bestPeriod;
}

int findWorstPerformingEmployee(int** ratings, int numEmployees, int numPeriods) {
    int worstEmployee = 0;
    double lowestAverage = 10;

    for (int i = 0; i < numEmployees; i++) {
        int total = 0;
        for (int j = 0; j < numPeriods; j++) {
            total += ratings[i][j];
        }
        double average = (double)total / numPeriods;
        if (average < lowestAverage) {
            lowestAverage = average;
            worstEmployee = i;
        }
    }
    return worstEmployee;
}