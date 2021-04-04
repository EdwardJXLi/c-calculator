// Linked List Node Types
#define LL_OPERATOR 0
#define LL_OPERAND 1

// Linked List Manager
// first -> First element of linked list
// last -> Last element of linked list
typedef struct {
    void * first;
    void * last;
    int nodes;
} LinkedList;

// Linked List Data Node
// type -> Type of data (VALUE 0) (LL_OPERAND)
// next -> Pointer to next node
// prev -> Pointer to previous node
// data -> Operand and/or Operator stored inside node
typedef struct {
    int type;
    void * next;
    void * back;
    int data;
} LLNode;

// Funtions
LinkedList* createLinkedList();
void appendNode(LinkedList* ll, int type, int data);
void appendOperator(LinkedList* ll, char data);
void appendOperand(LinkedList* ll, int data);
int peekNodeType(LinkedList* ll);
int peekNode(LinkedList* ll);
char peekOperator(LinkedList* ll);
int peekOperand(LinkedList* ll);
int popNode(LinkedList* ll);
char popOperator(LinkedList* ll);
int popOperand(LinkedList* ll);
void deleteLinkedList(LinkedList* ll);
void linkedListDebugPrint(LinkedList* ll);
