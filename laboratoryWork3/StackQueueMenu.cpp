#include "GetInput.h"
#include "StackQueue.h"
#include "Stack.h"
#include "StackQueueMenu.h"

using namespace std;

void StackForQueue(Stack* stack)
{
	if (stack == nullptr)
	{
		cout << "Null" << endl;
		return;
	}

	if (IsEmpty(stack))
	{
		cout << "Empty" << endl;
		return;
	}

	Stack* temp = CreateStack();
	cout << "Stack contents: " << endl;
	while (!IsEmpty(stack))
	{
		int value = Pop(stack);
		cout << "[ " << value << "] " << endl;
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
	StackForQueue(queue->Stack1);
	cout << "OutStack: ";
	StackForQueue(queue->Stack2);
}

void StackQueueMenu(StackQueue* queue)
{
	//StackQueue* queue = CreateStackQueue();
	while (true)
	{
		cout << "Current queue: ";
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
