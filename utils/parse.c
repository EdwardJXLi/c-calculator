/**
 * File: parse.c
 * Description: Variety of functions to clean and parse user input
 */

#include "common.h"
#include "linkedlist.h"
#include "error.h"
#include "helpers.h"
#include "parse.h"

// Function to remove all spaces from string
void removeSpaces(char* input){
    int i = 0;
    int j = 0;
    while (input[i]) {
        if (input[i] != ' ') {
            input[j] = input[i];
            ++j;
        }
        ++i;
    }
    input[j] = '\0';
}

LinkedList* parseInput(char* input, ErrorHandler* errorHandler) {
    // Clean Input
    removeSpaces(input);

    // Create New Linked List
    LinkedList* output = createLinkedList();

    // Init Vars
    int tempInt = 0;
    int i = 0;
    int bracketLayer = 0;
    int lastType;

    // Sanity check -> Check if input was given!
    if (input[0] == '\0') {
        return setError(errorHandler, "Parser", "No Input Was Given!");
    }

    // Sanity check -> Checks if first character is a number or operator
    if (isNum(input[0]) || input[0] == '(') {
        lastType = OPERATOR;
    }
    // Special Condition for Negative Numbers
    else if (input[0] == '-') {
        appendOperand(output, 0);
        appendOperator(output, '-');
        lastType = OPERATOR;
        i++;
    }
    else {
        char errorMessage[MAX_ERROR_LEN];
        snprintf(errorMessage, MAX_ERROR_LEN, "Unexpected Character In Input: %c At Location 0", input[0]);
        return setError(errorHandler, "Parser", errorMessage);
    }

    // Loop Through All Characters of the Input and Parse Into Linked List
    while (input[i]) {
        // Handle Number
        if (isNum(input[i])) {
            // Handle if last type was a closing bracket
            if (lastType == CLOSE_BRACKET) {
                appendOperator(output, '*');
            }

            // Process Number
            tempInt = tempInt*10 + input[i] - '0';
            lastType = OPERAND;
        }
        // Handle Anything Else (Not Number!)
        else {
            // Handle if last character was a number or closing bracket
            if (lastType == OPERAND || lastType == CLOSE_BRACKET) {
                // Only Append Number if last was actually Operand!
                if (lastType == OPERAND){
                    // Append Number!
                    appendOperand(output, tempInt);
                    tempInt = 0;
                }

                // Check if current character is opening bracket
                if (input[i] == '(') {
                    appendOperator(output, '*');
                    appendOperator(output, '(');
                    lastType = OPEN_BRACKET;
                    ++bracketLayer;
                }
                // Check if current character is closing bracket
                else if (input[i] == ')') {
                    appendOperator(output, ')');
                    lastType = CLOSE_BRACKET;
                    --bracketLayer;
                }
                // Check if current character is operator
                else if (getPrecedence(input[i])) {
                    appendOperator(output, input[i]);
                    lastType = OPERATOR;
                }
                else {
                    char errorMessage[MAX_ERROR_LEN];
                    snprintf(errorMessage, MAX_ERROR_LEN, "Unexpected Character In Input: %c At Location %d", input[i], i);
                    return setError(errorHandler, "Parser", errorMessage);
                }
            }
            // Handle if last character was an operator or opening bracket
            else if (lastType == OPERATOR || lastType == OPEN_BRACKET) {
                // Special Condition if Negative in Brackets
                if (lastType == OPEN_BRACKET && input[i] == '-') {
                    appendOperand(output, 0);
                    appendOperator(output, '-');
                    lastType = OPERATOR;
                }
                // Check if opening bracket
                else if (input[i] == '(') {
                    appendOperator(output, '(');
                    lastType = OPEN_BRACKET;
                    ++bracketLayer;
                }
                else {
                    char errorMessage[MAX_ERROR_LEN];
                    snprintf(errorMessage, MAX_ERROR_LEN, "Unexpected Character In Input: %c At Location %d", input[i], i);
                    return setError(errorHandler, "Parser", errorMessage);
                }
            }
            else {
                char errorMessage[MAX_ERROR_LEN];
                snprintf(errorMessage, MAX_ERROR_LEN, "Runtime Error: Unknown Last Datatype: %d", lastType);
                return setError(errorHandler, "Parser", errorMessage);
            }
        }
        ++i;
    }

    // Error Checks
    // Check if last character is open bracket or operator
    if (lastType == OPERATOR || lastType == OPEN_BRACKET){
        char errorMessage[MAX_ERROR_LEN];
        snprintf(errorMessage, MAX_ERROR_LEN, "Unexpected Last Character: %c", input[i-1]);
        return setError(errorHandler, "Parser", errorMessage);
    }

    // Check if brackets are balanced
    if (bracketLayer != 0) {
        return setError(errorHandler, "Parser", "Unbalanced Brackets");
    }

    // Return Parsed LinkedList
    return output;
}
