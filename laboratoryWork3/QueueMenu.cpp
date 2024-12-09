#include "GetInput.h"
#include "QueueMenu.h"
#include "CircleBuffer.h"
#include "Queue.h"
#include "BufferMenu.h"

using namespace std;

//! \brief display queue
//! \param pointer
void DisplayQueue(Queue* queue)
{
	if (!queue->Cb)
	{
		cout << "Queue empty\n";
		return;
	}

	DisplayBuffer(queue->Cb);
}

void QueueMenu(Queue* queue)
{
	while (true)
	{
		//Queue* queue = CreateQueueByBuffer();
		cout << "Current queue: " << endl;
		DisplayQueue(queue);
		cout << endl;
		int choice = GetInput("Queue menu: \n 1. Add element\n 2. Remove element\n\
 0. Exit\n Your input: ");
		switch (choice)
		{
		case 1:
		{
			int value = GetInput("Enter element to add: ");
			Enqueue(queue, value);
			break;
		}
		case 2:
		{
			if (Dequeue(queue))
			{
				cout << "Element removed.\n";
			}
			else
			{
				cout << "Queue is empty.\n";
			}
			break;
		}

		case 0:
			FreeQueue(queue);
			return;
		default:
			cout << "Error: Invalid choice.\n";
		}
	}
}
