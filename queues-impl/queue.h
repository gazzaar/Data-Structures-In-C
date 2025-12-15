#define MAXQUEUE 10

typedef char QueueEntry;

/* -------- Queue Linked Implementaion --------------*/
typedef struct queueNode {
  QueueEntry entry;
  struct queueNode *next;

} QueueNode;

typedef struct queue {
  QueueNode *front;
  QueueNode *rear;
  int size;

} Queue;

void CreateQueue(Queue *);
void Append(QueueEntry, Queue *);
void Serve(QueueEntry *, Queue *);
int EmptyQueue(Queue *);
int QueueFull(Queue *);
int QueueSize(Queue *);
void TraverseQueue(Queue *, void (*)(QueueEntry));
void ClearQueue(Queue *);
