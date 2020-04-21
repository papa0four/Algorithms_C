#ifndef _STACK_H
#define _STACK_H
#include <stdbool.h>

#define STACK_SZ 5

typedef struct stack_data
{
	int top;
	int capacity;
	void** items;
} Stack;

Stack* stack_init();
void stack_destroy(Stack* stack_ptr);
bool push(Stack* stack_ptr, void* item);
void* peek(Stack* stack_ptr);
int pop (Stack* stack_ptr);
bool is_empty(Stack* stack_ptr);
bool is_full(Stack* stack_ptr);

#endif