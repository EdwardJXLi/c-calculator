#include "utils/common.h"
#include "utils/error.h"
#include "utils/linkedlist.h"
#include "utils/parse.h"
#include "utils/convert.h"
#include "utils/eval.h"

int main()
{
    // --- Test Input ---
    // Create a test input that hopefully tries out all test cases
    // char testInput[] = "2+2*(2^2-2)^(2+2*2)-2";
    char testInput[] = "   -1 + 22 /11.4 + (123.456+9-9+4.987    * 5) + 5(8.123)(7-55)-10.4( -123 (4 ^ 2.6) ) + .5 * -97 - 2.";
    // Expected: 45170.5787674
    // Output: 45170.578767

    // Print Out Test Cases
    printf("%s\n", testInput);

    // Create Error Handler
    ErrorHandler* errorHandler = createErrorHandler();

    // Create Linked List of Parsed Input
    LinkedList* expression = createLinkedList();

    // --- Input Parsing ---

    // Clean Input
    removeSpaces(testInput);

    // Parse User Input
    parseInput(testInput, expression, errorHandler);

    // Check Error
    if (errorHandler->error) {
        // Print Out Error
        printError(errorHandler);
        goto cleanup;
    }
    else {
        // Debug Print LinkedList
        linkedListPrintExp(expression);
        linkedListDebugPrint(expression);
    }

    // --- Convert Infix Notation into Postfix Notation ---

    // Infix to Postfix
    infixToPostfix(expression, errorHandler);

    // Check Error
    if (errorHandler->error) {
        // Print Out Error
        printError(errorHandler);
        goto cleanup;
    }
    else {
        // Debug Print LinkedList
        linkedListPrintExp(expression);
        linkedListDebugPrint(expression);
    }

    // Eval Postfix Expression

    // Eval
    long double result = evalExpression(expression, errorHandler);

    // Check Error
    if (errorHandler->error) {
        // Print Out Error
        printError(errorHandler);
        goto cleanup;
    }
    else {
        // Print Result
        printf("Result is: %Lf\n", result);
    }

    // --- Free Allocated Memory ---

    cleanup:
    // Free Memory
    deleteLinkedList(expression);
    destroyErrorHandler(errorHandler);

    printf("Exiting...\n");
}
