#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct queue
{
	int data;
	struct queue* next;
};

typedef struct queue QUEUE;

void push_queue(QUEUE**, QUEUE**, int);
void traverse_queue(QUEUE*);
bool is_queue_empty(QUEUE*);
void pop_queue(QUEUE**);

void queue()
{
	QUEUE* head = NULL, * tail = NULL;
	int choice = 0;

	while (1)
	{
		printf("\nQueue");
		printf("\nEnter 1 to push");
		printf("\nEnter 2 to traverse");
		printf("\nEnter 3 to check if queue is empty");
		printf("\nEnter 4 to pop");
		printf("\nEnter 0 for exit");
		scanf_s("%d", &choice);

		if (choice == 1)
		{
			int key_value;

			printf("\nEnter value : ");
			scanf_s("%d", &key_value);

			push_queue(&head, &tail, key_value);
		}

		else if (choice == 2)
			traverse_queue(head);

		else if (choice == 3)
		{
			if (is_queue_empty(head))
				printf("\nEmpty queue!");
			else
				printf("\nQueue is not empty!");
		}

		else if (choice == 4)
			pop_queue(&head);

		else 
			return;
	}
}

void push_queue(QUEUE** head, QUEUE** tail, int value)
{
	QUEUE* new_node;
	new_node = (QUEUE*)malloc(sizeof(QUEUE));
	new_node->data = value;
	new_node->next = NULL;

	if (*head == NULL && *tail == NULL)
		* head = *tail = new_node;
	else
	{
		(*tail)->next = new_node;
		*tail = new_node;
	}
}

void traverse_queue(QUEUE* head)
{
	QUEUE* queue_ptr = head;

	while (queue_ptr != NULL)
	{
		printf("\n%d", queue_ptr->data);
		queue_ptr = queue_ptr->next;
	}
}

bool is_queue_empty(QUEUE* head)
{
	return (head == NULL) ? true : false;
}

void pop_queue(QUEUE** head)
{
	QUEUE* head_ptr;

	if (*head == NULL)
		return;

	head_ptr = *head;
	*head = (*head)->next;
	free(head_ptr);
}