#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct list
{
	int key;
	struct list* next;
	struct list* prev;
};

typedef struct list LIST;

void add_node(LIST**, int);
void traverse_linked_list(LIST*);
LIST* find_node_by_value(LIST*, int);
void insert_node(LIST**, LIST*);
void delete_node(LIST**, int);

void doubly_linked_list()
{
	LIST* head = NULL;
	int choice;

	while (1)
	{
		printf("\nDoubly linked list");
		printf("\n1 -> Add a new node");
		printf("\n2 -> Find a node by value");
		printf("\n3 -> Insert a new node");
		printf("\n4 -> Delete a node by value");
		printf("\n5 -> Traverse the list");
		printf("\n6 -> Exit");
		scanf_s("%d", &choice);


		if (choice == 1)
		{
			int key_value;

			printf("Enter data");
			scanf_s("%d", &key_value);

			add_node(&head, key_value);
		}

		else if (choice == 2)
		{
			int search_value;
			LIST* search;

			printf("\nFind node by value");
			scanf_s("%d", &search_value);
			search = find_node_by_value(head, search_value);
			if (search == NULL)
				printf("\nNode with value %d does not exist", search_value);
			else
				printf("\nNode found - %d", search->key);
		}

		else if (choice == 3)
		{
			LIST* new_node = (LIST*)malloc(sizeof(LIST));
			new_node->next = NULL;

			printf("\nEnter data");
			scanf_s("%d", &new_node->key);

			insert_node(&head, new_node);
		}

		else if (choice == 4)
		{
			int delete_value;
			printf("\n Delete a node by value :");
			scanf_s("%d", &delete_value);

			delete_node(&head, delete_value);
		}

		else if (choice == 5)
			traverse_linked_list(head);

		else
			return;
	}
}

void add_node(LIST** head, int key_value)
{
	LIST* new_node = (LIST*)malloc(sizeof(LIST));
	LIST* list_ptr;

	new_node->key = key_value;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (*head == NULL)
		* head = new_node;
	else
	{
		for (list_ptr = *head; list_ptr->next != NULL; list_ptr = list_ptr->next);
		new_node->prev = list_ptr;
		list_ptr->next = new_node;
		list_ptr = new_node;
		list_ptr->next = new_node->next = NULL;
	}
}

void traverse_linked_list(LIST* head)
{
	LIST* node_ptr;
	for (node_ptr = head; node_ptr != NULL; node_ptr = node_ptr->next)
		printf("\n%d", node_ptr->key);
}

LIST* find_node_by_value(LIST* head, int val)
{
	LIST* node_ptr;

	for (node_ptr = head; node_ptr != NULL && node_ptr->key != val; node_ptr = node_ptr->next);
	return node_ptr;
	return NULL;
}
void insert_node(LIST** head, LIST* new)
{
	LIST* list_ptr;

	if ((*head)->key > new->key)
	{
		new->next = *head;
		*head = new;
		(*head)->prev = new->prev = NULL;
	}

	else
	{
		for (list_ptr = *head; list_ptr->next != NULL && list_ptr->next->key < new->key; list_ptr = list_ptr->next);

		if (list_ptr->next == NULL)
		{
			list_ptr->next = new;
			new->prev = list_ptr;
			list_ptr = new;
			list_ptr->next = new->next = NULL;
		}

		else
		{
			new->next = list_ptr->next;
			new->prev = list_ptr;
			list_ptr->next->prev = new;
			list_ptr->next = new;
		}
	}
}

void delete_node(LIST** head, int delete_value)
{
	LIST* curr_node = NULL, * prev_node = NULL;

	if ((*head)->key == delete_value)
	{
		curr_node = *head;
		*head = (*head)->next;
		free(curr_node);
	}

	else
	{
		for (curr_node = *head; curr_node->next != NULL && curr_node->key != delete_value;
			                               prev_node = curr_node, curr_node = curr_node->next);
	
		if (curr_node->next == NULL && curr_node->key == delete_value)
		{
		prev_node->next = curr_node->next;
		free(curr_node);
		curr_node = prev_node;
		}

		if (curr_node->key == delete_value)
		{
			prev_node->next = curr_node->next;
			curr_node->next->prev = prev_node;
			free(curr_node);
			curr_node = prev_node->next;
		}
		
		else
			return;
	}
}