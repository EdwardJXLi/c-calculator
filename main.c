#include <stdio.h>
#include "utils/clean.h"

int main()
{
    // Create a test input that hopefully tries out all test cases
    char testInput[] = "   1 + 2 /3 + (1+2-3+4    * 5)";

    // Clean Input
    removeSpaces(testInput);

    // Print Out Test Cases
    printf("%s\n", testInput);
}
