#include "Utils.h"

void reverse(int* nums, unsigned int size)
{
	Stack* stack = new Stack;
	initStack(stack);
	if (stack == NULL)
	{
		std::cout << "Could not allocate memory for the stack in reverse function\n";
		return;
	}
	for (int i = 0; i < size; i++)
	{
		push(stack, nums[i]);
	}
	for (int i = 0; i < size; i++)
	{
		nums[i] = pop(stack);
	}
	cleanStack(stack);
	delete stack;
}
int* reverse10()
{
	int* array = new int[ARRAY_10_SIZE];
	for (int i = 0; i < ARRAY_10_SIZE; i++)
	{
		std::cout << "Enter " << i + 1 << "st number: ";
		std::cin >> array[i];
	}
	reverse(array, ARRAY_10_SIZE);
	return array;
}