/**
 * File: linkedlist.c
 * Description: Custom implemented linked list to store operators and operands
 */

// Import Libraries
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h" 

// Function to Initiate a Linked List Object
LinkedList* createLinkedList() {
    // Malloc Linked List
    LinkedList* ll = (LinkedList*)malloc(sizeof(LinkedList));

    // Set Default Values
    ll->first = NULL;
    ll->last = NULL;
    ll->nodes = 0;

    // Return Pointer to Linked List
    return ll;
}

// Function to Add Node to the End of a Linked List
void appendNode(LinkedList* ll, int type, int data) {
    // Create and Malloc Operator Node
    LLNode* node = (LLNode*)malloc(sizeof(LLNode));

    // Set Base Values of Node
    node->type = type;
    node->next = NULL;
    node->back = NULL;
    node->data = data;

    // Set Values
    if (ll->nodes == 0) {
        // Set Pointers for First Node
        ll->first = node;
        ll->last = node;
    }
    else {
        // Get the Last Node
        LLNode* lastNode = (LLNode*)ll->last;

        // Set Last Node to the Back Pointer of Node
        node->back = lastNode;
        // Set Last Node's Next Pointer to Current Node
        lastNode->next = node;
        // Set pointer of Last Node to New Node
        ll->last = node;
    }
    ++ll->nodes;  // Increment Number of Nodes
}

// Function to Append Operator
void appendOperator(LinkedList* ll, char data) {
    appendNode(ll, LL_OPERATOR, (int)data);
}

// Function to Append Operand
void appendOperand(LinkedList* ll, int data) {
    appendNode(ll, LL_OPERAND, data);
}

// Function to Get Type of Node from the End of a Linked List
int peekNodeType(LinkedList* ll) {
    // Check if there are still nodes in the Linked List
    if (!ll->nodes){
        return -1;  // None to get!
    }

    // Get Current Last Node
    LLNode* node = (LLNode*)ll->last;
    
    // Return Type of Last Node
    return node->type;
}

// Function to Get Value of Node from the End of a Linked List
int peekNode(LinkedList* ll) {
    // Check if there are still nodes in the Linked List
    if (!ll->nodes){
        return -1;  // None to get!
    }

    // Get Current Last Node
    LLNode* node = (LLNode*)ll->last;
    
    // Return Data of Last Node
    return node->data;
}

// Function to get value of last operator
char peekOperator(LinkedList* ll) {
    return (char)peekNode(ll);
}

// Function to get value of last operand
int peekOperand(LinkedList* ll) {
    return peekNode(ll);
}

// Function to Remove Node from the End of a Linked List
int popNode(LinkedList* ll) {
    // Check if there are still nodes in the Linked List
    if (!ll->nodes){
        return -1;  // None to pop!
    }

    // Get Current Last Node
    LLNode* node = (LLNode*)ll->last;
    int data = node->data;

    // Decrement Number of Nodes
    --ll->nodes;
    
    // Set Values
    if (ll->nodes == 0) {
        ll->first = NULL;
        ll->last = NULL;
    }
    else {
        // Get the Previous Node
        LLNode* previousNode = (LLNode*)node->back;

        // Set Last Node Pointer to Previous
        ll->last = previousNode;
        // Set Next Pointer of Previous to NULL
        previousNode->next = NULL;
    }

    // Dealloc Node
    free(node);

    // Return the Data
    return data;
}

// Function to pop value of last operator
char popOperator(LinkedList* ll) {
    return (char)popNode(ll);
}

// Function to pop value of last operand
int popOperand(LinkedList* ll) {
    return popNode(ll);
}

void deleteLinkedList(LinkedList* ll){
    LLNode* current = ll->first;

    // Delete All Nodes until There Are No More Nodes!
    while (current) {
        // Set Next Value in Linked List
        current = current->next;

        // Dealloc Node
        free(current);
    }

    // Dealloc Linked List
    free(ll);

    return;
}

// Debug Function to Print All Values in Linked List
void linkedListDebugPrint(LinkedList* ll) {
    // Print Out Base LinkedList Info
    printf("===== Debug Print of Linked List %p =====\n", ll);
    printf("First Node: %p\n", ll->first);
    printf("Last Node: %p\n", ll->last);
    printf("# Nodes: %d\n", ll->nodes);

    // For Each Node in Linked List, Print Info
    printf("===== Nodes =====\n");

    // Iterate Through and Get Nodes
    LLNode* current = ll->first;
    while (current) {
        printf("Node at %p - Type: %d - Data: %d\n", current, current->type, current->data);
        printf("() [%p] <-> [[%p]] <-> [%p] )\n", current->back, current, current->next);
        current = current->next;
    }
    printf("=================\n");
}
