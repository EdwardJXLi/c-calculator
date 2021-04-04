/**
 * File: parse.c
 * Description: Variety of functions to clean and parse user input
 */

#include <stdio.h>
#include <stdlib.h>
#include "parse.h"

// Function to remove all spaces from string
void removeSpaces(char* input){
    int i = 0;
    int j = 0;
    while (input[i]) {
        if (input[i] != ' ') {
            input[j] = input[i];
            j++;
        }
        i++;
    }
    input[j] = '\0';
}

LinkedList* parseInput(char* input) {
    // Create New Linked List
    LinkedList* output = createLinkedList();

    // Init Vars
    int tempInt = 0;
    int i = 0;

    // Loop Through All Characters of the Input and Parse Into Linked List
    while (input[i]) {
        return;
    }

    // Return Parsed LinkedList
    return output;
}
