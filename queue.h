#ifndef _QUEUE_H_
#define _QUEUE_H_

#define SUCCESS		0
#define INVALID_QUEUE	-1
#define EMPTY_QUEUE	-2

struct queue_element {
	int elem;
	struct queue_element *next;
};

struct queue {
	struct queue_element *first, *last;
	int counter;
};

typedef struct queue QUEUE;
typedef struct queue_element QUEUE_ELEMENT;

QUEUE *queue_create();
int queue_enqueue(QUEUE *, int);
int queue_dequeue(QUEUE *, int *);
int queue_first(QUEUE *, int *);
int queue_size(QUEUE *);
int queue_free(QUEUE *);

#endif
