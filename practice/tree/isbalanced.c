#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	int data;
	struct node * left;
	struct node * right;
};

int height(struct node * node);

bool isBalanced(struct node * root)
{
	int lh;
	int rh;
	if (root == NULL)
	{
		return 1;
	}
	lh = height(root->left);
	rh = height (root->right);

	if (abs(lh-rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
	{
		return 1;
	}
	return 0;
}

int max(int a, int b)
{
	return (a >= b? a : b);
}

int height(struct node * node)
{
	if (node == NULL)
	{
		return 0;
	}
	return 1 + max(height(node->left), height(node->right));
}
struct node * newNode(int data)
{
	struct node * newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return (newnode);
}

int main(void)
{
	struct node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->right->right = newNode(5);
	root->left->left->left = newNode(8);

	if (isBalanced(root))
	{
		printf("tree is balanced");
	}
	else
	{
		printf("tree is not balanced");
	}

}