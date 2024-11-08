#include "Stack.h"

/*
* function that pushes an object to the stack
* @param s pointer to the start of the stack
* @param element the value that will be added to the stack
**/
void push(Stack* s, unsigned int element)
{
	addNode(s->head, element);
}
/*
* function that removes an object from the stack
* @param s pointer to the start of the stack
* @return the value of the removed object (-1 if the stack is empty)
**/
int pop(Stack* s)
{
	int element = 0;
	Node* current = NULL;
	if (*(s->head) == NULL)
	{
		std::cout << "The stack is empty\n";
		return -1;
	}
	current = *(s->head);
	element = current->num;
	*(s->head) = current->next;
	delete current;
	return element;
}
/*
* function that initials the stack
* @param s pointer to the start of the stack
**/
void initStack(Stack* s)
{
	s->head = new Node*;
	if (s->head == NULL)
	{
		std::cout << "Could not allocate memory for the linked list\n";
		return;
	}
	*(s->head) = NULL;
}
/*
* function that cleans the entire stack
* @param s pointer to the start of the stack
**/
void cleanStack(Stack* s)
{
	deleteList(s->head);
	delete s->head;
}
/*
* function that checks if the stack is empty
* @param s pointer to the start of the stack
* @return true of false
**/
bool isEmpty(Stack* s)
{
	return *(s->head) == NULL;
}
/*
* function that checks if the stack is full
* @param s pointer to the start of the stack
* @return ALWAYS FALSE the stack cant be full i dont know why this function was in the header file
**/
bool isFull(Stack* s)
{
	return false;
}