#include <stdlib.h>
#include <stdio.h>

struct node
{
	int data;
	struct node * left;
	struct node * right;
};

struct node * newNode(int data)
{
	struct node  * newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;

	return (newnode);
}

void printpostorder(struct node * node)
{
	if (node == NULL)
	{
		return;
	}

	printpostorder(node->left);
	printpostorder(node->right);
	printf("%d", node->data );
}

void printinorder(struct node * node)
{
	if (node == NULL)
	{
		return;
	}
	printinorder(node->left);
	printf("%d", node->data);
	printinorder(node->right);
}

void printpreorder(struct node * node)
{
	if (node == NULL)
	{
		return;
	}
	printf("%d",node->data);
	printpreorder(node->left);
	printpreorder(node->right);
}

int main()
{
	struct node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->right->right = newNode(5);

	printinorder(root);
	printf("\n");
	printpreorder(root);
	printf("\n");
	printpostorder(root);
	printf("\n");
}





