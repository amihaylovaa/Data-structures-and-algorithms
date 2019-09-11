#include <stdio.h>
#include <stdlib.h>

struct heap
{
	int v;
};

const int MAX_COUNT_NODES = 50;
void write(struct heap*, int, struct heap*);
void read(struct heap*, int, struct heap*);

void min_heap()
{
	int size;
	int count = 0;
	struct heap* heap = NULL;
	struct heap* data = NULL;

	do
	{
		printf("Enter heap's size :");
		scanf_s("%d", &size);

	} while (size<0 && size>MAX_COUNT_NODES);

	heap = (struct heap*)malloc(sizeof(struct heap) * size);
	data = (struct heap*)malloc(sizeof(struct heap)*size);


	while(size>count)
	{
		printf("Enter values in heap:");
		scanf_s("%d", &data->v);

		write(heap, count, data);
		count++;
	}

	read(heap, count, data);

	free(data);

	for (int i = 1; i <= count; i++)
		printf("\n%d", heap[i].v);
}

void write(struct heap* heap, int count, struct heap* new_node)
{
	struct heap tmp;

	if (count >= MAX_COUNT_NODES - 1) return;

	heap[++count] = *new_node;

	for (int i = count, j = i / 2; j >= 1; i = j, j = i / 2)
	{
		if (heap[j].v > heap[i].v)
		{
			tmp = heap[i];
			heap[i] = heap[j];
			heap[j] = tmp;
		}
	}
}

// under construction
void read(struct heap* hp, int count, struct heap* read)
{
	int left_node, right_node, curr_node_idx;
	struct heap tmp;

	*read = hp[1];
	hp[1] = hp[count--];

	for (int i = 1; i <= count / 2; i = curr_node_idx)
	{
		left_node = i * 2;
		right_node = left_node + 1;

		curr_node_idx = (hp[left_node].v <= hp[right_node].v) ? left_node : right_node;

		if (hp[curr_node_idx].v < hp[i].v)
		{
			tmp = hp[curr_node_idx];
			hp[curr_node_idx] = hp[i];
			hp[i] = tmp;
		}
	}
}