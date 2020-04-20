#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

#define SPELL_NAME_SZ 15

Stack* stack_init (int size)
{
	Stack* stack_ptr = calloc(1, sizeof(Stack));
	if (stack_ptr == NULL)
	{
		perror("Could not allocate memory for sstack_ptr in stack_init");
		exit(EXIT_FAILURE);
	}

	printf("Size of stack at initialization: %ld\n", sizeof(Stack));
	// memset(stack_ptr->spell_list, '\0', SPELL_NAME_SZ);
	// stack_ptr->spell_list = (char **)calloc(SPELL_NAME_SZ, sizeof(char*));
	// if (stack_ptr->spell_list == NULL)
	// {
	// 	perror("Could not allocate memory for spell list in init");
	// 	exit(EXIT_FAILURE);
	// }
	stack_ptr->spell_list[stack_ptr->top] = calloc(SPELL_NAME_SZ, sizeof(int));
	if (stack_ptr->spell_list[stack_ptr->top] == NULL)
	{
		perror("Could not allocate memory for spell list 0 index in init");
		exit(EXIT_FAILURE);
	}
	
	stack_ptr->capacity = size;
	stack_ptr->top = -1;

	return stack_ptr;
}

void stack_destroy (Stack* stack_ptr)
{
	stack_ptr = NULL;
	free(stack_ptr);
}

void push (Stack* stack_ptr, stack_node* spell)
{
	if (is_full(stack_ptr))
	{
		perror("StackOverflow");
		exit(EXIT_FAILURE);
	}

	else if (is_empty(stack_ptr))
	{

		// stack_ptr->spell_list[stack_ptr->top] = 0;
		stack_ptr->spell_list[stack_ptr->top] = spell;
		stack_ptr->spell_list[stack_ptr->top++];
	}
	else
	{
		stack_ptr->spell_list[stack_ptr->top] = spell;
		stack_ptr->spell_list[stack_ptr->top++];
	}
}

Stack* pop (Stack* stack_ptr, stack_node* spell)
{
	if (is_empty(stack_ptr))
	{
		perror("StackUnderflow");
		exit(EXIT_FAILURE);
	}
	else if (is_full(stack_ptr))
	{
		stack_ptr->spell_list[stack_ptr->top] = spell;
		stack_ptr->spell_list[stack_ptr->top--];
	}
	else
	{
		stack_ptr->spell_list[stack_ptr->top] = spell;
		stack_ptr->spell_list[stack_ptr->top--];
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
	if (stack_ptr->top > stack_ptr->capacity - 1)
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
	Stack* stack_ptr = stack_init(SPELL_LIST_SZ);

	char* first_spell = get_spell();
	push(stack_ptr, &first_spell);

	char* second_spell = get_spell();
	push(stack_ptr, &second_spell);

	char* third_spell = get_spell();
	push (stack_ptr, &third_spell);

	char* fourth_spell = get_spell();
	push (stack_ptr, &fourth_spell);

	char* fifth_spell = get_spell();
	push (stack_ptr, &fifth_spell);

	printf("First spell:\n");
	if (!is_empty(stack_ptr))
	{
		pop(stack_ptr, &fifth_spell);
		printf("%s", *stack_ptr->spell_list[stack_ptr->top]);
	}
	printf("Second spell:\n");
	if (!is_empty(stack_ptr))
	{
		pop(stack_ptr, &fourth_spell);
		printf("%s", *stack_ptr->spell_list[stack_ptr->top]);
	}
	printf("Third spell:\n");
	if (!is_empty(stack_ptr))
	{
		pop(stack_ptr, &third_spell);
		printf("%s", *stack_ptr->spell_list[stack_ptr->top]);
	}
	printf("Fourth spell:\n");
	if (!is_empty(stack_ptr))
	{
		pop(stack_ptr, &second_spell);
		printf("%s", *stack_ptr->spell_list[stack_ptr->top]);
	}
	printf("Last spell:\n");
	if (!is_empty(stack_ptr))
	{
		pop(stack_ptr, &first_spell);
		printf("%s", *stack_ptr->spell_list[stack_ptr->top]);
	}

	printf("Destroying stack...\n");
	stack_destroy(stack_ptr);
	// free(first_spell);
	// free(second_spell);
	// free(third_spell);

	return 0;


}