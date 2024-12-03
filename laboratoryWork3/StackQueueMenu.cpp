#include "GetInput.h"
#include "StackQueue.h"
#include "Stack.h"
#include "StackQueueMenu.h"

void DisplayStackQueue(StackQueue* queue)
{
	Stack* tempStack = CreateStack();
	cout << "Queue elements: ";
	while (!IsEmpty(queue->Stack2))
	{
		int value = Pop(queue->Stack2);
		cout << value << " ";
		Push(tempStack, value);
	}

	while (!IsEmpty(queue->Stack1))
	{
		int value = Pop(queue->Stack1);
		cout << value << " ";
		Push(tempStack, value);
	}

	while (!IsEmpty(tempStack))
	{
		int value = Pop(tempStack);
		Push(queue->Stack2, value);
	}

	Delete(tempStack);
	cout << endl;
}

void StackQueueMenu(StackQueue* queue)
{
	//StackQueue* queue = CreateStackQueue();
	while (true)
	{
		cout << "Current queue: ";
		DisplayStackQueue(queue);
		cout << endl;
		int choice = GetInput("Queue menu: \n 1. Add element\n 2. Remove element\n 0. Exit\n Your input: ");
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
