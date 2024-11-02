/*
Name = Rameez Ahmed Khan
Roll number = 24k-1043
Section = BCS-1C
Problem 4: You are working as a software engineer at a company that manages a large database of customer
transactions. Each transaction is stored as a string that contains encoded information about the
customer. However, some transactions may have been duplicated due to system errors, and these
duplicates appear in scrambled order. Your task is to identify and group these "scrambled"
transactions together, as they represent the same customer activity. Two transactions are considered
scrambled if they contain the same letters but in a different order (anagrams). You are provided with
a list of transaction strings. You need to write a program that groups these scrambled transactions
into separate categories, returning each group of related transactions together.
Example
Input transactions = ["eat", "tea", "tan", "ate", "nat", "bat"]
Expected Output: [['bat'], ['nat', 'tan'], ['ate', 'eat', 'tea']]
*/
#include <stdio.h>
#include <string.h>
int main(){
int n;
int length1=0;
int length2=0;
printf("Enter the number of words: ");
scanf("%d",&n);
char arr[n][100];
int i,j,k,l,inc=0;
for(i=0;i<n;i++){
	printf("Enter word number %d: ",i+1);
	scanf("%s",arr[i]);
}
for(i=n-1;i>=0;i--){
if(arr[i][0]!=' '){
	length1=0;
	while(arr[i][length1]!='\0')length1++;
	printf("{%s",arr[i]);
	for(j=i-1;j>=0;j--){
		length2=0;
	while(arr[j][length2]!='\0')length2++;
		for(k=0;arr[i][k]!='\0';k++){
			for(l=0;arr[j][l]!='\0';l++) if(arr[i][k]==arr[j][l]) break;
			  if(arr[j][l]=='\0')  break;
		    }    
	        if(arr[i][k]=='\0' && length1==length2)	{
	            printf(",%s",arr[j]);
		        while(arr[j][inc]!='\0'){
            		arr[j][inc]=' ';
	            	inc++;
				}
				inc=0;
            }						             
    	}
            printf("},");
        }
    }
    return 0;
}