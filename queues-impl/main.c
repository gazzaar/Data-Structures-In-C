#include "queue.h"

int main(void) {
  Queue q;
  QueueEntry e;
  CreateQueue(&q);
  Append('A', &q);
  Append('B', &q);
  Append('C', &q);
  Serve(&e, &q);
}
