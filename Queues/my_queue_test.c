#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_queue.h"

//define a display utility function
void display(Item item)
{
	printf("%d ", item.data);
}

//define a check queue utility function
void check_queue (Queue queue)
{
	if (is_empty(&queue))
	{
		printf("No data entered. ");
	}
	else
	{
		printf("Contents of the queue: ");
		traverse(&queue, display);
		printf("\n");
	}
}

//main driver function
int main (void)
{
	Queue queue;
	init(&queue);

	Item temp;

	for (int i = 10; i <= 100; i += 10)
	{
		temp.data = i;
		enqueue(&queue, temp);
	}
	
	printf("current size of the queue: %d\n", queue_length(&queue));
	check_queue(queue);

	printf("dequeue ...\n");
	for (int i = queue.length; i > 1; i--)
	{
		dequeue(&queue, &temp);
		printf("dequeued: %d\n", temp.data);
		check_queue(queue);
		printf("%d\n", i);
	}
	
	printf("Length of queue after dequeue: %d\n", queue.length);
	check_queue(queue);
	clear(&queue);

	return 0;
}