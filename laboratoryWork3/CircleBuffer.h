#pragma once
//! \brief Circle buffer structure.
struct CircleBuffer
{
	//! \brief pointer
	int* Buffer;

	//! \brief laast element
	int Tail;

	//! \brief first element
	int Head;

	//! \brief capacity
	int BufferSize;

	//! \brief number of elements
	int Count;
};

//! \brief initial Circle buffer size.
const int SIZE = 5;

//! \brief Creates and initializes a Circle buffer.
//! \return Pointer to the created Circle buffer.
CircleBuffer* CreateCircleBuffer();

//! \brief Adds an element to the Circle buffer.
//! param cb Pointer to the Circle buffer where the element will be added.
//! param item The value to be added to the buffer.
void AddElement(CircleBuffer* cb, int item);

//! \brief Retrieves an element from the Circle buffer.
//! param cb Pointer to the Circle buffer from which the element will be retrieved.
//! \return Value of the retrieved element.
int Remove(CircleBuffer* cb);

//! \brief Returns the number of free spaces in the Circle buffer.
//! param cb Pointer to the Circle buffer for which the number of free spaces is needed.
//! \return Number of free spaces in the buffer.
int FreeSpace(CircleBuffer* cb);

//! \brief Returns the number of occupied spaces in the Circle buffer.
//! param cb Pointer to the Circle buffer for which the number of occupied spaces is needed.
//! \return Number of occupied spaces in the buffer.
int OccupiedSpace(CircleBuffer* cb);

//! \brief Frees the memory occupied by the Circle buffer.
//! param cb Pointer to the Circle buffer that needs to be deleted.
void FreeBuffer(CircleBuffer* cb);