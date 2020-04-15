#include <stdio.h>
#include <stdlib.h>
#include "my_queue.h"

//define init
void init (Queue* queue)
{
	queue->front = queue->tail = NULL;
	queue->length = 0;
}

//define is_full
bool is_full (const Queue* queue)
{
	return queue->length == MAXQUEUE;
}

//define is_empty
bool is_empty (const Queue* queue)
{
	return queue->length == 0;
}

//define queue_length
int queue_length (const Queue* queue)
{
	return queue->length;
}

//define enqueue
bool enqueue (Queue* queue, Item item)
{
	if (is_full(queue))
	{
		return false;
	}

	Node* new_node = (Node *) malloc(sizeof(Node));
	if (!new_node)
	{
		fprintf(stderr, "Unable to allocate memory for new_node\n");
		exit(1);
	}

	new_node->item = item;
	new_node->next = NULL;

	if (is_empty(queue))
	{
		queue->front = new_node;
	}
	else
	{
		queue->tail->next = new_node;
	}

	queue->tail = new_node; //remark the tail
	queue->length++;

	return true;
}

//define dequeue
bool dequeue (Queue *queue, Item *item_ptr)
{
	if (is_empty(queue))
	{
		return false;
	}

	*item_ptr = queue->front->item;

	Node* temp = queue->front;
	queue->front = queue->front->next;
	free(temp);
	queue->length--;

	if (queue->length == 0)
	{
		queue->tail = NULL;
	}

	return true;
}

//define traverse
void traverse (const Queue* queue, void (*func_ptr) (Item item))
{
	Node* cursor = queue->front;
	while (cursor != NULL)
	{
		(*func_ptr) (cursor->item);
		cursor = cursor->next;
	}
}

//define clear
void clear (Queue* queue)
{
	Item dummy;
	while (!is_empty(queue))
	{
		dequeue(queue, &dummy);
	}
}