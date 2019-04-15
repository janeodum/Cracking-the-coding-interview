#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node * next;
}node_t;

void removeduplicate(node_t * start)
{
	node_t *p1, *p2, *dup;
	dup = malloc(sizeof(node_t));
	p1 = start;
	while (p1 != NULL && p1-> next != NULL)
	{
		p2 = p1;
		while (p2-> next !=NULL)
		{
			if (p1->data == p2->next->data)
			{
				dup = p2->next;
				p2->next = p2->next->next;
				free(dup);
			}
			else
			{
				p2 = p2->next;
			}
		}
		p1 = p1->next;
	}
}

void push(node_t **head_ref, int new_data)
{
	node_t * new_node;
	new_node = malloc(sizeof(node_t));

	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
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

int main()
{
	node_t * head = NULL;
	push(&head, 10);
	push(&head, 12);
	push(&head, 11);
	push(&head, 11);
	push(&head, 12);
	push(&head, 11);
	push(&head, 10);

	removeduplicate(head);
	printlist(head);

}