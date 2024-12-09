#include <stdexcept>
#include "Stack.h"

using namespace std;

Stack* CreateStack()
{
    Stack* stack = new Stack();
    stack->Capacity = 5;
    stack->Data = new int[stack->Capacity];
    stack->Top = -1;
    return stack;
}

void Push(Stack* stack, int data) 
{
    if (IsFull(stack))
    {
        Resize(stack, stack->Capacity * GROWTH_FACTOR);
    }

    stack->Data[++stack->Top] = data;
}

int Pop(Stack* stack) 
{
    if (IsEmpty(stack))
    {
        return 0;
    }

    else
    {
        int value = stack->Data[stack->Top];
        stack->Top--;
        return value;
    }
}


bool IsEmpty(Stack* stack) 
{
    return stack->Top == -1; 
}

bool IsFull(Stack* stack)
{
    return stack->Top == stack->Capacity - 1;
}

void Delete(Stack* stack) 
{
    delete[] stack->Data; 
    stack->Data = nullptr; 
}

void Resize(Stack* stack, int newCapacity) 
{
    if (newCapacity <= 0) 
    {
        return ;
    }

    int* newData = new int[newCapacity]; 
    for (int i = 0; i <= stack->Top && i < newCapacity; ++i) 
    {
        newData[i] = stack->Data[i];
    }

    delete[] stack->Data;
    stack->Data = newData;
    stack->Capacity = newCapacity; 
    if (stack->Top >= newCapacity) 
    {
        stack->Top = newCapacity - 1;
    }
}