#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int key;
	struct node* left;
	struct node* right;
} Node;

Node* new_node (int item)
{
	Node* temp = (Node *) malloc(sizeof(Node));
	temp->key = item;
	temp->left = temp->right = NULL;

	return temp;
}

Node* search (Node* root,int key)
{
	//Base Cases: root is null or key is present at root
	if (root == NULL || root->key == key)
	{
		return root;
	}

	//Key is greater than root's key
	if (root->key < key)
	{
		return search(root->right, key);
	}

	//Key is smaller than root's key
	return search(root->left, key);
}

//utility function to inorder traversal
void in_order (Node* root)
{
	if (root != NULL)
	{
		in_order(root->left);
		printf("%d ", root->key);
		in_order(root->right);
	}
}

//utility function to insert node passed by key
Node* insert (Node* node, int key)
{
	//check if tree is empty, thus create a new node
	if (node == NULL)
	{
		return new_node(key);
	}

	//recursive search down the tree and insert in appropriate location
	if (key < node->key)
	{
		node->left = insert(node->left, key);
	}
	else if (key > node->key)
	{
		node->right = insert(node->right, key);
	}

	return node;
}

Node* min_value(Node* node)
{
	Node* current = node;

	//loop down to find the leftmost leaf
	while (current && current->left != NULL)
	{
		current = current->left;
	}

	return current;
}

//Delete a node based upon the found key within a tree and returns a new root
Node* delete(Node* root, int key)
{
	//base case
	if (root == NULL)
	{
		return root;
	}

	//if key is smaller than root, node lies within left subtree
	if (key < root->key)
	{
		root->left = delete(root->left, key);
	} //if key is greater than root, node lies within right rubtree
	else if (key > root->key)
	{
		root->right = delete(root->right, key);
	} //if key is same as root, then delete root and set new
	else
	{
		//node with only one child or no children
		if (root->left == NULL)
		{
			Node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			Node* temp = root->left;
			free(root);
			return temp;
		}

		//if node has both children: get inorder successor (smallest) in right subtree
		Node* temp = min_value(root->right);
		root->key = temp->key;
		root->right = delete(root->right, temp->key);
	}

	return root;
}

//main function to drive test cases
int main ()
{
	//create the BST
	Node* root = NULL;
	root = insert(root, 50);

	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	printf("Inorder traversal of original tree:\n");
	in_order(root);

	printf("\nDelete 20\n");
	root = delete(root, 20);
	printf("Inorder traversal of newly modified tree:\n");
	in_order(root);

	printf("\nDelete 30\n");
	root = delete(root, 30);
	printf("Inorder traversal of newly modified tree:\n");
	in_order(root);

	printf("\nDelete 50\n");
	root = delete(root, 50);
	printf("Inorder traversal of newly modified tree:\n");
	in_order(root);

	insert(root, 10);
	printf("\nInorder traversal with new root:\n");
	in_order(root);

	printf("\nDelete 10\n");
	root = delete(root, 10);
	printf("Inorder traversal of tree with deleted 10 root:\n");
	in_order(root);

	insert(root, 100);
	printf("\nInorder traversal of newly modified tree:\n");
	in_order(root);

	printf("\n");

	return 0;
}