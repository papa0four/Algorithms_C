#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	int data;
	struct node* next;
} Node;

typedef struct list
{
	Node* head_node;
	Node* tail_node;
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
	Node* new_head = new_node(data);
	Node* current_head = lHead->head_node;
	Node* current_tail = lHead->tail_node;

	if (!lHead->head_node && !lHead->tail_node)
	{
		lHead->head_node = new_head;
		lHead->tail_node = new_head;
		return true;
	}
	else
	{
		new_head->next = current_head;
		lHead->head_node = new_head;
		current_head = lHead->tail_node;
		current_head->next = new_head;
		return true;
	}

	return false;
}

void print_list (List* lHead)
{
	Node* current = lHead->head_node;
	Node* tail = lHead->tail_node;

	printf("Printing list:\n");
	if (current != NULL)
	{
		printf("Head: Node %d ", current->data);
	}

	current = current->next;

	while (current->next != lHead->head_node && current != lHead->tail_node)
	{
		printf("Node %d ", current->data);
		current = current->next;
	}
	current->next = lHead->head_node;
	printf("Tail: Node %d\n", current->data);
	return;
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
	Node* prev = lHead->tail_node;

	if (lHead->head_node == NULL)
	{
		printf("List is empty\n");
		return NULL;
	}

	//if only 1 node exists in list
	if (temp->next == temp && data == temp->data)
	{
		lHead->head_node = NULL;
		return lHead->head_node;
	}

	//if head node is the one to be deleted
	if (temp->next != NULL && data == temp->data)
	{
		printf("Deleting head node: %d\n", data);
		lHead->head_node = temp->next;
		prev->next = lHead->head_node;
		return temp;
	}

	// while (prev->next != lHead->head_node && data != prev->data)
	// {
	// 	prev = prev->next;
	// }

	// printf("Deleting head node: %d\n", data);
	// prev->next = temp->next;
	// lHead->head_node = prev->next;
	// return temp;
}

Node* remove_tail (List* lHead, int data)
{
	Node* temp = lHead->head_node;
	Node* current = lHead->head_node;
	Node* prev;

	while (current->next != lHead->head_node)
	{
		prev = current;
		current = current->next;
	}

	printf("Deleting tail node: %d\n", data);
	prev->next = lHead->head_node;
	lHead->tail_node = prev;
	return current;
}

Node* remove_node (List* lHead, int data)
{
	Node* temp = lHead->head_node;
	Node* current = temp;
	Node* previous;

	//loop through list to search for selected node and keep track or previous node
	while (temp != NULL && data != temp->data)
	{
		current = temp;
		// previous = temp;
		temp = temp->next;
	}

	if (temp == NULL)
	{
		printf("Node %d does not exist in list\n", data);
		return NULL;
	}

	//remove node from the list
	printf("Deleting node: %d\n", data);
	current->next = temp->next;
	// current->next->next = previous;
	return temp;
}

void destroy_list (List* lHead)
{
	Node* current = lHead->head_node;
	Node* next;

	while (current != lHead->head_node)
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

	while (next->next != lHead->head_node)
	{
		next = next->next;
	}

	printf("Your list is circular...\n");
	return (next->next == current_head);
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
	printf("\n");
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