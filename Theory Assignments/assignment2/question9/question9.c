/*
Name = Rameez Ahmed Khan
Roll number = 24k-1043
Section = BCS-1C
Problem 9: Write a C program to simulate a simple grid-based adventure game using a 2D array.
Game Description:
• The game consists of a 5x5 grid.
• Each cell can contain:
o An empty space (' ').
o An item ('I') that the player can collect.
o An obstacle ('X') that the player cannot pass through.
o The player's position, represented by 'P'.

Example Input:
char grid[5][5] = {
{' ', ' ', 'I', 'X', ' '},
{' ', 'X', ' ', ' ', ' '},
{'I', ' ', 'X', 'X', ' '},
{' ', ' ', ' ', 'I', 'X'},
{' ', 'X', ' ', ' ', 'P'}
};
Requirements:
1. Display the grid and prompt the player for a move (W: up, S: down, A: left, D: right, Q: quit).
2. Update the player's position based on valid moves.
3. Collect items when the player moves to a cell containing an item (remove item from grid).
4. Prevent movement into obstacles ('X').
5. Continue until the player chooses to quit.
6. The grid is fixed at 5x5.
7. Only valid moves are allowed.
8. Handle invalid input gracefully.
*/
#include <stdio.h>

void upDown(char grid[][5], int*, int*, int*, int*);
void leftRight(char grid[][5], int*, int*, int*, int*);
void printGrid(char grid[5][5]);

int main(){
    char grid[5][5] = {
    {' ', ' ', 'I', 'X', ' '},
    {' ', 'X', ' ', ' ', ' '},
    {'I', ' ', 'X', 'X', ' '},
    {' ', ' ', ' ', 'I', 'X'},
    {' ', 'X', ' ', ' ', 'P'}
    };

    printf("Welcome to Grid Adventure Game.\n\n");
    printf("Enter following keys to play\nW: up\nS: down\nA: Left\nD: Right\nQ: Quit.\n\n");
    printf("Let's Start\n");
    int p1=4, p2=4, item=0;

    char a;
    while(a!='Q'){
        int p3=0;
        printGrid(grid);
        printf("\nEnter your move: ");
        scanf(" %c", &a);

        if(a=='W'){
            p3=p1-1;
            upDown(grid, &p2, &p1, &p3, &item);
        }
        else if(a=='S'){
            p3=p1+1;
            upDown(grid, &p2, &p1, &p3, &item);
        }
        else if(a=='A'){
            p3=p2-1;
            leftRight(grid, &p1, &p2, &p3, &item);
        }
        else if(a=='D'){
            p3=p2+1;
            leftRight(grid, &p1, &p2, &p3, &item);
        }
        else if(a=='Q'){ 
            printf("\nThe game has ended\n");
            printf("Collected items are %d", item);
            return 0;
        }
        else printf("Invalid Input\n");
    }
}

void printGrid(char grid[5][5]){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            printf("|'%c'", grid[i][j]);
        }
        printf("|\n");
    }
}

void upDown(char grid[][5], int *i, int *j, int *k, int *item){
    if(*k>=0 && *k<=4){
        if(grid[*k][*i]==' ' || grid[*k][*i]=='I'){
            if(grid[*k][*i]=='I') (*item)++;
            grid[*j][*i]=' ';
            grid[*k][*i]='P';
            *j=*k;
        }
    }
    else printf("Invalid Input\n");
    return;
}

void leftRight(char grid[][5], int *i, int *j, int *k, int *item){
    if(*k>=0 && *k<=4){
        if(grid[*i][*k]==' ' || grid[*i][*k]=='I'){
            if(grid[*i][*k]=='I') (*item)++;
            grid[*i][*j]=' ';
            grid[*i][*k]='P';
            *j=*k;
        }
    }
    else printf("Invalid Input\n");
    return;
}
