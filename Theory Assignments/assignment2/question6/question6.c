/*
Name = Rameez Ahmed Khan
Roll number = 24k-1043
Section = BCS-1C
Problem 6: Two friends, A and B, are playing the game of matchsticks. In this game, a group of N matchsticks is
placed on the table. The players can pick any number of matchsticks from 1 to 4 (both inclusive)
during their chance. The player who takes the last matchstick wins the game. If A starts first, how
many matchsticks should he pick on his 1st turn such that he is guaranteed to win the game or
determine if it’s impossible for him to win? Write a function which returns -1 if it’s impossible for A to
win the game, else return the number of matchsticks he should pick on his 1st turn such that he is
guaranteed to win.
*/
#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of matches: ");
    scanf("%d", &n);

    int result = n % 5;
    if (result == 0) {
        printf("-1\n");
    } else {
        printf("A should pick %d matchsticks.\n", result);
    }

    return 0;
}