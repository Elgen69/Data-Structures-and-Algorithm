//Sets members are not dynamically allocated, static
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

typedef struct {
    int members[SIZE]; // Static size (thus it could get full);
    int count; // Number of elements in the set
} Set;

// Prototypes
Set* init();
bool isEmpty(Set* set);
bool isFull(Set* set);
void insert(Set* set, int member);
void printSet(Set* set);
Set* setUnion(Set* setA, Set* setB);
Set* setIntersection(Set* setA, Set* setB);
Set* setDifference(Set* setA, Set* setB);
bool isSubset(Set* setA, Set* setB);
void deleteMember(Set* set, int num);
bool findMember(Set* set, int num);

int main(void) {
    // Initialize Set A
    Set* setA = init();

    // Check if Set A is empty
    if (isEmpty(setA)) {
        printf("Set A is Empty\n");
    } else {
        printf("Set A is not Empty\n");
    }

    // Insert elements into Set A
    insert(setA, 5);
    insert(setA, 6);
    insert(setA, 7);
    insert(setA, 7); // Test repeat
    insert(setA, 8);
    insert(setA, 9);
    printf("Set A: ");
    printSet(setA);

    // Check if Set A is empty after insertion
    if (isEmpty(setA)) {
        printf("Set A is Empty\n");
    } else {
        printf("Set A is not Empty\n");
    }

    // Initialize Set B and insert elements
    Set* setB = init();
    printf("\n");
    insert(setB, 7);
    insert(setB, 9);
    insert(setB, 10);
    insert(setB, 11);
    printf("Set B: ");
    printSet(setB);
    printf("\n");

    // Perform set operations
    Set* setC = setUnion(setA, setB);
    printf("Set A and B Unionized: ");
    printSet(setC);
    printf("\n");

    Set* setD = setIntersection(setA, setB);
    printf("A intersection B: ");
    printSet(setD);
    printf("\n");

    Set* setE = setDifference(setA, setB);
    printf("A minus B: ");
    printSet(setE);
    printf("\n");

    Set* setF = setDifference(setB, setA);
    printf("F = B minus A: ");
    printSet(setF);

    printf("\n");

    // Check if Set A is a subset of Set B
    if (isSubset(setA, setB)) {
        printf("A: ");
        printSet(setA);
        printf("-> is a subset of B ");
        printSet(setB);
    } else {
        printf("A: ");
        printSet(setA);
        printf("-> is not a subset of B ");
        printSet(setB);
    }

    printf("\n");

    // Check if Set F is a subset of Set B
    if (isSubset(setF, setB)) {
        printf("F: ");
        printSet(setF);
        printf("-> is a subset of B ");
        printSet(setB);
    } else {
        printf("F: ");
        printSet(setF);
        printf("-> is not a subset of B ");
        printSet(setB);
    }

    // Testing findMember
    int memberToFind = 7;
    printf("\nChecking if %d is a member of Set A...\n", memberToFind);
    if (findMember(setA, memberToFind)) {
        printf("%d is a member of Set A.\n", memberToFind);
    } else {
        printf("%d is not a member of Set A.\n", memberToFind);
    }

    // Test deleting a member
    printf("\nDeleting member 7 from Set A...\n");
    deleteMember(setA, 7);
    printf("Set A after deletion: ");
    printSet(setA);

    // Check if member 7 is still in Set A
    printf("\nChecking if 7 is still a member of Set A...\n");
    if (findMember(setA, 7)) {
        printf("7 is still a member of Set A.\n");
    } else {
        printf("7 is not a member of Set A.\n");
    }

    // Test isFull function
    printf("\nTesting isFull function:\n");
    if (isFull(setA)) {
        printf("Set A is full.\n");
    } else {
        printf("Set A is not full.\n");
    }

    // Fill Set A to full capacity for demonstration
    Set* setG = init(); // Another set to test isFull
    for (int i = 0; i < SIZE; i++) {
        insert(setG, i + 1);
    }
    printf("Set G (filled to capacity): ");
    printSet(setG);

    if (isFull(setG)) {
        printf("Set G is full.\n");
    } else {
        printf("Set G is not full.\n");
    }

    // Free allocated memory
    free(setA);
    free(setB);
    free(setC);
    free(setD);
    free(setE);
    free(setF);
    free(setG);

    return 0;
}

