#include "CircleBuffer.h"
#include "Queue.h"
#include <stdexcept>

using namespace std;

Queue* CreateQueueByBuffer()
{
    Queue* queue = new Queue;
    queue->Cb = CreateCircleBuffer();
    return queue;
}


void Enqueue(Queue* queue, int item) 
{
    AddElement(queue->Cb, item);
}

int Dequeue(Queue* queue) 
{
    return Remove(queue->Cb);
}

void FreeQueue(Queue* queue)
{
    if (queue == nullptr)
    {
        return;
    }

    delete queue->Cb;  
    queue->Cb = nullptr; 
}