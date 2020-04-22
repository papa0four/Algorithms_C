#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

Queue* init (int size)
{
	if (size < 0)
	{
		return NULL;
	}

	Queue* q_ptr = calloc(1, sizeof(*q_ptr));
	if (q_ptr == NULL)
	{
		perror("Could not allocate memory for q_ptr in init");
		exit(EXIT_FAILURE);
	}

	q_ptr->capacity = size;
	q_ptr->front = q_ptr->length = 0;
	q_ptr->tail = size - 1;

	q_ptr->items = calloc(MAXQUEUE, sizeof(void*));
	if (!q_ptr->items)
	{
		free(q_ptr);
		return NULL;
	}

	return q_ptr;
}

bool is_full (Queue* q_ptr)
{
	return q_ptr->length == q_ptr->capacity;
}

bool is_empty (Queue* q_ptr)
{
	return q_ptr->tail == q_ptr->front;
}

bool enqueue (Queue* q_ptr, void* item)
{
	if (is_full(q_ptr))
	{
		return false;
	}

	q_ptr->length += 1;
	q_ptr->tail = (q_ptr->tail + 1) % q_ptr->capacity;
	q_ptr->items[q_ptr->tail] = item;	

	return true;
}

void dequeue (Queue* q_ptr)
{
	if (is_empty(q_ptr))
	{
		printf("Queue is empty\n");
	}
	else 
	{
		void* item = q_ptr->items[q_ptr->front];
		printf("Item to be removed from front of queue: %ld\n", (long) q_ptr->items[q_ptr->front]);
		q_ptr->front = (q_ptr->front + 1) % q_ptr->capacity;
	}

	q_ptr->length -= 1;
}

void* peek (Queue* q_ptr)
{
	return q_ptr->items[q_ptr->front];
}


void destroy_q (Queue* q_ptr)
{
	printf("Destroying queue...\n");
	free(q_ptr->items);
	q_ptr->front = 0;
	q_ptr->tail = 0;
	q_ptr->length = -1;
	q_ptr->capacity = 0;
	q_ptr->items = NULL;
}

int main ()
{
	Queue* q_ptr = init(10);

	bool check;

	for (size_t i = 10; i <= 100; i += 10)
	{
		check = enqueue(q_ptr, (void*) i);
		if (!check)
		{
			printf("Your queue has contracted COVID-19! ERADICATE IMMEDIATELY!!!\n");
		}

		printf("%ld added to queue\n", (long) i);
	}

	for (size_t i = q_ptr->capacity; i > 1; i--)
	{
		dequeue(q_ptr);
		printf("New head of queue: %ld\n", (long) peek(q_ptr));
	}

	destroy_q(q_ptr);
	free(q_ptr);

	return 0;
}