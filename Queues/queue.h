#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>

#define MAXQUEUE 10

typedef struct queue
{
	int front;
	int tail;
	void** items;
	int length;
	int capacity;
} Queue;

Queue* init(int size);
bool is_full (Queue* q_ptr);
bool is_empty (Queue* q_ptr);
bool enqueue (Queue* q_ptr, void* item);
void dequeue (Queue* q_ptr);
void* peek (Queue* q_ptr);
void destroy_q (Queue* q_ptr);

#endif