/**
 * File: linkedlist.c
 * Description: Custom implemented linked list to store operators and operands
 */

#include "common.h"
#include "linkedlist.h" 

// Function to Initiate a Linked List Object
LinkedList* createLinkedList() {
    // Malloc Linked List
    LinkedList* ll = (LinkedList*)malloc(sizeof(LinkedList));

    // Set Default Values
    ll->head = NULL;
    ll->tail = NULL;
    ll->nodes = 0;

    // Return Pointer to Linked List
    return ll;
}

// Function to Push Operator to Head
void pushOperatorToHead(LinkedList* ll, char operator) {
    // Create and Malloc Operator Node
    LLOperator* node = (LLOperator*)malloc(sizeof(LLOperator));

    // Set Base Values of Node
    node->type = OPERATOR;
    node->next = NULL;
    node->prev = NULL;
    node->operator = operator;

    // Set Values
    if (ll->nodes == 0) {
        // Set Pointers for Linked List Manager
        ll->head = node;
        ll->tail = node;
    }
    else {
        // Get the head Node
        LLNode* headNode = (LLNode*)ll->head;

        // Set Head Node to the Next Pointer of Current Node
        node->next = headNode;
        // Set Head Node's Previous Pointer to Current Node
        headNode->prev = node;
        // Set pointer of Head Node to Current Node
        ll->head = node;
    }
    ++ll->nodes;  // Increment Number of Nodes
}

// Function to Push Operator to Tail
void pushOperatorToTail(LinkedList* ll, char operator) {
    // Create and Malloc Operator Node
    LLOperator* node = (LLOperator*)malloc(sizeof(LLOperator));

    // Set Base Values of Node
    node->type = OPERATOR;
    node->next = NULL;
    node->prev = NULL;
    node->operator = operator;

    // Set Values
    if (ll->nodes == 0) {
        // Set Pointers for Linked List Manager
        ll->head = node;
        ll->tail = node;
    }
    else {
        // Get the Tail Node
        LLNode* tailNode = (LLNode*)ll->tail;

        // Set Tail Node to the Previous Pointer of Current Node
        node->prev = tailNode;
        // Set Tail Node's Next Pointer to Current Node
        tailNode->next = node;
        // Set pointer of Tail Node to Current Node
        ll->tail = node;
    }
    ++ll->nodes;  // Increment Number of Nodes
}

// Function to Push Operand to Head
void pushOperandToHead(LinkedList* ll, long double operand) {
    // Create and Malloc Operand Node
    LLOperand* node = (LLOperand*)malloc(sizeof(LLOperand));

    // Set Base Values of Node
    node->type = OPERAND;
    node->next = NULL;
    node->prev = NULL;
    node->operand = operand;

    // Set Values
    if (ll->nodes == 0) {
        // Set Pointers for Linked List Manager
        ll->head = node;
        ll->tail = node;
    }
    else {
        // Get the head Node
        LLNode* headNode = (LLNode*)ll->head;

        // Set Head Node to the Next Pointer of Current Node
        node->next = headNode;
        // Set Head Node's Previous Pointer to Current Node
        headNode->prev = node;
        // Set pointer of Head Node to Current Node
        ll->head = node;
    }
    ++ll->nodes;  // Increment Number of Nodes
}

// Function to Push Operand to Tail
void pushOperandToTail(LinkedList* ll, long double operand) {
    // Create and Malloc Operand Node
    LLOperand* node = (LLOperand*)malloc(sizeof(LLOperand));

    // Set Base Values of Node
    node->type = OPERAND;
    node->next = NULL;
    node->prev = NULL;
    node->operand = operand;

    // Set Values
    if (ll->nodes == 0) {
        // Set Pointers for Linked List Manager
        ll->head = node;
        ll->tail = node;
    }
    else {
        // Get the Tail Node
        LLNode* tailNode = (LLNode*)ll->tail;

        // Set Tail Node to the Previous Pointer of Current Node
        node->prev = tailNode;
        // Set Tail Node's Next Pointer to Current Node
        tailNode->next = node;
        // Set pointer of Tail Node to Current Node
        ll->tail = node;
    }
    ++ll->nodes;  // Increment Number of Nodes
}

// Function to Get Type of Node from the Start/Head of the Linked List
int peekHeadType(LinkedList* ll) {
    // Check if there are still nodes in the Linked List
    if (!ll->nodes){
        return -1;  // Nothing to get!
    }

    // Get Current Head Node
    LLNode* node = (LLNode*)ll->head;
    
    // Return Type of Head Node
    return node->type;
}

