/*
Name = Rameez Ahmed Khan
Roll number = 24k-1043
Section = BCS-1C
Problem 2: A popular beverage company is looking to optimize their marketing campaigns by understanding the
frequency of characters used in their promotional slogans. They believe that analyzing these patterns
can help them tailor their messaging to specific demographics and improve brand recall. You've been
tasked with creating a C code function to analyze the character frequency in a list of slogans provided
by the marketing team. This analysis will help identify the most common letters used in their slogans,
which can inform future marketing strategies.
Input:
slogans = ["buy now", "save big", "limited offer"]
Expected Output:
● For "buy now": {'b': 1, 'u': 1, 'y': 1, ' ': 1, 'n': 1, 'o': 1, 'w': 1}
● For "save big": {'s': 1, 'a': 1, 'v': 1, 'e': 1, ' ': 1, 'b': 1, 'i': 1, 'g': 1}
● For "limited offer": {'l': 1, 'i': 1, 'm': 1, 't': 1, 'e': 2, 'd': 1, ' ': 1, 'o': 1, 'f': 1, 'r': 1}
*/
#include <stdio.h>
#include <string.h>

void CFA(char *slogan) { // where cfa = character frequency analysis
    int freq[26] = {0}; // array for lettters (a-z)

    for (int i = 0; slogan[i] != '\0'; i++) {
        if (slogan[i] >= 'a' && slogan[i] <= 'z') { // to check if the character is lower case
            int index = slogan[i] - 'a';
            freq[index]++;
        }
    }
    printf("For \"%s\": ", slogan);
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("{'%c': %d, ", i + 'a', freq[i]);
        }
    }
    printf("}\n");
}

int main() {
    char slogans[][20] = {"buy now", "save big", "limited offer"};
    int NumberOfSlogans = sizeof(slogans) / sizeof(slogans[0]);

    for (int i = 0; i < NumberOfSlogans ; i++) {
        CFA(slogans[i]);
    }

    return 0;
}