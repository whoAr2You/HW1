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
void removeNode(Node** head);
void deleteList(Node** head);

#endif // !LINKEDLIST_H
