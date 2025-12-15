#include "stack.h"


void CreateStack(Stack *ps) { ps->top = 0; };

void Push(StackEntry e, Stack *ps) {
  ps->entry[ps->top] = e;
  ps->top++;
}

int StackFull(Stack *ps) {
  if (ps->top == MAXSTACK) {
    return 1;
  } else {
    return 0;
  }
}

void Pop(StackEntry *pe, Stack *ps) {
  ps->top--;
  *pe = ps->entry[ps->top];
}

int StackEmpty(Stack *ps) {
  if (ps->top == 0) {
    return 1;
  } else {
    return 0;
  }
}

void StackTop(StackEntry *pe, Stack *ps) { *pe = ps->entry[ps->top - 1]; }

int StackSize(Stack *ps) { return ps->top; }
void ClearStack(Stack *ps) { ps->top = 0; }

void TraverseStack(Stack *ps, void (*pf)(StackEntry e)) {
  for (int i = ps->top; i > 0; i--) {
    (*pf)(ps->entry[i - 1]);
  }
}
