#include <stdio.h>
#include <stdlib.h>
#include "utils/linkedlist.h"
#include "utils/parse.h"

int main()
{
    // Create a test input that hopefully tries out all test cases
    char testInput[] = "   1 + 2 /3 + (1+2-3+4    * 5) + 5(8)(7-5)( 123 (4 * 2) )";

    // Clean Input
    removeSpaces(testInput);

    // Print Out Test Cases
    printf("%s\n", testInput);

    // Parse User Input
    LinkedList* parsedInput = parseInput(testInput);

    // Debug Print LinkedList
    linkedListDebugPrint(parsedInput);
}
