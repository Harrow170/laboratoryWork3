#include "CircleBuffer.h"
#include <stdexcept>

using namespace std;

CircleBuffer* CreateCircleBuffer()
{
    CircleBuffer* cb = new CircleBuffer();
    cb->BufferSize = SIZE;
    cb->Buffer = new int[cb->BufferSize];
    cb->Head = 0;
    cb->Tail = 0;
    cb->Count = 0;
    return cb;
}

void AddElement(CircleBuffer* cb, int item)
{
    if (cb->Count == cb->BufferSize)
    {
        cb->Head = (cb->Head + 1) % cb->BufferSize;
    }
    else
    {
        cb->Count++;
    }

    cb->Buffer[cb->Tail] = item;
    cb->Tail = (cb->Tail + 1) % cb->BufferSize;
}

int Remove(CircleBuffer* cb)
{
    if (cb->Count == 0)
    {
        return 0;
    }

    else
    {
        int value = cb->Buffer[cb->Head];
        cb->Head = (cb->Head + 1) % cb->BufferSize;
        cb->Count--;
        return value;
    }
}

int FreeSpace(CircleBuffer* cb)
{
    return cb->BufferSize - cb->Count;
}

int OccupiedSpace(CircleBuffer* cb)
{
    return cb->Count;
}

void FreeBuffer(CircleBuffer* cb)
{
    delete[] cb->Buffer;
    delete cb;
}