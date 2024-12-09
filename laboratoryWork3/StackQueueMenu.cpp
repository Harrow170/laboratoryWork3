#include "GetInput.h"
#include "StackQueue.h"
#include "Stack.h"
#include "StackQueueMenu.h"
#include <iostream>

using namespace std;

void PrintStackForQueue(Stack* stack) {
	if (stack == nullptr) 
	{
		cout << "Stack is null." << endl;
		return;
	}

	if (IsEmpty(stack)) 
	{
		cout << "Stack is empty." << endl;
		return;
	}

	Stack* temp = CreateStack();


	cout << "Stack contents: ";
	while (!IsEmpty(stack)) {
		int value = Pop(stack);
		std::cout << value << " ";
		Push(temp, value);
	}
	cout << endl;

	while (!IsEmpty(temp))
	{
		Push(stack, Pop(temp));
	}

	Delete(temp);
}

void DisplayStackQueue(StackQueue* queue)
{
	if (queue == nullptr)
	{
		cout << "Queue is null." << endl;
		return;
	}

	cout << "InStack: ";
	PrintStackForQueue(queue->Stack1);

	cout << "OutStack: ";
	PrintStackForQueue(queue->Stack2);
}


void StackQueueMenu(StackQueue* queue)
{
	//StackQueue* queue = CreateStackQueue();
	while (true)
	{
		cout << "Current queue: " << endl;
		DisplayStackQueue(queue);
		cout << endl;
		int choice = GetInput("Queue menu: \n 1. Add element\n 2. Remove element\n \
0. Exit\n Your input: ");
		switch (choice)
		{
			case 1:
			{
				int value = GetInput("Enter element to add: ");
				EnqueueStackQueue(queue, value);
				break;
			}

			case 2:
			{
				int value = DequeueStackQueue(queue);
				if (value != -1)
				{
					cout << "Removed element: " << value << endl;
				}
				else
				{
					cout << "Queue is empty!" << endl;
				}
				break;
			}

			case 0:
				FreeStackQueue(queue);
				return;

			default:
				cout << "Error: Invalid choice." << endl;
		}
	}
}
