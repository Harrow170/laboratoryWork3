#include "GetInput.h"
#include "BufferMenu.h"

using namespace std;

void DisplayBuffer(CircleBuffer* cb)
{
	if (OccupiedSpace(cb) == 0)
	{
		cout << "Buffer empty\n";
		return;
	}

	cout << "Elements: " << endl;
	int current = cb->Head;
	do
	{
		cout << cb->Buffer[current] << " ";
		current = (current + 1) % cb->BufferSize;
	} while (current != cb->Tail);
	cout << endl;
}

void BufferMenu(CircleBuffer* cb)
{
	//CircleBuffer* cb = CreateCircleBuffer();
	while (true)
	{
		cout << "Current buffer: " << endl;
		DisplayBuffer(cb);
		cout << endl;
		int choice = GetInput("Buffer menu: \n 1. Add element\n 2. Remove element\n \
3. Get free space\n 4. Get space\n 0. Exit\n Your input: ");
		switch (choice)
		{
		case 1:
		{
			int value = GetInput("Enter element to add: ");
			try
			{
				AddElement(cb, value);
			}

			catch (const overflow_error& e)
			{
				cout << e.what() << endl;
			}
			break;
		}
		case 2:
		{
			if (Remove(cb))
			{
				cout << "Element removed.\n";
			}
			else
			{
				cout << "Buffer is empty.\n";
			}
			break;
		}
		case 3:
		{
			cout << "Free space: " << FreeSpace(cb) << endl;
			break;
		}
		case 4:
		{
			cout << "Occupied space: " << OccupiedSpace(cb) << endl;
			break;
		}

		case 0:
			FreeBuffer(cb);
			return;
		default:
			cout << "Error: Invalid choice.\n";
		}
	}
}