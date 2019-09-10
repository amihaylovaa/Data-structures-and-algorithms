#include <stdio.h>
#include <stdlib.h>

struct data
{
	int value;
	int priority;
};

struct queue
{
	struct data data;
	struct queue* next;
};

void traverse_priority_queue(struct queue**);
void pop_priority_queue(struct queue**);
void push_priority_queue(struct queue**, struct data);

void priority_queue()
{
	struct queue* priority_queue = NULL;
	struct data queue_data;
	int choice = 0;

	while (1)
	{
		printf("\nPriority queue");
		printf("\nPress 1 for push ");
		printf("\nPress 2 for pop ");
		printf("\nPress 3 for print ");
		printf("\nPress 0 for exit ");
		scanf_s("%d", &choice);

		if (choice == 1)
		{
			printf("Enter values :");
			scanf_s("%d", &queue_data.value);
			printf("Enter priority : ");
			scanf_s("%d", &queue_data.priority);
			push_priority_queue(&priority_queue, queue_data);
		}

		else if (choice == 2)
			pop_priority_queue(&priority_queue);

		else if (choice == 3)
			traverse_priority_queue(&priority_queue);

		else
			return;
	}
}

void push_priority_queue(struct queue** head, struct data queue_data)
{
	struct queue* new_node;
	struct queue* curr_node = NULL;
	struct queue* prev_node = NULL;
	int flg = 0;

	new_node = (struct queue*)malloc(sizeof(struct queue));
	new_node->data.value = queue_data.value;
	new_node->data.priority = queue_data.priority;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		(*head)->next = NULL;
	}
	else
	{
		if (new_node->data.priority > (*head)->data.priority)
		{
			curr_node = *head;
			*head = new_node;
			(*head)->next = curr_node;
		}

		else
		{
			for (curr_node = *head; curr_node != NULL && flg == 0; prev_node = curr_node, curr_node = curr_node->next)
			{
				if (new_node->data.priority > curr_node->data.priority)
				{
					flg = 1;
					prev_node->next = new_node;
					new_node->next = curr_node;
				}

				if (curr_node->next == NULL)
				{
					flg = 1;
					curr_node->next = new_node;
					curr_node = new_node;
					new_node->next = NULL;
				}
			}
		}
	}
}

void traverse_priority_queue(struct queue** head)
{
	struct queue* queue_ptr = *head;

	if (queue_ptr == NULL)
		printf("\nPriority tail is empty! ");

	else
	{
		while (queue_ptr != NULL)
		{
			printf("\n");
			printf("\nElement %d has priority %d ", queue_ptr->data.value, queue_ptr->data.priority);
			queue_ptr = queue_ptr->next;
		}
	}
}

void pop_priority_queue(struct queue** head)
{
	int value;
	int priority;
	struct queue* delete_ptr;

	if (*head == NULL)
		printf("\nPriority tail is empty! ");

	else
	{
		delete_ptr = *head;
		value = (*head)->data.value;
		priority = (*head)->data.priority;
		*head = (*head)->next;
		free(delete_ptr);
		printf("\nDeleted node has value %d and priority %d", value, priority);
	}
}