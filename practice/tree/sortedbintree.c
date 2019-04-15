#include <stdlib.h>
#include <stdio.h>

struct node
{
	int data;
	struct node * left;
	struct node * right;
};
struct node * newNode(int data);
struct node * sortbinarytree(int arr[], int start, int end)
{
	if (start > end)
	{
		return NULL;
	}
	int mid = (start + end)/2;
	struct node * root = newNode(arr[mid]);
	root->left = sortbinarytree(arr, start, mid-1);
	root->right = sortbinarytree(arr, mid+1, end);

	return root;
}

struct node * newNode(int data)
{
	struct node * newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return (newnode);
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
    int arr[] = {1, 2, 3, 4, 5, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    /* Convert List to BST */
    struct node *root = sortbinarytree(arr, 0, n-1); 
    printf("n PreOrder Traversal of constructed BST "); 
    printpreorder(root); 
    printf("\n");
  
    return 0; 
} 