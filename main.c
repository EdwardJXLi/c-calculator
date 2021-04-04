#include "utils/common.h"
#include "utils/error.h"
#include "utils/linkedlist.h"
#include "utils/parse.h"

int main()
{
    // Create a test input that hopefully tries out all test cases
    char testInput[] = "   1 + 22 /11 + (123456+9-9+4    * 5) + 5(8)(7-55)10( -123 (4 * 2) )";

    // Print Out Test Cases
    printf("%s\n", testInput);

    // Create Error Handler
    ErrorHandler* errorHandler = createErrorHandler();

    // Parse User Input
    LinkedList* parsedInput = parseInput(testInput, errorHandler);

    // Check Error
    if (errorHandler->error) {
        // Print Out Error
        printError(errorHandler);
    }
    else {
        // Debug Print LinkedList
        linkedListDebugPrint(parsedInput);
    }
}
