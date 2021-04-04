#include <stdio.h>
#include <stdlib.h>
#include "utils/clean.h"
#include "utils/linkedlist.h"

int main()
{
    // Create a test input that hopefully tries out all test cases
    char testInput[] = "   1 + 2 /3 + (1+2-3+4    * 5)";

    // Clean Input
    removeSpaces(testInput);

    // Print Out Test Cases
    printf("%s\n", testInput);

    // Test Linked List
    printf("\nTEST: Creating Linked List\n");
    LinkedList* testList = createLinkedList();
    linkedListDebugPrint(testList);

    printf("\nTEST: Appending Operator\n");
    appendOperator(testList, '-');
    linkedListDebugPrint(testList);

    printf("\nTEST: Getting Type\n");
    printf("%d\n", peekNodeType(testList));
    
    printf("\nTEST: Popping Operator\n");
    printf("%c\n", popOperator(testList));
    linkedListDebugPrint(testList);

    printf("\nTEST: Appending Operand\n");
    appendOperand(testList, 1234);
    linkedListDebugPrint(testList);

    printf("\nTEST: Getting Type\n");
    printf("%d\n", peekNodeType(testList));
    
    printf("\nTEST: Popping Operand\n");
    printf("%d\n", popOperand(testList));
    linkedListDebugPrint(testList);

    printf("\nTEST: Appending Full Equation\n");
    appendOperand(testList, 1);
    appendOperator(testList, '+');
    appendOperand(testList, 2);
    appendOperator(testList, '-');
    appendOperand(testList, 3);
    appendOperator(testList, '*');
    appendOperand(testList, 4);
    appendOperator(testList, '/');
    appendOperand(testList, 5);
    linkedListDebugPrint(testList);

    printf("\nTEST: Free All\n");
    deleteLinkedList(testList);
}
