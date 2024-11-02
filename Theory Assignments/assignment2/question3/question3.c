/*
Name = Rameez Ahmed Khan
Roll number = 24k-1043
Section = BCS-1C
Problem 3: You are working for a text-processing company that optimizes storage for large amounts of written
data. The company has identified a recurring issue: words in documents are often unnecessarily
lengthy due to repeated consecutive characters. Your task is to minimize these words by reducing
consecutive duplicate characters to a single instance of the character.
Operations:
Compress a Word: Write a function that takes a string (a word) as input and returns a minimized
version of the word, where all consecutive duplicate letters are reduced to one.
Multiple Word Compression: You will then apply this function to a list of words and return the
minimized version for each word.
Add a feature to calculate how many characters were removed during the compression process.
Input: words = [“booooook”, “coooool”, “heeeey”]
Output: [“bok”, “col”, “hey”]
*/
#include <stdio.h>
#include <string.h>

#define ORIGINAL_WORD 100

int compressWord(char *word, char *compressedWord) {
    int j = 0;
    int removedcharCount = 0;

    for (int i = 0; i < strlen(word); i++) { // this loop iterate over each character of the word.
        if (i == 0 || word[i] != word[i - 1]) { // checks for identical characters.
            compressedWord[j++] = word[i];
        } else {
            removedcharCount++;
        }
    }
    compressedWord[j] = '\0'; // \0: null character
    return removedcharCount;
}
int main() {
    char word[ORIGINAL_WORD];
    char compressedWord[ORIGINAL_WORD];

    printf("Enter your word here: ");
    scanf("%s", word);

    int removedcharCount = compressWord(word, compressedWord);

    printf("Compressed word: %s\n", compressedWord);
    printf("Total characters removed: %d\n", removedcharCount);

    return 0;
}