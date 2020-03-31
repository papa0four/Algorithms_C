#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
} Node;

typedef struct tree
{
	Node* root;
} Tree;

typedef struct stack_node
{
	Node* tree_node;
	struct stack_node* next;
} Stack;

Node* new_node (int data)
{
	Node* new = (Node *)malloc(sizeof(Node));
	if (new == NULL)
	{
		perror("Could not allocate memory for new in new_node");
		exit(EXIT_FAILURE);
	}

	new->data = data;
	new->left = new->right = NULL;

	return new;
}

 bool search (Tree* tree, int data)
{
	Node* current = tree->root;

	while (current != NULL)
	{
		if (data > current->data)
		{
			current = current->right;
		}
		else if (data < current->data)
		{
			current = current->left;
		}
		else
		{
			return true;
		}
	}
	return false;
}


void push (Stack** t_of_stack, Node* node)
{
	Stack* new_node = (Stack *)malloc(sizeof(Stack));
	if (new_node == NULL)
	{
		fprintf(stderr, "Could not allocate memory for new_node in push function");
		exit(2);
	}

	new_node->tree_node = node;
	new_node->next = (*t_of_stack);
	(*t_of_stack) = new_node;
}

bool is_empty (Stack* top)
{
	if (top == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Node* pop (Stack** t_of_stack)
{
	Node* reset;
	Stack* top;

	if (is_empty(*t_of_stack))
	{
		fprintf(stderr, "stack reference pointer is NULL");
		exit(3);
	}
	else
	{
		top = *t_of_stack;
		reset = top->tree_node;
		*t_of_stack = top->next;
		free(top);

		return reset;
	}
}

void in_order (Tree* tree)
{
	Node* current = tree->root;
	Stack* stack = NULL;
	bool done = false;

	while (!done)
	{
		if (current != NULL)
		{
			push(&stack, current);
			current = current->left;
		}
		else
		{
			if (!is_empty(stack))
			{
				current = pop(&stack);
				printf("%d ", current->data);
				current = current->right;
			}
			else
			{
				done = true;
			}
		}
	}
}

 Node* insert (Tree* tree, int data)
{
	Node* current = tree->root;
	Node* parent = (Node *)malloc(sizeof(Node));

	if (current == NULL)
	{
		current = new_node(data);
		return current;
	}

	while (current != NULL)
	{
		parent = current;

		if (data < current->data)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}

		return current;
	}

	if (data < parent->data)
	{
		parent->left = new_node(data);
	}
	else
	{
		parent->right = new_node(data);
	}
	return parent;
}

// Node* min_value (Node* node)
// {
// 	Node* current = node;
// 	while (current && current->left != NULL)
// 	{
// 		current = current->left;
// 	}

// 	return current;
// }

Node* delete (Tree* tree, int data)
{
	Node* current = tree->root;
	Node* target = NULL;
	Node* parent = NULL;

	if (current == NULL)
	{
		return current;
	}

	while (true)
	{
		if (current->data == data)
		{
			target = current;
		}

		if (data < current->data)
		{
			if (current->left == NULL)
			{
				break;
			}
			parent = current;
			current = current->left;
		}
		else
		{
			if (current->right == NULL)
			{
				break;
			}
			parent = current;
			current = current->right;
		}
	}

	if (target == NULL)
	{
		return target;
	}
	else
	{
		if (parent == NULL)
		{
			free(current);
			tree->root = NULL;
		}
		else
		{
			target->data = current->data;

			if (parent->left == current)
			{
				parent->left = current->right;
			}
			else
			{
				parent->right = current->left;
				free(current);
			}
		}
	}
	return target;
}

int main ()
{
	Tree* tree = NULL;
	tree = (Tree *)malloc(sizeof(Tree));
	if (tree == NULL)
	{
		perror("Could not allocate memory for tree in main function");
		exit(EXIT_FAILURE);
	}

	insert(tree, 10);
	new_node(20);
	insert(tree, 20);
	// insert(tree, 30);
	// insert(tree, 50);
	// insert(tree, 70);
	// insert(tree, 80);
	in_order(tree);

	delete(tree, 10);
	free(tree);

	return 0;

}