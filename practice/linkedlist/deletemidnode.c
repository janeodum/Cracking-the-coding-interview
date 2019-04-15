#include <stdio.h>
#include <stdlib.h>


void deletemidnode(node_t * head)
{
	if (head == NULL)
	{
		return;
	}
	if (head->next == NULL)
	{
		free(head);
	}
	//Initialize slow and fast pointers to reach 
    // middle of linked list
	node_t * slow_ptr = head;
	node_t * fast_ptr = head;
	node_t * prev;

	// Find the middle and previous of middle. 

	while (fast_ptr != NULL && fast_ptr->next != NULL)
	{
		fast_ptr = fast_ptr->next->next;
		prev = slow_ptr;
		slow_ptr = slow_ptr->next;
	}
	prev->next = slow_ptr->next;
	free(slow_ptr);
	return;
}

void printlist(node_t * current)
{
	while (current != NULL)
	{
		printf("%s", current->data);
		current = current-> next;
	}
	printf("\n");
}

void push(node_t **head_ref, char * new_data)
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

	push(&head, "e");
	push(&head, "d");
	push(&head, "c");
	push(&head, "b");
	push(&head, "a");

	deletemidnode(head);
	printlist(head);
}