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
	Node* current = NULL;
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
	current = *head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = node;
}