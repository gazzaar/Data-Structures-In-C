#include "stack.h"
#include "stdio.h"

void Display(StackEntry e) { printf("e is: %d\n", e); }

int main() {
  Stack s;
  StackEntry e;

  CreateStack(&s);
  if (!StackFull(&s)) {
    Push(e, &s);
  }

  if (!StackEmpty(&s)) {
    Pop(&e, &s);
  }
}
