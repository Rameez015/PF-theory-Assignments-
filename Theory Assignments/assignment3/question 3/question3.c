/*Create a program to validate an email address based on a few basic criteria. The program will
prompt the user to enter an email address and will dynamically allocate memory to store and
process the input.
Define the following function:
1. int validateEmail(char* email): This function validates the email based on the following
criteria:
○ Contains exactly one @ symbol.
○ Contains at least one dot (.) after the @ symbol.
○ Is non-empty.
○ Returns 1 if the email is valid, and 0 if invalid.

Steps:
1. User Input: Prompt the user to enter an email address. Allocate memory dynamically for the
email, ensuring the memory size is based on the input length.
2. Validation Process:
○ Call the validateEmail function to check if the email meets the criteria.
3. Display Results:
○ Print "Valid Email" if the email meets the criteria.
○ Print "Invalid Email" if the email does not meet the criteria.
4. Memory Cleanup:
○ Free the dynamically allocated memory after validation to prevent memory leaks.*/
#include <stdio.h>
#include <stdlib.h>
int validateEmail(char* email) {
    int i=0;
    int at=0;
    int dot=0;
    int ati;
    while(email[i]!='\0') {
        if(email[i]=='@') {
            at++;
            ati=i;
        }
        i++;
    }
    if(at==1) {
        i=ati;
        while(email[i]!='\0') {
            if(email[i]!='.') {
                dot++;
            }
            i++;
        }
    }
    else {
        return 0;
    }
    i=0;
    while(i<ati) {
        if(email[i]=='.') {
            return 0;
        }
        i++;
    }
    if(at==1 && dot>=1) {
        return 1;
    }
    else {
        return 0;
    }
}
int main() {
    printf("enter your email:\n");
    char* email=malloc(sizeof(char)*1);
    int len=0;
    while(1) {
        email=realloc(email,sizeof(char)*(len+1));
        char val;
        scanf("%c",&val);
        if(val=='\n') {
            break;
        }
        email[len]=val;
        len++;
    }
    email[len]='\0';
    if(validateEmail(email)) {
        printf("valid email");
    }
    else {
        printf("not valid");
    }
    free(email);
}