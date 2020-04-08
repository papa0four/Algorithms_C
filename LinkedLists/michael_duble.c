#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	int data;
	struct node* prev;
	struct node* next;
} Node;

typedef struct link_list
{
	Node* head_node;
} List;

Node* new_node (int data)
{
	Node* new = (Node *)malloc(sizeof(Node));
	if (new == NULL)
	{
		perror("Could not allocalte memory for new in new_node");
		exit(EXIT_FAILURE);
	}

	new->data = data;
	new->prev = NULL;
	new->next = NULL;

	return new;
}

List* list_init ()
{
	List* lHead = (List *)malloc(sizeof(List));
	if(lHead == NULL)
	{
		perror("Could not allocate memory for lHead in list_init");
		exit(EXIT_FAILURE);
	}

	lHead->head_node = NULL;

	return lHead;
}

bool append (List* lHead,  int data)
{
	Node* hNode = new_node(data);
	if (hNode == NULL)
	{
		perror("Could not create hNode in append");
		exit(EXIT_FAILURE);
	}

	if (lHead->head_node == NULL)
	{
		lHead->head_node = hNode;
		return true;
	}

	Node* current = lHead->head_node;

	while (current->next != NULL)
	{
		current = current->next;
	}

	current->next = hNode;
	hNode->prev = current;

	return true;
}

void print_list (List* lHead)
{
	Node* current = lHead->head_node;
	current->prev = NULL;

	printf("Printing forward traversal:\n");
	while (current->next != NULL)
	{
		printf("Node %d ", current->data);
		current = current->next;
	}
	if (current->next == NULL)
	{
		printf("Node %d\n", current->data);
	}

	printf("\nPrinting reverse traversal:\n");
	while(current->prev != NULL)
	{
		printf("Node %d ", current->data);
		current = current->prev;
	}

	if (current->prev == NULL)
	{
		printf("Node %d\n", current->data);
	}
}

bool search (List* lHead, int data)
{
	Node* current = lHead->head_node;

	while (current->next != NULL)
	{
		if (data == current->data)
		{
			printf("Node %d found!\n", data);
			return true;
		}

		current = current->next;
	}

	//if searched node is tail
	if (data == current->data)
	{
		printf("Node %d found!\n", data);
	}
	else
	{
		printf("Node %d does not exist in list\n", data);
		return false;
	}
}

Node* remove_node (List* lHead, int data)
{
	Node* temp = lHead->head_node;
	Node* previous;

	//if head node is the one to be deleted
	if (temp->next != NULL && data == temp->data)
	{
		printf("Deleting head node: %d\n", data);
		lHead->head_node = temp->next;
		lHead->head_node->prev = NULL;
		return temp;
	}


	//loop through list to search for selected node and keep track or previous node
	while (temp != NULL && data != temp->data)
	{
		temp->prev = previous;
		previous = temp;
		temp = temp->next;		
	}

	if (temp == NULL)
	{
		printf("Node %d does not exist in list\n", data);
		return NULL;
	}

	if (temp->next == NULL && data == temp->data)
	{
		printf("Deleting tail node: %d\n", data);
		previous->next = NULL;
		return temp;
	}

	//remove node from the list
	printf("Deleting node: %d\n", data);
	previous->next = temp->next;
	return temp;
}

void destroy_list (List* lHead)
{
	Node* current = lHead->head_node;
	Node* next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	lHead->head_node = NULL;
	free(lHead);
}

int main ()
{
	List* link_list = list_init();

	Node* node;

	bool check;

	for (int i = 10; i <= 100; i += 10)
	{
		check = append(link_list, i);

		if (!check)
		{
			printf("LIST HAS CONTRACTED COVID19, PLEASE PERFORM ERADICATION PROCEDURES!\n");
		}
	}

	print_list(link_list);

	search(link_list, 10);
	search(link_list, 40);
	search(link_list, 250);
	search(link_list, 70);
	search(link_list, 100);

	node = remove_node(link_list, 80);
	free(node);
	node = remove_node(link_list, 50);
	free(node);
	search(link_list, 50);
	node = remove_node(link_list, 100);
	free(node);
	node = remove_node(link_list, 10);
	free(node);
	search(link_list, 10);
	print_list(link_list);

	printf("Destroying list...\n");
	destroy_list(link_list);

	return 0;
}
