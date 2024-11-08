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