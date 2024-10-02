#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct node {
    int data;
    struct node* next;
}*SET;

typedef SET Dictionary[MAX];

// Hash Function
int hashBrown(int key) {
    int sum = 0;
    while (key != 0) {
        sum += (key % 10);
        key /= 10;
    }
    return sum % MAX;
}

// Initialize Dictionary
void initDictionary(Dictionary D) {
    for (int i = 0; i < MAX; i++) {
        D[i] = NULL;
    }
}

// Display Dictionary
void displayDict(Dictionary D) {
    printf("\n\tSET\tELEMENTS");
    for (int i = 0; i < MAX; i++) {
        printf("\n\t[%d] : \t", i);
        if (D[i] != NULL) {
            for (SET temp = D[i]; temp; temp = temp->next) {
                printf("%d ", temp->data);
            }
        } else {
            printf("Empty");
        }
    }
    printf("\n");
}

// Check if Member Exists
bool isMember(Dictionary D, int elem) {
    int key = hashBrown(elem);
    SET temp;
    for (temp = D[key]; temp && temp->data != elem; temp = temp->next) {}
    return temp != NULL;
}

// Insert Unique Element
void insertUnique(Dictionary D, int num) {
    int key = hashBrown(num);
    SET* trav;
    for (trav = &D[key]; *trav && (*trav)->data < num; trav = &(*trav)->next) {}
    if (*trav == NULL || (*trav)->data != num) {
        SET temp = (SET)malloc(sizeof(struct node));
        if (temp != NULL) {
            temp->data = num;
            temp->next = *trav;
            *trav = temp;
        }
    } else {
        printf("\t%d is already in the set.\n", num);
    }
}

// Delete Member
void deleteMember(Dictionary D, int elem) {
    int key = hashBrown(elem);
    SET* trav, temp;
    for (trav = &D[key]; *trav && (*trav)->data != elem; trav = &(*trav)->next) {}
    if (*trav != NULL) {
        temp = *trav;
        *trav = temp->next;
        free(temp);
    } else {
        printf("\t%d does not exist in the set.\n", elem);
    }
}

int main() {
    Dictionary dict;
    initDictionary(dict);

    printf("Inserting elements...\n");
    insertUnique(dict, 15);
    insertUnique(dict, 25);
    insertUnique(dict, 35);
    insertUnique(dict, 45);
    insertUnique(dict, 55);

    displayDict(dict);

    printf("\nChecking membership...\n");
    printf("Is 25 in the set? %s\n", isMember(dict, 25) ? "Yes" : "No");
    printf("Is 40 in the set? %s\n", isMember(dict, 40) ? "Yes" : "No");

    printf("\nDeleting element 25...\n");
    deleteMember(dict, 25);
    displayDict(dict);

    printf("\nTrying to delete element 40 (not in the set)...\n");
    deleteMember(dict, 40);
    displayDict(dict);

    return 0;
}
