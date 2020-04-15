#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

#define SPELL_NAME_SZ 15

Stack* stack_init (int size)
{
	Stack* stack_ptr = (Stack *)malloc(sizeof(Stack));
	if (stack_ptr == NULL)
	{
		perror("Could not allocate memory for sstack_ptr in stack_init");
		exit(EXIT_FAILURE);
	}
	stack_node* new_spell = (stack_node *)malloc(sizeof(stack_node) * size);
	if (new_spell == NULL)
	{
		perror("Could not allocate memory for new_spell in stack_init");
		exit(EXIT_FAILURE);
	}

	stack_ptr->spell_list = new_spell;
	stack_ptr->capacity = size;
	stack_ptr->top = -1;
}

void stack_destroy (Stack* stack_ptr)
{
	free(stack_ptr->spell_list);
	stack_ptr->spell_list = NULL;
	stack_ptr->capacity = 0;
	stack_ptr->top = -1;
	free(stack_ptr);
}

void push (Stack* stack_ptr, stack_node* spell)
{
	if (is_full(stack_ptr))
	{
		perror("StackOverflow");
		exit(EXIT_FAILURE);
	}

	stack_ptr->spell_list[++stack_ptr->top] = *spell;

	// for (size_t i = 0; i < strlen(*stack_ptr->spell_list); i++)
	// {
	// 	for (size_t j = 0; j < strlen(*spell); j++)
	// 	{
	// 		stack_ptr->spell_list[++stack_ptr->top] = spell[j];
	// 	}
	// }
}

stack_node* pop (Stack* stack_ptr, stack_node* spell)
{
	if (is_empty(stack_ptr))
	{
		perror("StackUnderflow");
		exit(EXIT_FAILURE);
	}
	// for (size_t i = 0; i < strlen(*spell); i++)
	// {
	// 	stack_ptr->spell_list[stack_ptr->top] = spell[i];
	// }
	//stack_ptr->spell_list[stack_ptr->top] = *spell;
	return &stack_ptr->spell_list[stack_ptr->top--];
}

bool is_empty (Stack* stack_ptr)
{
	if (stack_ptr->top <= 0)
	{
		return true;
	}
	return false;
}

bool is_full (Stack* stack_ptr)
{
	if (stack_ptr->top >= stack_ptr->capacity - 1)
	{
		return true;
	}

	return false;
}

char* get_spell ()
{
	char* spell_name = (char *)calloc(SPELL_NAME_SZ, sizeof(char));
	if (spell_name == NULL)
	{
		perror("Could not allocate memory for spell_name in get_spell");
		exit(EXIT_FAILURE);
	}
	printf("Enter the name of your spell:\n");
	fgets(spell_name, SPELL_NAME_SZ, stdin);

	return spell_name;

}

int main (void)
{
	Stack* stack_ptr = stack_init(100);
	char* traverse;

	char* spell = get_spell();

	for (traverse = spell; *traverse != '\0'; traverse++)
	{
		push (stack_ptr, &traverse);
	}

	spell = get_spell();

	for (traverse = spell; *traverse != '\0'; traverse++)
	{
		push (stack_ptr, &traverse);
	}

	spell = get_spell();

	for (traverse = spell; *traverse != '\0'; traverse++)
	{
		push (stack_ptr, &traverse);
	}

	printf("Spell cast Sequence:\n");
	while (!is_empty(stack_ptr))
	{
		printf("%s", *pop(stack_ptr, &spell));
	}

	printf("Destroying stack...\n");
	stack_destroy(stack_ptr);

	return 0;


}