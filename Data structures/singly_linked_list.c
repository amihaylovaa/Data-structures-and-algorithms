#include <stdio.h>
#include <stdlib.h>

struct list
{
	int key;
	struct list* next;
};

typedef struct list LIST;

void  add(LIST**, int);
LIST* find_node(LIST*, int);
void traverse_list(LIST*);
void insert(LIST**, LIST*);
void delete(LIST**, LIST*);

void singly_linked_list()
{
	LIST* head = NULL;
	int choice;

	while (1)
	{
		printf("\nSingly linked list");
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
			add(&head, key_value);
		}

		else if (choice == 2)
		{
			int search_value;
			LIST* search_result;

			printf("Enter searched value:");
			scanf_s("%d", &search_value);

			search_result = find_node(head, search_value);

			if (search_result == NULL)
				printf("\nNode with value %d does not exist!", search_value);
			else
				printf("\nValue found - %d !", search_result->key);
		}

		else if (choice == 3)
		{
			LIST* new_node;

			new_node = (LIST*)malloc(sizeof(LIST));
			printf("\nInsert new node");
			scanf_s("%d", &new_node->key);
			new_node->next = NULL;

			insert(&head, new_node);
		}
		else if (choice == 4)
		{
			LIST* delete_node;

			delete_node = (LIST*)malloc(sizeof(LIST));
			printf("\nDelete node by value: ");
			scanf_s("%d", &delete_node->key);

			delete(&head, delete_node);
		}

		else if (choice == 5)
			traverse_list(head);

		else
			return;
	}
}

void add(LIST** head, int key_value)
{
	LIST* new_node;
	LIST* node_ptr;

	new_node = (LIST*)malloc(sizeof(LIST));
	new_node->key = key_value;
	new_node->next = NULL;

	if (*head == NULL)
		* head = new_node;

	else
	{
		for (node_ptr = *head; node_ptr->next != NULL; node_ptr = node_ptr->next);

		node_ptr->next = new_node;
		node_ptr = new_node;
		new_node->next = node_ptr->next = NULL;
	}
}

LIST* find_node(LIST* head, int key_value)
{
	LIST* node_ptr;

	for (node_ptr = head; node_ptr != NULL && node_ptr->key != key_value; node_ptr = node_ptr->next);
	return node_ptr;
}

void insert(LIST** head, LIST* new_node)
{
	LIST* node_ptr;

	if ((*head)->key > new_node->key)
	{
		new_node->next = *head;
		*head = new_node;
	}

	else
	{
		for (node_ptr = *head; node_ptr->next != NULL && node_ptr->next->key < new_node->key; node_ptr = node_ptr->next);
		if (node_ptr->next == NULL)
		{
			node_ptr->next = new_node;
			node_ptr = new_node;
			new_node->next = node_ptr->next = NULL;
		}

		else
		{
			new_node->next = node_ptr->next;
			node_ptr->next = new_node;
		}
	}
}

void traverse_list(LIST* head)
{
	LIST* node_ptr;

	printf("List's elements are :");
	for (node_ptr = head; node_ptr != NULL; node_ptr = node_ptr->next)
		printf("\n%d", node_ptr->key);
}

void delete(LIST** head, LIST* delete_node)
{
	LIST* current_node = NULL;
	LIST* prev_node = NULL;

	if ((*head)->key == delete_node->key)
	{
		current_node = *head;
		*head = (*head)->next;
		free(current_node);
	}

	else
	{
		for (current_node = *head; current_node->next != NULL && current_node->key != delete_node->key; prev_node = current_node, current_node = current_node->next);

		if (current_node->key == delete_node->key)
		{
			prev_node->next = current_node->next;
			free(current_node);
			current_node = prev_node->next;
		}
		else
			return;
	}
}