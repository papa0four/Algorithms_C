#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <string.h>

typedef struct link_node
{
	int data;
	struct link_node* next;
} Node;

typedef struct linked_list
{
	Node* head_node;
} List;

Node* new_node (int data)
{
	Node* new = (Node *)malloc(sizeof(Node));
	if (new == NULL)
	{
		perror("Could not allocate memory for new in new_node");
		exit(EXIT_FAILURE);
	}

	new->data = data;
	new->next = NULL;

	return new;
}

List* list_init ()
{
	List* lHead = (List *)malloc(sizeof(List));
	if (lHead == NULL)
	{
		perror("Could not allocate memory for lHead in list_init");
		exit(EXIT_FAILURE);
	}

	lHead->head_node = NULL;

	return lHead;
}

bool append (List* lHead, int data)
{
	Node* hNode = new_node(data);
	if (hNode == NULL)
	{
		perror("Could not allocate memory for hNode in append");
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
	return true;
}

void print_list (List* link_list)
{
	if (link_list->head_node == NULL)
	{
		printf("No list to print\n");
		return;
	}

	Node* current;
	current = link_list->head_node;

	while (current)
	{
		printf("Data in node: %d\n", current->data);
		current = current->next;
	}

	return;
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

	if (data == current->data)
	{
		printf("Node %d found!\n", data);
		return true;
	}

	printf("Node %d does not exist in list\n", data);
	return false;
}

Node* remove_node (List* lHead, int data)
{
	Node* temp = lHead->head_node;
	Node* previous;

	//if head node is the one to be deleted
	if (temp->next != NULL && data == temp->data)
	{
		printf("Deleting node: %d\n", data);
		lHead->head_node = temp->next;
		// free(temp);
		return temp;
	}

	//loop through list to search for selected node and keep track or previous node
	while (temp != NULL && data != temp->data)
	{
		previous = temp;
		temp = temp->next;
	}

	if (temp == NULL)
	{
		printf("Node %d does not exist in list\n", data);
		// free(temp);
		return NULL;
	}

	//remove node from the list
	printf("Deleting node: %d\n", data);
	previous->next = temp->next;
	// free(temp);
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

	for (int i = 10; i <= 50; i += 10)
	{
		check = append(link_list, i);

		if (!check)
		{
			printf("LIST NODE HAS CONTRACTED COVID19, ERADICATE IMMEDIATELY!\n");
		}
	}

	search(link_list, 40);
	search(link_list, 50);
	search(link_list, 100);

	print_list(link_list);

	node = remove_node(link_list, 10);
	free(node);
	node = remove_node(link_list, 30);
	free(node);
	node = remove_node(link_list, 50);
	free(node);
	node = remove_node(link_list, 80);
	free(node);

	print_list(link_list);

	printf("\nDeleting tree...\n");
	destroy_list(link_list);

	return 0;
}