// Function to Get Type of Node from the End/Tail of the Linked List
int peekTailType(LinkedList* ll) {
    // Check if there are still nodes in the Linked List
    if (!ll->nodes){
        return -1;  // Nothing to get!
    }

    // Get Current Tail Node
    LLNode* node = (LLNode*)ll->tail;
    
    // Return Type of Tail Node
    return node->type;
}

// Function to get value of Operator from Head
char peekOperatorFromHead(LinkedList* ll) {
    // Check if there are still nodes in the Linked List
    if (!ll->nodes){
        return LLEMPTYNODE;  // None to get!
    }

    // Get Current Head Node
    LLNode* node = (LLNode*)ll->head;

    // Check Node Type
    if (node->type != OPERATOR) {
        return LLTYPEERROR;
    } 

    // Cast Operator Structure
    LLOperator* operatorNode = (LLOperator*)node;
    
    // Return Operator of Last Node
    return operatorNode->operator;
}

// Function to get value of Operator from Tail
char peekOperatorFromTail(LinkedList* ll) {
    // Check if there are still nodes in the Linked List
    if (!ll->nodes){
        return LLEMPTYNODE;  // None to get!
    }

    // Get Current Tail Node
    LLNode* node = (LLNode*)ll->tail;

    // Check Node Type
    if (node->type != OPERATOR) {
        return LLTYPEERROR;
    } 

    // Cast Operator Structure
    LLOperator* operatorNode = (LLOperator*)node;
    
    // Return Operator of Last Node
    return operatorNode->operator;
}

// Function to get value of Operand from Head
long double peekOperandFromHead(LinkedList* ll) {
    // Check if there are still nodes in the Linked List
    if (!ll->nodes){
        return LLEMPTYNODE;  // None to get!
    }

    // Get Current Head Node
    LLNode* node = (LLNode*)ll->head;

    // Check Node Type
    if (node->type != OPERAND) {
        return LLTYPEERROR;
    } 

    // Cast Operand Structure
    LLOperand* operandNode = (LLOperand*)node;
    
    // Return Operand of Last Node
    return operandNode->operand;
}

// Function to get value of Operand from Tail
char peekOperandFromTail(LinkedList* ll) {
    // Check if there are still nodes in the Linked List
    if (!ll->nodes){
        return LLEMPTYNODE;  // None to get!
    }

    // Get Current Tail Node
    LLNode* node = (LLNode*)ll->tail;

    // Check Node Type
    if (node->type != OPERAND) {
        return LLTYPEERROR;
    } 

    // Cast Operand Structure
    LLOperand* operandNode = (LLOperand*)node;
    
    // Return Operand of Last Node
    return operandNode->operand;
}

// Function to pop value of Operator from Head
char popOperatorFromHead(LinkedList* ll) {
    // Check if there are still nodes in the Linked List
    if (!ll->nodes){
        return LLEMPTYNODE;  // None to get!
    }

    // Get Current Head Node
    LLNode* node = (LLNode*)ll->head;

    // Check Node Type
    if (node->type != OPERATOR) {
        return LLTYPEERROR;
    } 

    // Cast Operator Structure
    LLOperator* operatorNode = (LLOperator*)node;

    // Decrement Number of Nodes
    --ll->nodes;
    
    // Set Values
    if (ll->nodes == 0) {
        ll->head = NULL;
        ll->tail = NULL;
    }
    else {
        // Get the Next Node
        LLNode* nextNode = (LLNode*)operatorNode->next;

        // Set Previous Pointer of Next to NULL
        nextNode->prev = NULL;

        // Set Head Pointer to Next
        ll->head = nextNode;
    }

    // Free Memory of Node
    free(operatorNode);
    
    // Return Operator of Last Node
    return operatorNode->operator;
}

