#include "LinkedList.h"

/**
* function that creates a node object
* @param  num the number that will be stored in the node
* @return pointer to node object
*/
Node* createNode(int num)
{
	Node* node = new Node;
	if (node == NULL)
	{
		std::cout << "Could not allocate memory for linked list's node\n";
	}
	node->num = num;
	node->next = NULL;
	return node;
}
/*
* function that adds a node to a linked list
* @param head pointer to the head of the linked list (double pointer)
* @param num the num that will be stored in the new node
**/
void addNode(Node** head, int num)
{
	Node* node = createNode(num);
	if (node ==  NULL)
	{
		std::cout << "Could not create node with the num " << num;
		return;
	}
	if (*head == NULL)
	{
		*head = node;
		return;
	}
	node->next = *head;
	*head = node;
}
/*
* function that removes a node from the linked list
* @param head pointer to the head of the linked list (double pointer)
**/
void removeNode(Node** head)
{
	Node* nodeToDelete = NULL;
	if (*head == NULL)
	{
		std::cout << "The linked list is empty\n";
		return;
	}
	nodeToDelete = *head;
	*head = (*head)->next;
	delete nodeToDelete;
}
/*
* function that deletes the entire linked list
* @param head pointer to the head of the linked list (double pointer)
**/
void deleteList(Node** head)
{
	Node* current = NULL;
	Node* toDelete = NULL;
	current = *head;
	while (current != NULL)
	{
		toDelete = current;
		current = current->next;
		delete toDelete;
	}
	delete current;
	*head = NULL;
}
