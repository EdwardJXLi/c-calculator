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

// Internal Function to Push Node to Head
void pushToHead(LinkedList* ll, LLNode* node) {
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

// Internal Function to Push Node to Tail
void pushToTail(LinkedList* ll, LLNode* node) {
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

// Function to Push Operator to Head
void pushOperatorToHead(LinkedList* ll, char operator) {
    // Create and Malloc Operator Node
    LLOperator* node = (LLOperator*)malloc(sizeof(LLOperator));

    // Set Base Values of Node
    node->type = OPERATOR;
    node->next = NULL;
    node->prev = NULL;
    node->operator = operator;

    // Handle Push to Linked List
    pushToHead(ll, (LLNode*)node);
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

    // Handle Push to Linked List
    pushToTail(ll, (LLNode*)node);
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

    // Handle Push to Linked List
    pushToHead(ll, (LLNode*)node);
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

    // Handle Push to Linked List
    pushToTail(ll, (LLNode*)node);
}

// Function to Push Bracket to Head
void pushBracketToHead(LinkedList* ll, int bracket) {
    // Create and Malloc Bracket Node
    LLBracket* node = (LLBracket*)malloc(sizeof(LLBracket));

    // Set Base Values of Node
    node->type = BRACKET;
    node->next = NULL;
    node->prev = NULL;
    node->bracket = bracket;

    // Handle Push to Linked List
    pushToHead(ll, (LLNode*)node);
}

// Function to Push Bracket to Tail
void pushBracketToTail(LinkedList* ll, int bracket) {
    // Create and Malloc Bracket Node
    LLBracket* node = (LLBracket*)malloc(sizeof(LLBracket));

    // Set Base Values of Node
    node->type = BRACKET;
    node->next = NULL;
    node->prev = NULL;
    node->bracket = bracket;

    // Handle Push to Linked List
    pushToTail(ll, (LLNode*)node);
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
    
    // Return Operator of Last Node
    return ((LLOperator*)node)->operator;
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
    
    // Return Operator of Last Node
    return ((LLOperator*)node)->operator;
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
    
    // Return Operand of Last Node
    return ((LLOperand*)node)->operand;
}

// Function to get value of Operand from Tail
long double peekOperandFromTail(LinkedList* ll) {
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
    
    // Return Operand of Last Node
    return ((LLOperand*)node)->operand;
}

// Function to get value of Bracket from Head
int peekBracketFromHead(LinkedList* ll) {
    // Check if there are still nodes in the Linked List
    if (!ll->nodes){
        return LLEMPTYNODE;  // None to get!
    }

    // Get Current Head Node
    LLNode* node = (LLNode*)ll->head;

    // Check Node Type
    if (node->type != BRACKET) {
        return LLTYPEERROR;
    }
    
    // Return Bracket of Last Node
    return ((LLBracket*)node)->bracket;
}

// Function to get value of Bracket from Tail
int peekBracketFromTail(LinkedList* ll) {
    // Check if there are still nodes in the Linked List
    if (!ll->nodes){
        return LLEMPTYNODE;  // None to get!
    }

    // Get Current Tail Node
    LLNode* node = (LLNode*)ll->tail;

    // Check Node Type
    if (node->type != BRACKET) {
        return LLTYPEERROR;
    }
    
    // Return Bracket of Last Node
    return ((LLBracket*)node)->bracket;
}

// Internal Function to Pop Node from Head
void popFromHead(LinkedList* ll, LLNode* node) {
    // Decrement Number of Nodes
    --ll->nodes;
    
    // Set Values
    if (ll->nodes == 0) {
        ll->head = NULL;
        ll->tail = NULL;
    }
    else {
        // Get the Next Node
        LLNode* nextNode = (LLNode*)node->next;

        // Set Previous Pointer of Next to NULL
        nextNode->prev = NULL;

        // Set Head Pointer to Next
        ll->head = nextNode;
    }

    // Free Memory of Node
    free(node);
}

// Internal Function to Pop Node from Tail
void popFromTail(LinkedList* ll, LLNode* node) {
    // Decrement Number of Nodes
    --ll->nodes;
    
    // Set Values
    if (ll->nodes == 0) {
        ll->head = NULL;
        ll->tail = NULL;
    }
    else {
        // Get the Previous Node
        LLNode* previousNode = (LLNode*)node->prev;

        // Set Next Pointer of Previous to NULL
        previousNode->next = NULL;

        // Set Tail Pointer to Previous
        ll->tail = previousNode;
    }

    // Free Memory of Node
    free(node);
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

    // Get Operator Value
    char operator = ((LLOperator*)node)->operator;

    // Handle Pop from Linked List
    popFromHead(ll, node);
    
    // Return Operator of Last Node
    return operator;
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

    // Get Operator Value
    char operator = ((LLOperator*)node)->operator;

    // Handle Pop from Linked List
    popFromTail(ll, node);
    
    // Return Operator of Last Node
    return operator;
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
    if (node->type != OPERAND) {
        return LLTYPEERROR;
    } 

    // Get Operand Value
    long double operand = ((LLOperand*)node)->operand;

    // Handle Pop from Linked List
    popFromHead(ll, node);
    
    // Return Operand of Last Node
    return operand;
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

    // Get Operand Value
    long double operand = ((LLOperand*)node)->operand;

    // Handle Pop from Linked List
    popFromTail(ll, node);
    
    // Return Operand of Last Node
    return operand;
}

// Function to pop value of Bracket from Head
int popBracketFromHead(LinkedList* ll) {
    // Check if there are still nodes in the Linked List
    if (!ll->nodes){
        return LLEMPTYNODE;  // None to get!
    }

    // Get Current Head Node
    LLNode* node = (LLNode*)ll->head;

    // Check Node Type
    if (node->type != BRACKET) {
        return LLTYPEERROR;
    } 

    // Get Bracket Value
    long double bracket = ((LLBracket*)node)->bracket;

    // Handle Pop from Linked List
    popFromHead(ll, node);
    
    // Return Bracket of Last Node
    return bracket;
}

// Function to pop value of Bracket from Tail
int popBracketFromTail(LinkedList* ll) {
    // Check if there are still nodes in the Linked List
    if (!ll->nodes){
        return LLEMPTYNODE;  // None to get!
    }

    // Get Current Tail Node
    LLNode* node = (LLNode*)ll->tail;

    // Check Node Type
    if (node->type != BRACKET) {
        return LLTYPEERROR;
    } 

    // Get Bracket Value
    long double bracket = ((LLBracket*)node)->bracket;

    // Handle Pop from Linked List
    popFromTail(ll, node);
    
    // Return Bracket of Last Node
    return bracket;
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

// Function to Print Linked List as Expression
void linkedListPrintExp(LinkedList* ll) {
    // Iterate Through and Get Nodes
    LLNode* current = ll->head;
    while (current) {
        switch (current->type) {
            case OPERATOR: ;
                LLOperator* operatorNode = (LLOperator*)current;
                printf("%c ", operatorNode->operator);
                break;
            case OPERAND: ;
                LLOperand* operandNode = (LLOperand*)current;
                printf("%Lf ", operandNode->operand);
                break;
            case BRACKET: ;
                LLBracket* bracketNode = (LLBracket*)current;
                printf("%c ", (bracketNode->bracket == OPEN_BRACKET) ? '(' : ')');
                break;
            default:
                printf("?");
        }
        current = current->next;
    }
    printf("\n");
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
        switch (current->type) {
            case OPERATOR: ;
                LLOperator* operatorNode = (LLOperator*)current;
                printf("Node at %p - Type: %d - Data: %c\n", operatorNode, operatorNode->type, operatorNode->operator);
                break;
            case OPERAND: ;
                LLOperand* operandNode = (LLOperand*)current;
                printf("Node at %p - Type: %d - Data: %Lf\n", operandNode, operandNode->type, operandNode->operand);
                break;
            case BRACKET: ;
                LLBracket* bracketNode = (LLBracket*)current;
                printf("Node at %p - Type: %d - Data: %c (%d)\n", bracketNode, bracketNode->type, (bracketNode->bracket == OPEN_BRACKET) ? '(' : ')', bracketNode->bracket);
                break;
            default:
                printf("Unknown Node of Type %d at location %p\n", current->type, current);
        }
        printf("() [%p] <-> [[%p]] <-> [%p] )\n", current->prev, current, current->next);
        current = current->next;
    }
    printf("=================\n");
}

