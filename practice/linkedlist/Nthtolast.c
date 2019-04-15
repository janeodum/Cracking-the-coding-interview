#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node * next;
}node_t;

void printnthtolast(node_t * head, int n)
{
	int len = 0, i;

	node_t * temp = head;
	while (temp != NULL)
	{
		temp = temp->next;
		len++;
	}
	if (len < n)
	{
		return;
	}
	temp = head;
	for (i = 1; i < len-n+1; i++)
	{
		temp = temp->next;
	}
	printf("%d\n", temp->data);
	return;
}

void push(node_t **head_ref, int new_data)
{
	node_t * new_node;
	new_node = malloc(sizeof(node_t));

	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

int main ()
{
	node_t * head = NULL;

	push (&head, 20);
	push (&head, 4);
	push (&head, 15);
	push (&head, 35);

	printnthtolast(head, 4);

}