#ifndef _STACK_H
#define _STACK_H
#include <stdbool.h>

#define SPELL_LIST_SZ 5

typedef char* stack_node;

typedef struct stack
{
	stack_node* spell_list[SPELL_LIST_SZ];
	int capacity;
	int top;
} Stack;

Stack* stack_init(int size);
void stack_destroy(Stack* stack_ptr);
void push(Stack* stack_ptr, stack_node* spell);
Stack* pop (Stack* stack_ptr, stack_node* spell);
bool is_empty(Stack* stack_ptr);
bool is_full(Stack* stack_ptr);

#endif