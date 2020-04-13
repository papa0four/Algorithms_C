#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	int data;
	struct node* prev;
	struct node* next;
} Node;

typedef struct list
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

bool push (List* lHead, int data)
{
	Node* current_head = (Node *)malloc(sizeof(Node));
	if (current_head == NULL)
	{
		perror("Could not allocate memory for current_head in push");
		exit(EXIT_FAILURE);
	}

	Node* new_head = new_node(data);

	if (lHead->head_node == NULL)
	{
		current_head = new_head;
		lHead->head_node = current_head;
		return true;
	}
	else
	{
		current_head = lHead->head_node;
		new_head->next = current_head;
		lHead->head_node = new_head;
		return true;
	}

	return false;
}

void print_list (List* lHead)
{
	Node* current = lHead->head_node;

	printf("Printing list:\n");
	if (current != NULL)
	{
		printf("Head: Node %d ", current->data);
	}

	current = current->next;

	while (current->next != lHead->head_node)
	{
		printf("Node %d ", current->data);
		current = current->next;
		if (current->next == NULL)
		{
			printf("Tail: Node %d\n", current->data);
			current->next = lHead->head_node;
			return;
		}
	}
}

bool search (List* lHead, int data)
{
	Node* current = lHead->head_node;

	while (current->next != lHead->head_node)
	{
		if (data == current->data)
		{
			printf("Node %d found!\n", data);
			return true;
		}

		current = current->next;
	}
	current->next = lHead->head_node;

	if (current->next == lHead->head_node && data != current->data)
	{
		printf("Node %d does not exist in list\n", data);
		return false;
	}
}

Node* remove_head (List* lHead, int data)
{
	Node* temp = lHead->head_node;
	Node* prev = lHead->head_node;

	if (temp == NULL)
	{
		printf("List is empty\n");
		return NULL;
	}

	//if only 1 node exists in list
	if (prev->next == prev && data == prev->data)
	{
		lHead->head_node = NULL;
		return lHead->head_node;
	}

	while (prev->next != lHead->head_node && data != prev->data)
	{
		prev = prev->next;
	}

	printf("Deleting head node: %d\n", data);
	prev->next = temp->next;
	lHead->head_node = prev->next;
	return temp;
}

Node* remove_tail (List* lHead, int data)
{
	Node* temp = lHead->head_node;
	Node* current = lHead->head_node;
	Node* prev;

	if (lHead->head_node == NULL)
	{
		printf("List is empty\n");
		return NULL;
	}

	//if only 1 node exists in list
	if (current->next == current && data == current->data)
	{
		lHead->head_node = NULL;
		return lHead->head_node;
	}

	while (current->next != lHead->head_node && data != current->data)
	{
		prev = current;
		current = current->next;
	}

	printf("Deleting tail node: %d\n", data);
	prev->next = current->next;
	lHead->head_node = prev->next;
	return current;
}

Node* remove_node (List* lHead, int data)
{
	Node* head = lHead->head_node;
	if (head == NULL)
	{
		printf("List is empty\n");
		return NULL;
	}

	Node* current = head;
	Node* prev;

	while (data != current->data)
	{
		if (current->next == head)
		{
			printf("Node %d does not exist in list\n", data);
		}
		break;
	}

	prev = current;
	current = current->next;

	if (current->next == head)
	{
		head = NULL;
		return current;
	}

	if (current != head && current->next != head)
	{
		printf("Deleting node: %d\n", data);
		prev->next = current->next;
		return current;
	}
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

bool is_circular (List* lHead)
{
	Node* current_head = lHead->head_node;
	if (current_head == NULL)
	{
		printf("Technically empty lists are circular...\n");
		return true;
	}

	Node* next = current_head->next;

	while (next != NULL && next != current_head)
	{
		next = next->next;
	}

	printf("Your list is circular...\n");
	return (next == current_head);
}

int main ()
{
	List* link_list = list_init();

	Node* node;

	bool check;

	for (int i = 100; i >= 10; i -= 10)
	{
		check = push(link_list, i);

		if (!check)
		{
			printf("LIST HAS CONTRACTED COVID19, PLEASE PERFORM ERADICATION PROCEDURES!\n");
		}
	}

	print_list(link_list);
	check = is_circular(link_list);
	if (!check)
	{
		printf("LIST HAS CONTRACTED COVID19, PLEASE PERFORM ERADICATION PROCEDURES!\n");
	}

	search(link_list, 10);
	search(link_list, 40);
	search(link_list, 250);
	search(link_list, 70);
	search(link_list, 100);

	node = remove_node(link_list, 80);
	free(node);
	printf("\n");
	print_list(link_list);
	printf("\n");
	node = remove_node(link_list, 50);
	free(node);
	printf("\n");
	print_list(link_list);
	printf("\n");
	search(link_list, 50);
	node = remove_tail(link_list, 100);
	free(node);
	printf("\n");
	print_list(link_list);
	node = remove_head(link_list, 10);
	free(node);
	printf("\n");
	search(link_list, 10);
	printf("\n");
	print_list(link_list);
	check = is_circular(link_list);
	if (!check)
	{
		printf("LIST HAS CONTRACTED COVID19, PLEASE PERFORM ERADICATION PROCEDURES!\n");
	}
	printf("\n");

	destroy_list(link_list);

	return 0;
}