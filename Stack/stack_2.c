#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack_2.h"

int* array;

Stack* stack_init (int size)
{
	if (size < 0)
	{
		return NULL;
	}

	Stack* stack_ptr = calloc(1, sizeof(*stack_ptr));
	if (stack_ptr == NULL)
	{
		perror("Could not allocate memory for stack_ptr in stack_init");
		exit(EXIT_FAILURE);
	}

	stack_ptr->capacity = size;
	stack_ptr->top = -1;

	stack_ptr->items = calloc(stack_ptr->capacity, sizeof(int));
	if (!stack_ptr->items)
	{
		free(stack_ptr);
		free(array);
		return NULL;
	}

	// array = calloc(stack_ptr->capacity, sizeof(int));
	// if (!array)
	// {
	// 	free(stack_ptr);
	// 	free(array);
	// 	return NULL;
	// }
	array = (int *)stack_ptr->items;

	return stack_ptr;
}

bool is_empty (Stack* stack_ptr)
{
	if (stack_ptr->top < 0)
	{
		return true;
	}

	return false;
}

bool is_full (Stack* stack_ptr)
{
	if (stack_ptr->top >= stack_ptr->capacity - 1)
	{
		printf("StackOverflow\n");
		return true;
	}
	
	return false;
}

bool push (Stack* stack_ptr, int item)
{
	if (is_full(stack_ptr) || stack_ptr == NULL)
	{
		return false;
	}

	array = (int *)stack_ptr->items;
	stack_ptr->top++;
	array[stack_ptr->top] = item;
	printf("Node %d pushed to stack\n", item);

	return true;
}

void stack_destroy (Stack* stack_ptr)
{
	printf("Destroying stack...\n");
	
	free(array);
			
	stack_ptr->top = -1;
	stack_ptr->capacity = 0;
	array = NULL;
	stack_ptr->items = NULL;
}

int main()
{
	Stack* stack_ptr = stack_init(5);

	bool check;

	for (int i = 50; i >= 10; i -= 10)
	{
		check = push(stack_ptr, i);
		if (!check)
		{
			printf("Your stack has contracted COVID-19! ERADICATE IMMEDIATELY!!!\n");
		}
	}

	stack_destroy(stack_ptr);
	free(stack_ptr);
	
	return 0;
}