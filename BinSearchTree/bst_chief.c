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

Tree* tree_init ()
{
	Tree* pTree = (Tree *)malloc(sizeof(Tree));
	if (pTree == NULL)
	{
		perror("Could not allocate memory for pTree in tree_init");
		exit(EXIT_FAILURE);
	}

	pTree->root = NULL;

	return pTree;
}

bool insert_node (Tree* pTree, int data)
{
	Node* current = (Node *)malloc(sizeof(Node));
	Node* parent = NULL;
	if (current == NULL)
	{
		perror("Could not allocate memory for current in insert_node");
		exit(EXIT_FAILURE);
	}

	if (pTree->root == NULL)
	{
		pTree->root = new_node(data);
		current = pTree->root;
		return true;
	}

	current = pTree->root;
	while (current != NULL)
	{
		parent = current;

		if (data < current->data)
		{
			current = current->left;
			return true;
		}
		else
		{
			current = current->right;
			return true;
		}
	}

	if (data < parent->data)
	{
		parent->left = new_node(data);
		return true;
	}
	else
	{
		parent->right = new_node(data);
		return true;
	}

	return false;
}

int main ()
{
	Tree* pTree = (Tree *)malloc(sizeof(Tree));
	if (pTree == NULL)
	{
		perror("Could not allocate memory for pTree in main");
		exit(EXIT_FAILURE);
	}

	Node* tNode = (Node *)malloc(sizeof(Node));
	if (tNode == NULL)
	{
		perror("Could not allocate memory for tNode in main");
		exit(EXIT_FAILURE);
	}

	pTree = tree_init();
	bool check;

	for (int i = 0; i < 10; i++)
	{
		check = insert_node(pTree, i);
		if (!check)
		{
			printf("EVERYTHING IS BROKEN COVID19!!!\n");
		}
		else
		{
			printf("Node insertion == TRUE!\n");
		}
	}

	tNode = new_node(50);
	check = insert_node(pTree, tNode->data);
	if (!check)
	{
		printf("STILL COVID THOUGH...\n");
	}
	else
	{
		printf("Insertion of node success!\n");
	}

	return 0;		
}