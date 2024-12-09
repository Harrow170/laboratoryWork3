#include "Stack.h"
#include "GetInput.h"

using namespace std;

void DisplayStack(Stack* stack)
{
	if (IsEmpty(stack))
	{
		cout << "Stack empty\n";
		return;
	}
	cout << "Stack elements: " << endl;
	for (int i = stack->Top; i >= 0; i--)
	{
		cout << stack->Data[i] << " " << endl;
	}
}

void StackMenu(Stack* stack)
{
	//Stack* stack = CreateStack();
	while (true)
	{
		cout << "Current stack: " << endl;
		DisplayStack(stack);
		cout << endl;
		int choice = GetInput("Stack menu: \n 1. Add element\n 2. Delete element\n \
3. Is empty\n 4. Resize\n 0. exit\n Your input:\n");
		switch (choice)
		{
			case 1:
			{
				int value = GetInput("Enter element to add: ");
				Push(stack, value);
				break;
			}
			case 2:
			{
				if (!IsEmpty(stack))
				{
					int value = Pop(stack);
					cout << "Removed element: " << value << endl;
				}
				else
				{
					cout << "Stack is empty, cannot pop.\n";
				}
				break;
			}
			case 3:
			{
				if (IsEmpty(stack))
				{
					cout << "Stack is empty.\n";
				}
				else
				{
					cout << "Stack is not empty.\n";
				}
				break;
			}
			case 4:
			{
				int value = GetInput("Enter new size: ");
				Resize(stack, value);
				break;
			}
			case 0:
				Delete(stack);
				return;
			default:
				cout << "Error: Invalid choice.\n";
		}
	}
}