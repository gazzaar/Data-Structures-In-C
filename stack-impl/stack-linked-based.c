#include "stack.h"
#include <stdlib.h>

void CreateStack(Stack *ps) {
  ps->top = NULL;
  ps->size = 0;
};

void Push(StackEntry e, Stack *ps) {
  StackNode *pn = (StackNode *)malloc(sizeof(StackNode));
  pn->entry = e;
  pn->next = ps->top;
  ps->top = pn;
  ps->size++;
}

void Pop(StackEntry *pe, Stack *ps) {
  StackNode *pn;
  *pe = ps->top->entry;
  pn = ps->top;
  ps->top = ps->top->next;
  free(pn);
  ps->size--;
}

int StackEmpty(Stack *ps) { return ps->top == NULL; }
int StackFull(Stack *ps) { return 0; };
void StackTop(StackEntry *pe, Stack *ps) { *pe = ps->top->entry; };

void ClearStack(Stack *ps) {
  StackNode *pn = ps->top;
  StackNode *qn = ps->top;
  while (pn) {
    pn = pn->next;
    free(qn);
    qn = pn;
  }
  ps->top = NULL;
  ps->size = 0;
};

void TraverseStack(Stack *ps, void (*pf)(StackEntry)) {
  StackNode *pn = ps->top;
  while (pn) {
    (*pf)(pn->entry);
    pn = pn->next;
  }
};

int main() {
  StackEntry e;
  Stack s;

  CreateStack(&s);
}
