#include <iostream>
#include <string>
#include <limits>
#include "StackMenu.h"
#include "BufferMenu.h"
#include "QueueMenu.h"
#include "StackQueueMenu.h"
#include "Menu.h"
#include "GetInput.h"

using namespace std;

void Menu()
{
	Stack* stack = CreateStack();
	CircleBuffer* cb = CreateCircleBuffer();
	Queue* queue = CreateQueueByBuffer();
	StackQueue* sque = CreateStackQueue();
	while (true)
	{
		int choice = GetInput("Menu: \n 1. Stack\n 2. Buffer\n 3. Queue\n 4. Stack queue\n 0. End\n Your input: ");
		switch (choice)
		{
		case 1:
			StackMenu(stack);
			break;

		case 2:
			BufferMenu(cb);
			break;

		case 3:
			QueueMenu(queue);
			break;

		case 4:
			StackQueueMenu(sque);
			break;

		case 0:
			Delete(stack);
			FreeBuffer(cb);
			FreeQueue(queue);
			FreeStackQueue(sque);
			return; 

		default:
			cout << "Error: Invalid choice." << endl;
		}
	}
}
