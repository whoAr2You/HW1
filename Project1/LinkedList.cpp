#include "LinkedList.h"

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
void deleteList(Node** head)
{
	Node* current = NULL;
	Node* toDelete = NULL;
	current = *head;
	while (current->next != NULL)
	{
		toDelete = current;
		current = current->next;
		delete toDelete;
	}
	delete current;
	*head = NULL;
}
