#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node * next;
}node_t;

node_t * newNode(int data)
{
	node_t * newnode = malloc(sizeof(node_t));
	newnode->data = data;
	newnode->next = NULL;
	return(newnode);
}

node_t * addlist(node_t * first, node_t * second)
{
	node_t * res = NULL;
	node_t * temp, *prev = NULL;
	int carry = 0;
	int sum;
	while (first != NULL && second != NULL)
	{
		sum = carry + (first? first->data : 0) + (second ? second->data : 0);

		carry = (sum >= 10) ? 1 : 0;
		sum = sum % 10;

		temp = newNode(sum);
		if (res == NULL)
		{
			res = temp;
		}
		else
		{
			prev->next = temp;
		}
		prev = temp;

		if (first) first = first->next;
		if (second) second = second->next;
	}
	if (carry > 0)
	{
		temp->next = newNode(carry);
	}
	return (res);
}

void printlist(struct node * current)
{
	while (current != NULL)
	{
		printf("%d", current->data);
		current = current->next;
	}
	printf("\n");
}
void push(node_t **head_ref, int new_data)
{
	node_t * new_node;
	new_node = malloc(sizeof(node_t));

	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}
int main()
{
	node_t * res = NULL;
	node_t * first = NULL;
	node_t * second = NULL;

	push(&first, 5);
	push(&first, 1);
	push(&first, 3);

	push(&second, 2);
	push(&second, 9);
	push(&second, 5);

	res = addlist(first, second);
	printlist(res);
}