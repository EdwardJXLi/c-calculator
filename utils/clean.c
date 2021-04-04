/**
 * File: clean.c
 * Description: Variety of functions to clean user input
 */

#include <stdio.h>
#include <stdlib.h>
#include "clean.h"

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
