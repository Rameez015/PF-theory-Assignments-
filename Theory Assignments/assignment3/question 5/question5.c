/*You're building an inventory system for a pet shop called "Pets in Heart" that keeps track of
different species of animals and their specific supplies (e.g., food, toys, bedding). The shop
inventory system uses a 2D dynamic array char** speciesSupplies where:
● Rows are explicitly set for each species (e.g., "Dogs," "Cats," "Parrots"), and each row
corresponds to a different species.
● Columns are dynamically allocated for each species to hold their specific supplies (e.g.,
"Food," "Leash," "Toys").
Task:
Write a C program that:
1. Initialize the Inventory: Allocate memory for a specified number of species, with each
species having its own list of supplies (initially empty).
2. Add Supplies: For each species, dynamically allocate memory for a list of supplies and allow
the user to add supplies for that species.
3. Update Supplies: Let users update the name of a supply item for a specific species.
4. Remove Species: Allow users to delete a species and free the associated memory (both for
the species and its supplies).
5. Display Inventory: Show the current supplies for each species in the inventory.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeInventory(char*** speciesSupplies, int numSpecies);
void addSupplies(char*** speciesSupplies, int numSpecies, int* numSuppliesPerSpecies);
void updateSupply(char*** speciesSupplies, int speciesIndex, int supplyIndex);
void removeSpecies(char*** speciesSupplies, int* numSpecies, int* numSuppliesPerSpecies, int speciesIndex);
void displayInventory(char*** speciesSupplies, int numSpecies, int* numSuppliesPerSpecies);

int main() {
    int numSpecies;

    printf("Enter the number of species: ");
    scanf("%d", &numSpecies);

    char*** speciesSupplies = (char***)malloc(numSpecies * sizeof(char**));
    int* numSuppliesPerSpecies = (int*)calloc(numSpecies, sizeof(int));

    initializeInventory(speciesSupplies, numSpecies);

    int choice;
    do {
        printf("\n--- Pets in Heart Inventory Menu ---\n");
        printf("1. Add Supplies\n");
        printf("2. Update Supply\n");
        printf("3. Remove Species\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSupplies(speciesSupplies, numSpecies, numSuppliesPerSpecies);
                break;
            case 2: {
                int speciesIndex, supplyIndex;
                printf("Enter species index (0 to %d): ", numSpecies - 1);
                scanf("%d", &speciesIndex);
                printf("Enter supply index (0 to %d): ", numSuppliesPerSpecies[speciesIndex] - 1);
                scanf("%d", &supplyIndex);
                updateSupply(speciesSupplies, speciesIndex, supplyIndex);
                break;
            }
            case 3: {
                int speciesIndex;
                printf("Enter species index to remove (0 to %d): ", numSpecies - 1);
                scanf("%d", &speciesIndex);
                removeSpecies(speciesSupplies, &numSpecies, numSuppliesPerSpecies, speciesIndex);
                break;
            }
            case 4:
                displayInventory(speciesSupplies, numSpecies, numSuppliesPerSpecies);
                break;
            case 5:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    for (int i = 0; i < numSpecies; i++) {
        for (int j = 0; j < numSuppliesPerSpecies[i]; j++) {
            free(speciesSupplies[i][j]);
        }
        free(speciesSupplies[i]);
    }
    free(speciesSupplies);
    free(numSuppliesPerSpecies);

    return 0;
}

void initializeInventory(char*** speciesSupplies, int numSpecies) {
    for (int i = 0; i < numSpecies; i++) {
        speciesSupplies[i] = NULL;
    }
}

void addSupplies(char*** speciesSupplies, int numSpecies, int* numSuppliesPerSpecies) {
    int speciesIndex;
    printf("Enter species index (0 to %d): ", numSpecies - 1);
    scanf("%d", &speciesIndex);

    if (speciesIndex < 0 || speciesIndex >= numSpecies) {
        printf("Invalid species index!\n");
        return;
    }

    int numSupplies;
    printf("Enter the number of supplies to add: ");
    scanf("%d", &numSupplies);

    speciesSupplies[speciesIndex] = (char**)realloc(speciesSupplies[speciesIndex], (numSuppliesPerSpecies[speciesIndex] + numSupplies) * sizeof(char*));

    for (int i = 0; i < numSupplies; i++) {
        char buffer[100];
        printf("Enter supply %d: ", i + 1);
        scanf("%s", buffer);
        speciesSupplies[speciesIndex][numSuppliesPerSpecies[speciesIndex] + i] = strdup(buffer);
    }

    numSuppliesPerSpecies[speciesIndex] += numSupplies;
}

void updateSupply(char*** speciesSupplies, int speciesIndex, int supplyIndex) {
    char buffer[100];
    printf("Enter new name for the supply: ");
    scanf("%s", buffer);

    free(speciesSupplies[speciesIndex][supplyIndex]);
    speciesSupplies[speciesIndex][supplyIndex] = strdup(buffer);
}

void removeSpecies(char*** speciesSupplies, int* numSpecies, int* numSuppliesPerSpecies, int speciesIndex) {
    for (int i = 0; i < numSuppliesPerSpecies[speciesIndex]; i++) {
        free(speciesSupplies[speciesIndex][i]);
    }
    free(speciesSupplies[speciesIndex]);

    for (int i = speciesIndex; i < *numSpecies - 1; i++) {
        speciesSupplies[i] = speciesSupplies[i + 1];
        numSuppliesPerSpecies[i] = numSuppliesPerSpecies[i + 1];
    }

    (*numSpecies)--;
    speciesSupplies = (char***)realloc(speciesSupplies, (*numSpecies) * sizeof(char**));
    numSuppliesPerSpecies = (int*)realloc(numSuppliesPerSpecies, (*numSpecies) * sizeof(int));
}

void displayInventory(char*** speciesSupplies, int numSpecies, int* numSuppliesPerSpecies) {
    printf("\n--- Inventory ---\n");
    for (int i = 0; i < numSpecies; i++) {
        printf("Species %d:\n", i);
        for (int j = 0; j < numSuppliesPerSpecies[i]; j++) {
            printf("  %s\n", speciesSupplies[i][j]);
        }
    }
}