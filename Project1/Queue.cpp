#include "queue.h"
#include <iostream>

/*
* function that initials a queue
* @param q pointer to the start of the queue
* @param size the size of the queue
**/
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
/*
* function that cleans the entire queue
* @param q pointer to the start of the queue
**/
void cleanQueue(Queue* q)
{
	delete[] q->array;
}
/*
* function that adds an object to the queue
* @param q pointer to the start of the queue
* @param newValue the new value that will be added to the queue
**/
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
/*
* function that removes an object from the queue
* @param q pointer to the start of the queue
* @return the value of the removed object (-1 if the queue is empty)
**/
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
/*
* function to check if the queue is empty
* @param q pointer to the start of the queue
* @return true or false
**/
bool isEmpty(Queue* s)
{
	return (s->numOfObjects == 0);
}
/*
* function that checks if the queue is full
* @param q pointer to the start of the queue
* @return true or false
**/
bool isFull(Queue* s)
{
	return (s->numOfObjects == s->sizeOfArray);
}