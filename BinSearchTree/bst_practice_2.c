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

Node* min_value (Node* node)
{
	Node* current = node;

	while(current && current->left != NULL)
	{
		current = current->left;
	}

	return current;
}

Node* delete (Node* node, int data)
{
	if (node == NULL)
	{
		return node;
	}

	if (data < node->data)
	{
		node->left = delete(node->left, data);
	}
	else if (data > node->data)
	{
		node->right = delete(node->right, data);
	}
	else
	{
		if (node->left == NULL)
		{
			Node* temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right == NULL)
		{
			Node* temp = node->left;
			free(node);
			return temp;
		}

		Node* temp = min_value(node->right);
		node->data = temp->data;
		node->right = delete(node->right, temp->data);
	}

	return node;
}

int main ()
{
	Tree* tree = NULL;
	tree = (Tree *)malloc(sizeof(Tree));
	if (tree == NULL)
	{
		perror("Could not allocate memory for tree in main");
		exit(EXIT_FAILURE);
	}

	Node* node = NULL;
	node = (Node *)malloc(sizeof(Node));
	if (node == NULL)
	{
		perror("Could not allocate memory for node in main");
		exit(EXIT_FAILURE);
	}

	Node* new = NULL;
	new = (Node *)malloc(sizeof(Node));
	if (new == NULL)
	{
		perror("Could not allocate memory for new in main");
		exit(EXIT_FAILURE);
	}

	tree->root = insert(tree, 10);
	node = tree->root;
	insert(tree, 20);
	insert(tree, 30);
	insert(tree, 50);
	insert(tree, 70);
	insert(tree, 80);

	printf("Printing current tree:\n");
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



	printf("\nDeleting 20\n");
	tree->root = delete(node, 20);
	printf("Printing newly modified tree\n");
	in_order(tree);

	printf("\nDeleting 30\n");
	tree->root = delete(node, 30);
	printf("\nPrinting newly modified tree\n");
	in_order(tree);

	printf("\nDeleting 50\n");
	tree->root = delete(node, 50);
	printf("\nPrinting newly modified tree\n");
	in_order(tree);
	printf("\n");

	printf("\nDeleting 10\n");
	tree->root = delete(node, 10);
	printf("Printing newly modified tree\n");
	in_order(tree);
	printf("\n");

	new = new_node(40);
	printf("\nInserting new node: 40\n");
	insert(tree, new->data);

	printf("Printing newly modified tree\n");
	in_order(tree);
	printf("\n");
	
	free(tree);
	free(node);

	return 0;

}