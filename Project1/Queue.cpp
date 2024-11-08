#include "queue.h"
#include <iostream>

void initQueue(Queue* q, unsigned int size)
{
	q->array = new int[size];
	if (q->array == NULL)
	{
		std::cout << "Could not allocate memory for the queue's array\n";
		return;
	}
	q->sizeOfArray = size;
	q->tail = 0;
}
void cleanQueue(Queue* q)
{
	delete[] q->array;
}
void enqueue(Queue* q, unsigned int newValue)
{
	if (isFull(q))
	{
		std::cout << "The queue is full\n";
		return;
	}
	q->array[q->tail] = newValue;
	q->tail++;
}
int dequeue(Queue* q)
{
	if (isEmpty(q))
	{
		std::cout << "The queue is empty\n";
		return -1;
	}
	int num = q->array[0];
	q->tail--;
	for (int i = 0; i < q->tail; i++)
	{
		q->array[i] = q->array[i + 1];
	}
	return num;
}
bool isEmpty(Queue* s)
{
	return (s->tail == 0);
}
bool isFull(Queue* s)
{
	return (s->tail == s->sizeOfArray);
}