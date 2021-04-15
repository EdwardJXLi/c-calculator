/**
 * File: convert.c
 * Description: Variety of functions to convert values from one datatype to another
 */

#include "common.h"
#include "linkedlist.h"
#include "error.h"
#include "helpers.h"
#include "convert.h" 

// Convert Infix to Postfix for Input Expression
// NOTE: This implementation will use the same linked list for input and output
void infixToPostfix(LinkedList* expression, ErrorHandler* errorHandler) {
    // Save length of original expression
    int expLen = expression->nodes;
    // Temporary Variables
    long double operand;
    char operator;
    char scannedOperator;
    char top;
    int bracket;
    // Temporary Stack to Store Operators
    LinkedList* operatorStack = createLinkedList();

    // Loop Through All Values in Infix Expression
    for (int i = 0; i < expLen; i++) {
        switch (peekHeadType(expression)) {
            case OPERAND: ;
                // Push Operand Onto Output
                operand = popOperandFromHead(expression);
                pushOperandToTail(expression, operand);
                break;
            case OPERATOR: ;
                scannedOperator = popOperatorFromHead(expression);
                // Check something
                switch (peekOperatorFromTail(operatorStack)) {
                    case LLEMPTYNODE: ;
                        // If operator stack is empty, push operator into stack
                        pushOperatorToTail(operatorStack, scannedOperator);
                        break;
                    case LLTYPEERROR: ;
                        // TODO: Handle Error
                        char errorMessage[MAX_ERROR_LEN];
                        snprintf(errorMessage, MAX_ERROR_LEN, "RuntimeError: Unknown Operator Type at location %d", i+1);
                        setError(errorHandler, "InfixToPostfix", errorMessage);
                        free(operatorStack);
                        return;
                    default: ;
                        top = peekOperatorFromTail(operatorStack);
                        if (getPrecedence(scannedOperator) > getPrecedence(top)) {
                            // If precedence of scanned operator is greater than one in stack, push operator into stack
                            pushOperatorToTail(operatorStack, scannedOperator);
                        }
                        else {
                            // Pop all operators that have greater precedence than scanned
                            while (getPrecedence(peekOperatorFromTail(operatorStack)) >= getPrecedence(scannedOperator)) {
                                operator = popOperatorFromTail(operatorStack);
                                pushOperatorToTail(expression, operator);
                            }
                            // Push Operator onto stack
                            pushOperatorToTail(operatorStack, scannedOperator);
                        }
                        break;
                }
                break;
            case BRACKET:
                bracket = popBracketFromHead(expression);
                switch (bracket) {
                    case OPEN_BRACKET: ;
                        // Push Bracket onto Stack
                        // Pushing as Operator for Simplicity
                        pushOperatorToTail(operatorStack, '(');
                        break;
                    case CLOSE_BRACKET: ;
                        // Pop All Values from Stack until next '('
                        while (peekOperatorFromTail(operatorStack) != '(') {
                            operator = popOperatorFromTail(operatorStack);
                            pushOperatorToTail(expression, operator);
                        }
                        popOperatorFromTail(operatorStack); // Discard Bracket
                        break;
                    default: ;
                        char errorMessage[MAX_ERROR_LEN];
                        snprintf(errorMessage, MAX_ERROR_LEN, "RuntimeError: Unknown Bracket Type %d at location %d", bracket, i+1);
                        setError(errorHandler, "InfixToPostfix", errorMessage);
                        free(operatorStack);
                        return;
                }
                break;
            default: ;
                char errorMessage[MAX_ERROR_LEN];
                snprintf(errorMessage, MAX_ERROR_LEN, "RuntimeError: Unknown Node Type %d at location %d", peekHeadType(expression), i+1);
                setError(errorHandler, "InfixToPostfix", errorMessage);
                free(operatorStack);
                return;
        }
    }

    // Pop all Remaining Values from Operator Stack
    while (operatorStack->nodes) {
        operator = popOperatorFromTail(operatorStack);
        pushOperatorToTail(expression, operator);
    }

    // Free Operator Stack
    free(operatorStack);

    return;
}
