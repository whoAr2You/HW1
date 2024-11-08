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
	q->numOfObjects = 0;
	q->head = 0;
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
	if (q->tail == q->sizeOfArray)
	{
		q->tail = 0;
	}
	q->numOfObjects++;
}
int dequeue(Queue* q)
{
	if (isEmpty(q))
	{
		std::cout << "The queue is empty\n";
		return -1;
	}
	int num = q->array[q->head];
	q->head++;
	q->numOfObjects--;
	if (q->head == q->sizeOfArray)
	{
		q->head = 0;
	}
	return num;
}
bool isEmpty(Queue* s)
{
	return (s->numOfObjects == 0);
}
bool isFull(Queue* s)
{
	return (s->numOfObjects == s->sizeOfArray);
}