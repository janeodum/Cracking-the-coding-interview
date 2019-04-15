#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node * next;
}node_t;

void deletefirstNode(node_t * key)
{
	node_t * temp;
	if (key->next == NULL || key == NULL)
	{
		free(key);
		return;
	}
	temp = key->next;
	key->data = temp->data;
	key->next = temp->next;
	free(temp);
	return;
}

void printlist(node_t * current)
{
	while (current != NULL)
	{
		printf("%d", current->data);
		current = current-> next;
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
	node_t * head = NULL;

	// push(&head, 1);
	// push(&head, 2);
	// push(&head, 3);
	// push(&head, 4);
	// push(&head, 5);

	node_t * second = NULL;
	node_t * third = NULL;
	node_t * fouth = NULL;
	node_t * fifth = NULL;

	head = malloc(sizeof(node_t));
	second = malloc(sizeof(node_t));
	third = malloc(sizeof(node_t));
	fouth = malloc(sizeof(node_t));
	fifth = malloc(sizeof(node_t));

	head->data = 1;
	head->next  = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = fouth;

	fouth->data = 4;
	fouth->next = fifth;

	fifth->data = 5;
	fifth->next = NULL;
	printlist(head); 
	deletefirstNode(head);
	printlist(head);

}