// Function to pop value of Operator from Tail
char popOperatorFromTail(LinkedList* ll) {
    // Check if there are still nodes in the Linked List
    if (!ll->nodes){
        return LLEMPTYNODE;  // None to get!
    }

    // Get Current Tail Node
    LLNode* node = (LLNode*)ll->tail;

    // Check Node Type
    if (node->type != OPERATOR) {
        return LLTYPEERROR;
    } 

    // Cast Operator Structure
    LLOperator* operatorNode = (LLOperator*)node;

    // Decrement Number of Nodes
    --ll->nodes;
    
    // Set Values
    if (ll->nodes == 0) {
        ll->head = NULL;
        ll->tail = NULL;
    }
    else {
        // Get the Previous Node
        LLNode* previousNode = (LLNode*)operatorNode->prev;

        // Set Next Pointer of Previous to NULL
        previousNode->next = NULL;

        // Set Tail Pointer to Previous
        ll->tail = previousNode;
    }

    // Free Memory of Node
    free(operatorNode);
    
    // Return Operator of Last Node
    return operatorNode->operator;
}

// Function to pop value of Operand from Head
long double popOperandFromHead(LinkedList* ll) {
    // Check if there are still nodes in the Linked List
    if (!ll->nodes){
        return LLEMPTYNODE;  // None to get!
    }

    // Get Current Head Node
    LLNode* node = (LLNode*)ll->head;

    // Check Node Type
    if (node->type != OPERATOR) {
        return LLTYPEERROR;
    } 

    // Cast Operand Structure
    LLOperand* operandNode = (LLOperand*)node;

    // Decrement Number of Nodes
    --ll->nodes;
    
    // Set Values
    if (ll->nodes == 0) {
        ll->head = NULL;
        ll->tail = NULL;
    }
    else {
        // Get the Next Node
        LLNode* nextNode = (LLNode*)operandNode->next;

        // Set Previous Pointer of Next to NULL
        nextNode->prev = NULL;

        // Set Head Pointer to Next
        ll->head = nextNode;
    }

    // Free Memory of Node
    free(operandNode);
    
    // Return Operand of Last Node
    return operandNode->operand;
}

// Function to pop value of Operand from Tail
long double popOperandFromTail(LinkedList* ll) {
    // Check if there are still nodes in the Linked List
    if (!ll->nodes){
        return LLEMPTYNODE;  // None to get!
    }

    // Get Current Tail Node
    LLNode* node = (LLNode*)ll->tail;

    // Check Node Type
    if (node->type != OPERAND) {
        return LLTYPEERROR;
    } 

    // Cast Operand Structure
    LLOperand* operandNode = (LLOperand*)node;

    // Decrement Number of Nodes
    --ll->nodes;
    
    // Set Values
    if (ll->nodes == 0) {
        ll->head = NULL;
        ll->tail = NULL;
    }
    else {
        // Get the Previous Node
        LLNode* previousNode = (LLNode*)operandNode->prev;

        // Set Next Pointer of Previous to NULL
        previousNode->next = NULL;

        // Set Tail Pointer to Previous
        ll->tail = previousNode;
    }

    // Free Memory of Node
    free(operandNode);
    
    // Return Operand of Last Node
    return operandNode->operand;
}

void deleteLinkedList(LinkedList* ll){
    LLNode* current = ll->head;
    LLNode* nextNode;

    // Delete All Nodes until There Are No More Nodes!
    while (current) {
        // Get the Next Value in Linked List
        nextNode = current->next;

        // Check Node Type
        free(current);

        // Set Current Node to Next Node
        current = nextNode;
    }

    // Dealloc Linked List
    free(ll);
}

// Debug Function to Print All Values in Linked List
void linkedListDebugPrint(LinkedList* ll) {
    // Print Out Base LinkedList Info
    printf("===== Debug Print of Linked List %p =====\n", ll);
    printf("Head Node: %p\n", ll->head);
    printf("Tail Node: %p\n", ll->tail);
    printf("# Nodes: %d\n", ll->nodes);

    // For Each Node in Linked List, Print Info
    printf("===== Nodes =====\n");

    // Iterate Through and Get Nodes
    LLNode* current = ll->head;
    while (current) {
        if (current->type == OPERATOR) {
            LLOperator* operatorNode = (LLOperator*)current;
            printf("Node at %p - Type: %d - Data: %c\n", operatorNode, operatorNode->type, operatorNode->operator);
        }
        else if (current->type == OPERAND) {
            LLOperand* operandNode = (LLOperand*)current;
            printf("Node at %p - Type: %d - Data: %Lf\n", operandNode, operandNode->type, operandNode->operand);
        }
        printf("() [%p] <-> [[%p]] <-> [%p] )\n", current->prev, current, current->next);
        current = current->next;
    }
    printf("=================\n");
}