// Initialize a new set
Set* init() {
    Set* new_set = malloc(sizeof(Set));
    new_set->count = 0; // Set count starts at 0
    return new_set;
}

// Check if the set is empty
bool isEmpty(Set* set) {
    return set->count == 0;
}

// Check if the set is full
bool isFull(Set* set) {
    return set->count == SIZE;
}

// Insert a member into the set if it's not already present
void insert(Set* set, int member) {
    if (isFull(set)) {
        printf("Set is full, cannot insert %d\n", member);
        return;
    }

    bool inSet = false;
    // Check if member is already in the set
    for (int i = 0; i < set->count; i++) {
        if (set->members[i] == member) {
            inSet = true;
            break;
        }
    }

    // If member is not in the set, add it
    if (!inSet) {
        set->members[set->count] = member;
        set->count++;
    }
}

// Print all members of the set
void printSet(Set* set) {
    for (int i = 0; i < set->count; i++) {
        if (i == (set->count - 1)) {
            printf("%d\n", set->members[i]);
        } else {
            printf("%d,", set->members[i]);
        }
    }
}

// Return a new set that is the union of setA and setB
Set* setUnion(Set* setA, Set* setB) {
    Set* newSet = init();
    // Insert elements from setA into the new set
    for (int i = 0; i < setA->count; i++) {
        insert(newSet, setA->members[i]);
    }
    // Insert elements from setB into the new set
    for (int i = 0; i < setB->count; i++) {
        insert(newSet, setB->members[i]);
    }

    return newSet;
}

// Return a new set that is the intersection of setA and setB
Set* setIntersection(Set* setA, Set* setB) {
    Set* newSet = init();
    for (int i = 0; i < setA->count; i++) {
        for (int j = 0; j < setB->count; j++) {
            // If element in setA is also in setB, add it to the new set
            if (setA->members[i] == setB->members[j]) {
                insert(newSet, setA->members[i]);
            }
        }
    }
    return newSet;
}

// Return a new set that is the difference of setA and setB (elements in setA but not in setB)
Set* setDifference(Set* setA, Set* setB) {
    Set* newSet = init();
    for (int i = 0; i < setA->count; i++) {
        bool inB = false;
        for (int j = 0; j < setB->count; j++) {
            if (setA->members[i] == setB->members[j]) {
                inB = true;
                break;
            }
        }

        // If element in setA is not in setB, add it to the new set
        if (!inB) {
            insert(newSet, setA->members[i]);
        }
    }

    return newSet;
}

// Check if setA is a subset of setB
bool isSubset(Set* setA, Set* setB) {
    for (int i = 0; i < setA->count; i++) {
        bool inB = false;
         for (int j = 0; j < setB->count; j++) {
            if (setA->members[i] == setB->members[j]) {
                inB = true;
                break;
            }
        }

        if (!inB) return false; // Element in setA not found in setB
    }

    return true; // All elements of setA are in setB
}

// Delete a specific member from the set
void deleteMember(Set* set, int num) {
    int i, j;
    bool found = false;

    // Find the element to delete
    for (i = 0; i < set->count; i++) {
        if (set->members[i] == num) {
            found = true;
            break;
        }
    }

    if (!found) return; // Element not found, nothing to delete

    // Shift elements left to fill the gap created by the deletion
    for (j = i; j < set->count - 1; j++) {
        set->members[j] = set->members[j + 1];
    }

    set->count--;
}

// Check if a specific member exists in the set
bool findMember(Set* set, int num) {
    for (int i = 0; i < set->count; i++) {
        if (set->members[i] == num) {
            return true; // Member found
        }
    }
    return false; // Member not found
}
