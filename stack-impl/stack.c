#include "stack.h"
#include <stdlib.h>

#ifdef LIMITED_MEMORY
/* ----------Array Based functions---------- */
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
#else 

/* ----------Linked Based Functions---------- */

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

#endif
