#include <stdbool.h>

typedef struct node QUEUE_NODE;
typedef struct queue QUEUE;

//	Prototype Declarations
QUEUE* createQueue (void);
bool enqueue (QUEUE* queue, void* itemPtr);
bool dequeue (QUEUE* queue, void** itemPtr);
bool queueFront (QUEUE* queue, void** itemPtr);
bool queueRear (QUEUE* queue, void** itemPtr);
bool emptyQueue (QUEUE* queue);
bool fullQueue (QUEUE* queue);
int queueCount(QUEUE* queue);
QUEUE* destroyQueue (QUEUE* queue);

