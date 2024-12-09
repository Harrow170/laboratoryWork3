#include "Stack.h"
#include "StackQueue.h"
#include <stdexcept>

using namespace std;

StackQueue* CreateStackQueue()
{
	StackQueue* queue = new StackQueue();
	queue->Stack1 = CreateStack();
	queue->Stack2 = CreateStack();
	return queue;
}

void EnqueueStackQueue(StackQueue* queue, int data)
{
	Push(queue->Stack1, data);
}

int DequeueStackQueue(StackQueue* queue)
{
	if (IsEmpty(queue->Stack2))
	{
		while (!IsEmpty(queue->Stack1))
		{
			Push(queue->Stack2, Pop(queue->Stack1));
		}
	}

	if (IsEmpty(queue->Stack2))
	{
		return 0;
	}

	else
	{
		return Pop(queue->Stack2);
	}
}

void FreeStackQueue(StackQueue* queue)
{
	if (queue != nullptr)
	{
		if (queue->Stack1 != nullptr)
		{
			Delete(queue->Stack1);
			queue->Stack1 = nullptr;
		}

		if (queue->Stack2 != nullptr)
		{
			Delete(queue->Stack2);
			queue->Stack2 = nullptr;
		}

		delete queue;
	}
}