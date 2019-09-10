#include <stdio.h>

void stack();
void queue();
void priority_queue();
void team_queue();
void singly_linked_list();
void doubly_linked_list();

int main()
{
	int choice = 0;

	while (choice != 8)
	{
		printf("\nPlease, enter your choice");
		printf("\n1 -> Stack");
		printf("\n2 -> Queue");
		printf("\n3 -> Priority queue");
		printf("\n4 -> Team queue");
		printf("\n5 -> Singly linked list");
		printf("\n6 -> Doubly linked list");
		scanf_s("%d", &choice);
	
		switch (choice)
		{
		case 1: stack(); break;
		case 2: queue(); break;
		case 3: priority_queue(); break;
		case 4: team_queue(); break;
		case 5: singly_linked_list(); break;
		case 6: doubly_linked_list(); break;
		default: exit(1);
		}
	}
	return 0;
}