/**
 * File: eval.c
 * Description: Evaluate Postfix Expression
 */

#include "common.h"
#include "linkedlist.h"
#include "error.h"
#include "helpers.h"
#include "eval.h"

// Function to Evaluate Postfix Expression
long double evalExpression(LinkedList* expression, ErrorHandler* errorHandler) {
    // Create Stack to Store Values
    LinkedList* stack = createLinkedList();
    // Temporary Variables
    long double val1, val2, res;
    char operator;
    long double operand;

    // Pop through all values in expression
    while (expression->nodes) {
        switch (peekHeadType(expression)) {
            case OPERAND: ;
                // If operand, push value to stack
                operand = popOperandFromHead(expression);
                pushOperandToTail(stack, operand);
                break;
            case OPERATOR: ;
                // If operator, grab the first two values from stack and do operation
                // Then push value back on stack
                operator = popOperatorFromHead(expression);
                val1 = popOperandFromTail(stack);
                val2 = popOperandFromTail(stack);

                // Do operations
                switch (operator) {
                    case '+': res = val2 + val1; break; 
                    case '-': res = val2 - val1; break; 
                    case '*': res = val2 * val1; break; 
                    case '/': res = val2 / val1; break; 
                    case '^': res = pow(val2, val1); break; 
                }

                // Push to Stack
                pushOperandToTail(stack, res);

                break;
            default: ;
                char errorMessage[MAX_ERROR_LEN];
                snprintf(errorMessage, MAX_ERROR_LEN, "RuntimeError: Unknown Node Type %d", peekHeadType(expression));
                setError(errorHandler, "Evaluate", errorMessage);
                free(stack);
                return 0;
        }
    }

    // Sanity Checks
    if (stack->nodes != 1) {
        char errorMessage[MAX_ERROR_LEN];
        snprintf(errorMessage, MAX_ERROR_LEN, "RuntimeError: Unfinished Postfix Operation! %d nodes left in stack, expected 1", stack->nodes);
        setError(errorHandler, "Evaluate", errorMessage);
        free(stack);
        return 0;
    }

    // Get Result
    res = popOperandFromTail(stack);

    // Free Stack
    free(stack);

    return res;
}