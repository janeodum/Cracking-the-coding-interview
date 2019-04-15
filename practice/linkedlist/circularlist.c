#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char * data;
	struct node * next;
}node_t;

node_t * circular(node_t * head, node_t *n1, node_t *n2)
{
	n1 = head;
	n2 = head;

	while (n2->next != NULL)
	{
		n1 = n1->next;
		n2 = n2->next->next;
		if (n1 == n2)
		{
			break;
		}
	}
	if (n2->next == NULL)
	{
		return NULL;
	}
	n1 = head;
	while (n1 != n2)
	{
		n1 = n1->next;
		n2 = n2->next;
	}
	return n2;

}

void printlist(struct node * current)
{
	node_t * temp = current;
	if (current != NULL)
	{
		do
		{
			printf("%s", current->data);
			current = current->next;
		}
		while(temp != current);
		printf("\n");
	}
}

void push(node_t **head_ref, char *data) 
{ 
    node_t *ptr1 = malloc(sizeof(node_t)); 
   	node_t *temp = *head_ref; 
    ptr1->data = data; 
    ptr1->next = *head_ref; 
  
    /* If linked list is not NULL then set the next of last node */
    if (*head_ref != NULL) 
    { 
        while (temp->next != *head_ref) 
            temp = temp->next; 
        temp->next = ptr1; 
    } 
    else
        ptr1->next = ptr1; /*For the first node */
  
    *head_ref = ptr1; 
} 
int main ()
{
	node_t * head = NULL;
	node_t * n1 = head;
	node_t * n2 = head;
	push(&head, "C");
	push(&head, "E");
	push(&head, "D");
	push(&head, "C");
	push(&head, "B");
	push(&head, "A");
	printlist(head);
	node_t * result = circular(head, n1, n2);
	if(result)
	{
		printf("%s\n",(result->data));
	}


}