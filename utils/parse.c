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

void parseInput(char* input, LinkedList* output, ErrorHandler* errorHandler) {
    // Init Vars
    long double tempNum = 0;
    int isNegative = false;
    int decimal = 0;  // How many Decimals
    int i = 0;
    int bracketLayer = 0;
    int lastType;

    // Sanity check -> Check if input was given!
    if (input[0] == '\0') {
        setError(errorHandler, "Parser", "No Input Was Given!");
        return;
    }

    // Sanity check -> Checks if first character is a number or operator
    if (isNum(input[0]) || input[0] == '(') {
        lastType = OPERATOR;
    }
    // Special Condition for Negative Numbers
    else if (input[0] == '-') {
        lastType = OPERATOR;
        isNegative = true;
        i++;
    }
    else {
        char errorMessage[MAX_ERROR_LEN];
        snprintf(errorMessage, MAX_ERROR_LEN, "Unexpected Character In Input: %c At Location 0", input[0]);
        setError(errorHandler, "Parser", errorMessage);
        return;
    }

    // Loop Through All Characters of the Input and Parse Into Linked List
    while (true) {
        // Handle Number
        if (isNum(input[i])) {
            // Handle if last type was a closing bracket
            // NOT ALLOWED!
            if (lastType == CLOSE_BRACKET) {
                char errorMessage[MAX_ERROR_LEN];
                snprintf(errorMessage, MAX_ERROR_LEN, "Unexpected Operand In Input: %c At Location %d", input[i], i+1);
                setError(errorHandler, "Parser", errorMessage);
                return;
            }

            // Process Number
            if (decimal) {
                // Process Decimal
                tempNum = tempNum + (input[i] - '0') * pow(0.1, decimal);
                ++decimal;
            }
            else {
                // Process Non-Decimal Number
                tempNum = tempNum*10 + input[i] - '0';
            }
            lastType = OPERAND;
        }
        // Handle Decimal
        else if (input[i] == '.') {
            // Check if decimal is already set
            if (decimal) {
                char errorMessage[MAX_ERROR_LEN];
                snprintf(errorMessage, MAX_ERROR_LEN, "Multiple Decimal Points in One Number At Location %d", i+1);
                setError(errorHandler, "Parser", errorMessage);
                return;
            }
            ++decimal;
        }
        // Handle Anything Else (Not Number!)
        else {
            // Handle if last character was a number or closing bracket
            if (lastType == OPERAND || lastType == CLOSE_BRACKET) {
                // Only Push Number if last was actually Operand!
                if (lastType == OPERAND){
                    // Push Number!
                    if (isNegative) {
                        tempNum = -1 * tempNum;
                    }
                    pushOperandToTail(output, tempNum);
                    tempNum = 0;
                    decimal = 0;
                    isNegative = false;
                }

                // Check if current character is opening bracket
                if (input[i] == '(') {
                    pushOperatorToTail(output, '*');
                    pushOperatorToTail(output, '(');
                    lastType = OPEN_BRACKET;
                    ++bracketLayer;
                }
                // Check if current character is closing bracket
                else if (input[i] == ')') {
                    pushOperatorToTail(output, ')');
                    lastType = CLOSE_BRACKET;
                    --bracketLayer;
                }
                // Check if current character is operator
                else if (getPrecedence(input[i])) {
                    pushOperatorToTail(output, input[i]);
                    lastType = OPERATOR;
                }
                // Check if End of String
                else if (input[i] == '\0') {
                    break;
                }
                else {
                    char errorMessage[MAX_ERROR_LEN];
                    snprintf(errorMessage, MAX_ERROR_LEN, "Unexpected Operand In Input: %c At Location %d", input[i], i+1);
                    setError(errorHandler, "Parser", errorMessage);
                    return;
                }
            }
            // Handle if last character was an operator or opening bracket
            else if (lastType == OPERATOR || lastType == OPEN_BRACKET) {
                // Special Condition if Negative in Brackets
                if (input[i] == '-') {
                    lastType = OPERATOR;
                    isNegative = true;
                }
                // Check if opening bracket
                else if (input[i] == '(') {
                    pushOperatorToTail(output, '(');
                    lastType = OPEN_BRACKET;
                    ++bracketLayer;
                }
                // Check if End of String
                else if (input[i] == '\0') {
                    break;
                }
                else {
                    char errorMessage[MAX_ERROR_LEN];
                    snprintf(errorMessage, MAX_ERROR_LEN, "Unexpected Operator In Input: %c At Location %d", input[i], i+1);
                    setError(errorHandler, "Parser", errorMessage);
                    return;
                }
            }
            else {
                char errorMessage[MAX_ERROR_LEN];
                snprintf(errorMessage, MAX_ERROR_LEN, "Runtime Error: Unknown Last Datatype: %d", lastType);
                setError(errorHandler, "Parser", errorMessage);
                return;
            }
        }
        ++i;
    }

    // Error Checks
    // Check if last character is open bracket or operator
    if (lastType == OPERATOR || lastType == OPEN_BRACKET){
        char errorMessage[MAX_ERROR_LEN];
        snprintf(errorMessage, MAX_ERROR_LEN, "Unexpected Last Character: %c", input[i-1]);
        setError(errorHandler, "Parser", errorMessage);
        return;
    }

    // Check if brackets are balanced
    if (bracketLayer != 0) {
        setError(errorHandler, "Parser", "Unbalanced Brackets");
        return;
    }
}
