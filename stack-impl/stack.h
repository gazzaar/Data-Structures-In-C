typedef char StackEntry;
#define LIMITED_MEMORY

/*------------ Linked Based----------*/

#ifndef LIMITED_MEMORY

typedef struct stackNode {
  StackEntry entry;
  struct stackNode *next;

} StackNode;

typedef struct stack {
  StackNode *top;
  int size;

} Stack;

#else 

/*-------- Array Based---------*/

#define MAXSTACK 100

typedef struct stack {
  int top;
  StackEntry entry[MAXSTACK];

} Stack;
#endif

void Push(StackEntry, Stack *);
void Pop(StackEntry *, Stack *);
int StackEmpty(Stack *);
int StackFull(Stack *);
void CreateStack(Stack *);
void StackTop(StackEntry *, Stack *);
void ClearStack(Stack *);
void TraverseStack(Stack *, void (*)(StackEntry));
