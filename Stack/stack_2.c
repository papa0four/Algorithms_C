#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack_2.h"

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

	stack_ptr->items = calloc(STACK_SZ, sizeof(void*));
	if (!stack_ptr->items)
	{
		free(stack_ptr);
		return NULL;
	}

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

bool push (Stack* stack_ptr, void* item)
{
	if (is_full(stack_ptr) || stack_ptr == NULL)
	{
		return false;
	}

	stack_ptr->top++;
	stack_ptr->items[stack_ptr->top] = item;

	return true;
}

void* peek(Stack* stack_ptr)
{
	return stack_ptr->items[stack_ptr->top];
}

void pop (Stack* stack_ptr)
{
	printf("Item to be popped from top of stack: %ld\n", (long) stack_ptr->items[stack_ptr->top]);

	stack_ptr->items[stack_ptr->top--];
}

void stack_destroy (Stack* stack_ptr)
{
	printf("Destroying stack...\n");
	free(stack_ptr->items);		
	stack_ptr->top = -1;
	stack_ptr->capacity = 0;
	stack_ptr->items = NULL;
}

int main()
{
	Stack* stack_ptr = stack_init(5);

	bool check;

	for (size_t i = 10; i <= 50; i += 10)
	{
		check = push(stack_ptr, (void *) i);
		if (!check)
		{
			printf("Your stack has contracted COVID-19! ERADICATE IMMEDIATELY!!!\n");
		}

		printf("%ld pushed to stack\n", (long) peek(stack_ptr));
	}

	for (size_t i = stack_ptr->top; i > 0; i--)
	{
		pop(stack_ptr);
		printf("New top of stack: %ld\n", (long) peek(stack_ptr));
	}

	stack_destroy(stack_ptr);
	free(stack_ptr);
	
	return 0;
}