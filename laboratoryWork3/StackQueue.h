#pragma once
#include "Stack.h"

//! \brief Structure representing a queue implemented using two stacks
struct StackQueue 
{
    //! \brief 1 stack
    Stack* Stack1;

    //! \brief 2 stack
    Stack* Stack2; 
};

//! \brief Function to create a new instance of StackQueue
//! \return Pointer to the newly created StackQueue instance.
StackQueue* CreateStackQueue();

//! \brief Initializes the input and output stacks for the queue.
//! param queue Pointer to the StackQueue instance to be initialized.
//! param size The size of the stacks.
void InitStackQueues(StackQueue* queue, int size);

//! \brief Checks if the queue is empty.
//! param queue Pointer to the StackQueue instance to check.
//! \return True if the queue is empty, false otherwise.
bool IsStackQueueEmpty(const StackQueue* queue);

//! \brief Adds an element to the end of the queue.
//! param queue Pointer to the StackQueue instance where the element will be added.
//! param data The value to be added to the queue.
void EnqueueStackQueue(StackQueue* queue, int data);

//! \brief Removes and returns the first element from the queue.
//! param queue Pointer to the StackQueue instance from which the element will be removed.
//! \return Value of the removed element.
int DequeueStackQueue(StackQueue* queue);

//! \brief Clears the queue by deleting both stacks.
//! param queue Pointer to the StackQueue instance that needs to be cleared.
void FreeStackQueue(StackQueue* queue);
