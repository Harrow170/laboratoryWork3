#pragma once
#include "CircleBuffer.h"

//! \brief Структура очереди на основе кольцевого буфера.
struct Queue
{
	//! \brief pointer
	CircleBuffer* Cb;
};

//! \brief Creates and initializes a queue using a circle buffer.
//! \return Pointer to the created queue.
Queue* CreateQueueByBuffer();

//! \brief Adds an element to the end of the queue.
//! param queue Pointer to the queue where the element will be added.
//! param item The value to be added to the queue.
void Enqueue(Queue* queue, int item);

//! \brief Removes and returns the front element from the queue.
//! param queue Pointer to the queue from which the element will be removed.
//! \return Value of the removed element.
int Dequeue(Queue* queue);

//! \brief Frees the memory occupied by the queue and its buffer.
//! param queue Pointer to the queue that needs to be deleted.
void FreeQueue(Queue* queue);