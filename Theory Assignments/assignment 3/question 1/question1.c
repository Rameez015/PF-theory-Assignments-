/*Write a program that contains a structure named Employee which contains the following
data members:
● employeeCode
● employeeName
● dateOfJoining
Perform the following operations:
1. Define a function that assigns user-defined values to these variables.
2. Create an array of 4 Employee structs and initialize them with user-defined values.
3. Define a function that asks the user to enter the current date, calculates the tenure of each
employee, and checks if the tenure is more than three years. Display the details of
employees with tenure of more than three years and the count of such employees.*/

#include<stdio.h>
#include<string.h>

    struct Employee {

        int employeeCode;
        char employeeName[30];
        char dateOfJoining[15];

    };
    
    void assignvalues(struct Employee *emp) {

        printf("enter the employee code: ");
        scanf("%d",&emp->employeeCode);

        printf("enter the employee name: ");
        getchar();
        fgets(emp->employeeName, sizeof(emp->employeeName), stdin); /*fgets to ensure all the blank spaces input 
                                                                      from the user are read by compiler as well.*/

        printf("enter the employee's date of joining (YYYY-MM-DD): ");
        scanf("%s",emp->dateOfJoining);

    } 
    void tenurecheck(const struct Employee employees[], int eligible){
      int currentyear, currentmonth, currentday;
      printf("enter the current date: ");
      scanf("%d-%d-%d",&currentyear, &currentmonth, &currentday);

      printf("enter the date of joining for each employee: ");
      for (int i = 0; i < 4; i++){
        int joinyear, joinmonth, joinday;
        sscanf(employees[i].dateOfJoining, "%d-%d-%d", &joinyear, &joinmonth, &joinday); // sscanf to exract data from string filled previously in part 2.

        int tenureyears = currentyear - joinyear;
        if (currentmonth<joinmonth || (currentmonth == joinmonth && currentday<joinday)){
            tenureyears --;
        }
        if (tenureyears > 3){
            eligible ++;
        }
      }  
       printf("Total employees with tenure of more than 3 years: %d\n", eligible);
    }
    int main(){
        struct Employee employees[4];
        
        for (int i = 0; i < 4; i ++){
            assignvalues(&employees[i]);
        }
        tenurecheck(employees, 4);
        return 0;
    }