#include "Stack.h"

void push(Stack* s, unsigned int element)
{
	addNode(s->head, element);
}
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
void cleanStack(Stack* s)
{
	deleteList(s->head);
	delete s->head;
}
bool isEmpty(Stack* s)
{
	return *(s->head) == NULL;
}
bool isFull(Stack* s)
{
	return false;
}