// Linked List Manager
// head -> First element of linked list
// tail -> Last element of linked list
typedef struct {
    void * head;
    void * tail;
    int nodes;
} LinkedList;

// Linked List Header
// Indicates Type of Node
// type -> Type of data
// next -> Pointer to next node
// prev -> Pointer to previous node
typedef struct {
    int type;
    void * next;
    void * prev;
} LLNode;

// Linked List Operator Node
// type -> Type of data (VALUE 0) (OPERATOR)
// next -> Pointer to next node
// prev -> Pointer to previous node
// operator -> Operator stored inside node
typedef struct {
    int type;
    void * next;
    void * prev;
    char operator;
} LLOperator;

// Linked List Operand Node
// type -> Type of data (VALUE 1) (OPERAND)
// next -> Pointer to next node
// prev -> Pointer to previous node
// operand -> Operator stored inside node
typedef struct {
    int type;
    void * next;
    void * prev;
    long double operand;
} LLOperand;

// Linked List Bracket Node
// type -> Type of data (VALUE 2) (BRACKET)
// next -> Pointer to next node
// prev -> Pointer to previous node
// bracket -> Type of Bracket Stored Inside (OPEN_BRACKET or CLOSED_BRACKET)
typedef struct {
    int type;
    void * next;
    void * prev;
    int bracket;
} LLBracket;

// Funtions
LinkedList* createLinkedList();
void pushOperatorToHead(LinkedList* ll, char operator);
void pushOperatorToTail(LinkedList* ll, char operator);
void pushOperandToHead(LinkedList* ll, long double operand);
void pushOperandToTail(LinkedList* ll, long double operand);
void pushBracketToHead(LinkedList* ll, int bracket);
void pushBracketToTail(LinkedList* ll, int bracket);
int peekHeadType(LinkedList* ll);
int peekTailType(LinkedList* ll);
char peekOperatorFromHead(LinkedList* ll);
char peekOperatorFromTail(LinkedList* ll);
long double peekOperandFromHead(LinkedList* ll);
long double peekOperandFromTail(LinkedList* ll);
int peekBracketFromHead(LinkedList* ll);
int peekBracketFromTail(LinkedList* ll);
char popOperatorFromHead(LinkedList* ll);
char popOperatorFromTail(LinkedList* ll);
long double popOperandFromHead(LinkedList* ll);
long double popOperandFromTail(LinkedList* ll);
int popBracketFromHead(LinkedList* ll);
int popBracketFromTail(LinkedList* ll);
void deleteLinkedList(LinkedList* ll);
void linkedListDebugPrint(LinkedList* ll);
