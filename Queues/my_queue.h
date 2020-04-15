#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>

typedef struct item
{
	int data;
} Item;

#define MAXQUEUE 100

typedef struct node
{
	struct item item;
	struct node* next;
} Node;

typedef struct queue
{
	Node* front;
	Node* tail;
	int length;
} Queue;

void init (Queue* queue);
bool is_full (const Queue* queue);
bool is_empty (const Queue* queue);
int queue_length (const Queue* queue);
void traverse (const Queue* queue, void (* func_ptr) (Item item));
bool enqueue (Queue* queue, Item item);
bool dequeue (Queue* queue, Item *item_ptr);
void clear (Queue* queue);

#endif