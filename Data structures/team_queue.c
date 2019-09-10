#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
	char name[32];
	int label;
};

struct queue
{
	struct student data;
	struct queue* next;
};

void traverse_team_queue(struct queue**);
void push_team_queue(struct queue**, struct student);
void pop_team_queue(struct queue**);

void team_queue()
{
	struct queue* head = NULL;
	struct student data;
	int choice = 0;

	while (1)
	{
		printf("\nEnter choice !");
		printf("\nPress 1 to push");
		printf("\nPress 2 to pop");
		printf("\nPress 3 to traverse");
		printf("\nPress 4 for exit");
		scanf_s("%d", &choice);


		if (choice == 1)
		{
			printf("Enter student's name : ");
			fgets(data.name, 32, stdin);
			fflush(stdin);
			printf("Enter label :");
			scanf_s("%d", &data.label);

			push_team_queue(&head, data);
		}

		else if (choice == 2)
			pop_team_queue(&head);
		else if (choice == 3)
			traverse_team_queue(&head);
		else
			return 1;
	}
}

void push_team_queue(struct queue** head, struct student student)
{
	struct queue* new_node;
	struct queue* curr_node = NULL;
	struct queue* next_node = NULL;
	int flg = 0;

	new_node = (struct queue*)malloc(sizeof(struct queue));
	new_node->data.label = student.label;
	strcpy_s(new_node->data.name, 32, student.name);
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		(*head)->next = NULL;
	}

	else
	{
		for (curr_node = *head; curr_node != NULL && flg == 0; curr_node = curr_node->next)
		{
			next_node = curr_node->next;

			if (curr_node->next == NULL)
			{
				flg = 1;
				curr_node->next = new_node;
				curr_node = new_node;
				new_node->next = NULL;
			}

			if (flg == 0 && new_node->data.label != next_node->data.label && new_node->data.label == curr_node->data.label)
			{
				flg = 1;
				curr_node->next = new_node;
				new_node->next = next_node;
			}
		}
	}
}

void traverse_team_queue(struct queue** head)
{
	struct queue* queue_ptr = *head;

	if (queue_ptr == NULL)
		printf("\nTeam queue is empty! ");

	else
	{
		while (queue_ptr != NULL)
		{
			printf("\n");
			printf("\n  %d %s ", queue_ptr->data.label, queue_ptr->data.name);
			queue_ptr = queue_ptr->next;
		}
	}
}

void pop_team_queue(struct queue** head)
{
	char name[32];
	int label;
	struct queue* delete_node;

	if (*head == NULL)
		printf("\nTeam tail is empty! ");

	else
	{
		delete_node = *head;
		label = (*head)->data.label;
		strcpy_s(name, 32, (*head)->data.name);
		*head = (*head)->next;
		free(delete_node);
		printf("\nDeleted student is with label %d and the name %s ", label, name);
	}
}