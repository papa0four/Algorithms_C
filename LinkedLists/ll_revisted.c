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
        perror("Could node allocate memory for head_node in create_list");
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

void
print_list(List *link_list)
{
    if (!link_list)
    {
        printf("not a list here\n");
        return;
    }
    Node *curr;
    curr = link_list->head_node;
    while(curr)
    {
        printf("Data in node: %d\n", curr->data);
        curr = curr->next;
    }
    return;
}

int main ()
{
    
    // creation of list has malloc in the function
    List* link_list = list_init();

    bool check;

    for (int i = 10; i <= 50; i += 10)
    {
        // uses the append function to add to list
        check = append(link_list, i);

        if (!check)
        {
            printf("LIST HAS CONTRACTED COVID19, ERADICATE IMMEDIATELY!\n");
        }
    }

    // here is a different way to check your list
    print_list(link_list);

    return 0;
}
