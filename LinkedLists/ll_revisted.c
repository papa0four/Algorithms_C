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
	Node* hNode = (Node *)malloc(sizeof(Node));
	if (hNode == NULL)
	{
		perror("Could node allocate memory for head_node in create_list");
		exit(EXIT_FAILURE);
	}

	if (lHead->head_node == NULL)
	{
		lHead->head_node = new_node(data);
		return true;
	}

	Node* current = (Node *)malloc(sizeof(Node));
	if (current == NULL)
	{
		perror("Could not allocate memory for current in create_list");
		exit(EXIT_FAILURE);
	}

	current = lHead->head_node;

	while (current != NULL)
	{
		Node* new = new_node(data);
		current->next = new;
		return true;
	}

	return false;
}

int main ()
{
	List* link_list = (List *)malloc(sizeof(List));
	if (link_list == NULL)
	{
		perror("Could not allocate memory for link_list in main");
		exit(EXIT_FAILURE);
	}

	Node* list_node = (Node *)malloc(sizeof(Node));
	if (list_node == NULL)
	{
		perror("Could not allocate memory for list_node in main");
		exit(EXIT_FAILURE);
	}

	link_list = list_init();
	//list_node = link_list->head_node;
	//printf("Head node in main points to: %p\n", link_list->head_node);
	bool check;

	for (int i = 10; i <= 50; i += 10)
	{
		check = append(link_list, i);
		list_node->data = i;
		if (!check)
		{
			printf("LIST HAS CONTRACTED COVID19, ERADICATE IMMEDIATELY!\n");
		}
		else if (list_node->data <= 40)
		{
			printf("Node %d->", list_node->data);
		}
		else if(list_node->data == 50 && list_node->next == NULL)
		{
			printf("Node %d->NULL\n", list_node->data);
		}
	}

	return 0;
}