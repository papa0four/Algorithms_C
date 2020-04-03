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

	bool check;

	for (int i = 10; i <= 50; i += 10)
	{
		check = append(link_list, i);

		if (!check)
		{
			printf("LIST NODE HAS CONTRACTED COVID19, ERADICATE IMMEDIATELY!\n");
		}
	}

	print_list(link_list);
	printf("Deleting tree:\n");
	destroy_list(link_list);

	return 0;
}