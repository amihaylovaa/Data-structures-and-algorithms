#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>

struct stack
{
	int key;
	struct stack* next;
};

typedef struct stack STACK;

void push(STACK**, int);
STACK* peek(STACK*);
bool  is_empty(STACK*);
void traverse(STACK*);
void pop(STACK**);

void stack()
{
	STACK* head = NULL;
	int choice;

	while (1)
	{
		printf("\nStack");
		printf("\n1 -> Push");
		printf("\n2 -> Pekk");
		printf("\n3 -> Check if stack is empty");
		printf("\n4 -> Pop");
		printf("\n5 -> Traverse");
		printf("\n6 -> Exit");
		scanf_s("%d", &choice);

		if (choice == 1)
		{
			int key_value;

			printf("\nEnter key value :");
			scanf_s("%d", &key_value);

			push(&head, key_value);
		}

		else if (choice == 2)
		{
			STACK* top_of_stack = peek(head);

			if (top_of_stack == NULL)
				printf("\nEmpty stack!");
			else
				printf("\nTop of the stack is: %d ", top_of_stack->key);
		}

		else if (choice == 3)
		{
			bool is_stack_empty = is_empty(head);

			if (is_stack_empty == true)
				printf("\nEmpty stack!");
			else
				printf("\nStack is not empty!");
		}

		else if (choice == 4)
		{
			if (head == NULL)
				printf("\nEmpty stack!");
			else
				pop(&head);
		}
		else if (choice == 5)
			traverse_queue(head);

		else
			return;

	}
}

void push(STACK** head, int key_value)
{
	STACK* new_node;
	new_node = (STACK*)malloc(sizeof(STACK));
	new_node->key = key_value;
	new_node->next = NULL;

	if (*head == NULL)
		* head = new_node;
	else
	{
		new_node->next = *head;
		*head = new_node;
	}
}

STACK* peek(STACK* head)
{
	if (head == NULL)
		return NULL;
	return head;
}

bool is_empty(STACK* h)
{
	return (h == NULL) ? true : false;
}

void pop(STACK** head)
{
	STACK* stack_ptr = *head;

	*head = (*head)->next;

	free(stack_ptr);
}

void traverse(STACK* head)
{
	STACK* node_ptr;

	for (node_ptr = head; node_ptr != NULL; node_ptr = node_ptr->next)
		printf("\n%d", node_ptr->key);
}