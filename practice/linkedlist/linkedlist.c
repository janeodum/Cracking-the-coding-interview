#include <stdlib.h>
#include <stdio.h>


typedef struct node
{
	int data;
	struct node * next;
} node_t;


void printlist(struct node * current)
{
	while (current != NULL)
	{
		printf("%d", current->data);
		current = current->next;
	}
	printf("\n");
}

void push(node_t ** head_ref, int new_data)
{
	node_t * new_node;
	new_node = malloc(sizeof(node_t));

	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;

}

void insertafter(node_t * prev_node, int new_data)
{
	node_t * new_node;
	if (prev_node == NULL)
	{
		return;
	}

	new_node = malloc(sizeof(node_t));

	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

// void append(node_t *last_node, int new_data)
// {
// 	if(last_node == NULL)
// 	{
// 		node_t * new_node;
// 		new_node = malloc(sizeof(node_t));
// 		new_node->data = new_data;
// 		ne
// 	}
// }

// void append(struct Node** head_ref, int new_data) 
// { 
//     /* 1. allocate node */
//     struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
  
//     struct Node *last = *head_ref;  /* used in step 5*/
   
//     /* 2. put in the data  */
//     new_node->data  = new_data; 
  
//     /* 3. This new node is going to be the last node, so make next  
//           of it as NULL*/
//     new_node->next = NULL; 
  
//     /* 4. If the Linked List is empty, then make the new node as head */
//     if (*head_ref == NULL) 
//     { 
//        *head_ref = new_node; 
//        return; 
//     }   
       
//     /* 5. Else traverse till the last node */
//     while (last->next != NULL) 
//         last = last->next; 
   
//     /* 6. Change the next of last node */
//     last->next = new_node; 
//     return;     
// } 

void deleteNode(node_t ** head_ref, int key)
{
	node_t * temp = *head_ref, *prev;

	if (temp != NULL && temp->data == key)
	{
		*head_ref = temp-> next;
		free(temp);
		return;
	}

	while (temp != NULL && temp->data != key)
	{
		prev = temp;
		temp = temp->next;

	}
	if (temp == NULL)
	{
		return;
	}
	prev->next = temp->next;
	free(temp);
}
int main() 
{ 
    /* Start with the empty list */
    node_t * head = NULL; 
  
    push(&head, 7); 
    push(&head, 1); 
    push(&head, 3); 
    push(&head, 2); 
  
    printlist(head); 
    deleteNode(&head, 1); 
    printlist(head); 
    return 0; 
}
// int main()
// {
// 	node_t * head = NULL;
// 	node_t * second = NULL;
// 	node_t * third = NULL;

// 	head = malloc(sizeof(node_t));
// 	second = malloc(sizeof(node_t));
// 	third = malloc(sizeof(node_t));


// 	head->data = 1;
// 	head->next  = second;

// 	second->data = 2;
// 	second->next = third;

// 	third->data = 3;
// 	third->next = NULL;

// 	printlist(head);
// 	return 0;
// }