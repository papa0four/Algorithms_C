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

Node* insert (Tree* tree, int data)
{
	Node* temp = (Node *)malloc(sizeof(Node));
	if (temp == NULL)
	{
		perror("Could not allocate memory for temp in insert");
		exit(EXIT_FAILURE);
	}

	temp = tree->root;

	if (tree->root == NULL)
	{
		tree->root = new_node(data);
		return tree->root;
	}

	while (true)
	{
		if (data > temp->data)
		{
			if (temp->right == NULL)
			{
				temp->right = new_node(data);
				break;
			}
			else
			{
				temp = temp->right;
			}
		}
		else
		{
			if (temp->left == NULL)
			{
				temp->left = new_node(data);
				break;
			}
			else
			{
				temp = temp->left;
			}
		}
	}
	return tree->root;
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

void in_order(Tree* tree)
{
	Node* current = (Node *)malloc(sizeof(Node));
	if (current == NULL)
	{
		perror("Could not allocate memory for current in in_order");
		exit(EXIT_FAILURE);
	}

	Node* prev = (Node *)malloc(sizeof(Node));
	if (prev == NULL)
	{
		perror("Could not allocate memory for prev in in_order");
		exit(EXIT_FAILURE);
	}

	if (tree->root == NULL)
	{
		return;
	}

	current = tree->root;
	while (current != NULL)
	{
		if (current->left == NULL)
		{
			printf("%d ", current->data);
			current = current->right;
		}
		else
		{
			prev = current->left;

			while (prev->right != NULL && prev->right != current)
			{
				prev = prev->right;
			}

			if (prev->right = NULL)
			{
				prev->right = current;
				current = current->left;
			}
			else
			{
				prev->right = NULL;
				printf("%d ", current->data);
				current = current->right;
			}
		}
	}
}

Node* max_value (Node* node)
{
	while (node->right != NULL)
	{
		node = node->right;
	}

	return node;
}

void delete (Tree* tree, int data)
{
	Node* current = (Node *)malloc(sizeof(Node));
	if (current == NULL)
	{
		perror("Could not allocate memory for current in delete");
		exit(EXIT_FAILURE);
	}

	Node* parent = (Node *)malloc(sizeof(Node));
	if (parent == NULL)
	{
		perror("Could not allocate memory for parent in delete");
		exit(EXIT_FAILURE);
	}

	current = tree->root;
	parent = search(tree, current->data);

	if (current == NULL)
	{
		return;
	}

	if (current->left == NULL && current->right == NULL)
	{
		if (current != tree->root)
		{
			if (parent->left == current)
			{
				parent->left = NULL;
			}
			else
			{
				parent->right = NULL;
			}
		}
		else
		{
			tree->root = NULL;
			free(current);
		}
	}
	else if (current->left && current->right)
	{
		Node* child = min_value
	}
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

	printf("Printing current tree:\n");
	insert(tree, 10);
	// new_node(20);
	insert(tree, 20);
	insert(tree, 30);
	insert(tree, 50);
	insert(tree, 70);
	insert(tree, 80);
	in_order(tree);

	printf("\nSearching for existing value: 30\n");
	if (search(tree, 30))
	{
		printf("Node found!\n");
	}
	else
	{
		printf("Node provided does not exist!\n");
	}

	printf("Deleting 10\n");
	delete(tree, 10);
	// delete(tree, 20);
	// delete(tree, 30);
	// delete(tree, 50);
	// delete(tree, 70);
	// delete(tree, 80);

	printf("Printing newly modified tree:\n");
	in_order(tree);

	printf("\n");

	free(tree);

	return 0;

}