#define MAXSTACK 100
typedef char StackEntry;

/*------------ Linked Based----------*/

typedef struct stackNode {
  StackEntry entry;
  struct stackNode *next;

} StackNode;

typedef struct stack {
  StackNode *top;
  int size;

} Stack;

/*-------- Array Based---------
typedef struct stack {
  int top;
  StackEntry entry[MAXSTACK];

} Stack;
*/

void Push(StackEntry, Stack *);
void Pop(StackEntry *, Stack *);
int StackEmpty(Stack *);
int StackFull(Stack *);
void CreateStack(Stack *);
void StackTop(StackEntry *, Stack *);
void ClearStack(Stack *);
void TraverseStack(Stack *, void (*)(StackEntry));
