#include "utils/common.h"
#include "utils/error.h"
#include "utils/linkedlist.h"
#include "utils/parse.h"
#include "utils/convert.h"

int main()
{
    // --- Test Input ---
    // Create a test input that hopefully tries out all test cases
    char testInput[] = "   -1 + 22 /11.4 + (123.456+9-9+4.987    * 5) + 5(8.123)(7-55)-10.4( -123 (4 ^ 2.6 ^-2.0) ) + .5 * -97 - 2.";

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
    }
    else {
        // Debug Print LinkedList
        linkedListDebugPrint(expression);
    }

    // --- Convert Infix Notation into Postfix Notation ---

    /*
    // Infix to Postfix
    infixToPostfix(expression, errorHandler);

    // Check Error
    if (errorHandler->error) {
        // Print Out Error
        printError(errorHandler);
    }
    else {
        // Debug Print LinkedList
        linkedListDebugPrint(errorHandler);
    }
    */

    // --- Free Allocated Memory ---

    // Free Memory
    deleteLinkedList(expression);
    destroyErrorHandler(errorHandler);
    // deleteLinkedList(postfixInput);
}
