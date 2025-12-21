#define LIMITED_MEMORY
typedef char QueueEntry;

#ifndef LIMITED_MEMORY

/* -------------- Queue Linked Implementaion --------------*/
typedef struct queueNode {
  QueueEntry entry;
  struct queueNode *next;

} QueueNode;

typedef struct queue {
  QueueNode *front;
  QueueNode *rear;
  int size;

} Queue;

#else 

/* -------------- Array Based Implementaion --------------*/
#define MAXQUEUE 10

typedef struct queue{
  QueueEntry entry[MAXQUEUE];
  int front;
  int rear;
  int size;

}Queue ;

#endif

void CreateQueue(Queue *);
void Append(QueueEntry, Queue *);
void Serve(QueueEntry *, Queue *);
int EmptyQueue(Queue *);
int QueueFull(Queue *);
int QueueSize(Queue *);
void TraverseQueue(Queue *, void (*)(QueueEntry));
void ClearQueue(Queue *);
