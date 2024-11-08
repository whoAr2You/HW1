#ifndef LINKEDLIST_H
#define LINKEDLIST_h

#include <iostream>

typedef struct  Node
{
	int num;
	Node* next;
}Node;

Node* createNode(int num);
void addNode(Node** head, int num);

#endif // !LINKEDLIST_H
