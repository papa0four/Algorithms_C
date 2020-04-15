#ifndef _STACK_H
#define _STACK_H
#include <stdbool.h>

typedef char* stack_node;

typedef struct stack
{
	stack_node* spell_list;
	int capacity;
	int top;
} Stack;

Stack* stack_init(int size);
void stack_destroy(Stack* stack_ptr);
void push(Stack* stack_ptr, stack_node* spell);
stack_node* pop (Stack* stack_ptr, stack_node* spell);
bool is_empty(Stack* stack_ptr);
bool is_full(Stack* stack_ptr);

#endif