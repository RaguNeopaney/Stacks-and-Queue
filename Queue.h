#ifndef QUEUE_H
#define QUEUE_H
#include <string>
#include <iostream>
using namespace std;
template <typename T>

class queue
{
public:
	// classes for errors
	class enqueError {};			// Handles the first catch block for queue overflow
	class dequeError {};			// Handles the second catch block for queue underflow
	class pekError {};				// Handles the third catch block for peek error from empty queue

	queue(int);
	~queue();
	void enqueue(T);
	T* dequeue();				// Returns the pointer of T type
	T* peek();					// Returnt the pointer of T type
	int length();
	bool isempty();
	bool isfull();
	void makeempty();

private:
	int SIZE;
	T* queArray;
	int front;
	int back;
	int count;
};
template <typename T>					// overloaded constructor
queue<T>::queue(int siz)
{
	SIZE = siz;
	queArray = new T[siz];
	front = -1;
	back = -1;
	count = 0;
}

template <typename T>				// Destructor
queue<T>::~queue()
{
	delete[] queArray;
}

template <typename T>				// enqueue function
void queue<T>::enqueue(T numToadd) 
{
	if (isfull())
	{
		//string fullexception = "ERROR: Cannot Enqeue the queue is full. \n";
		throw	enqueError();
	}
	else
	{
		back++;
		queArray[back] = numToadd;
		count++;
	}
}

template <typename T>				// dequeue function
T* queue<T>::dequeue() 
{
	if (isempty())
	{
		//string emptyException = "ERROR: Cannot dequeue from the stack. Stack is empty. \n";
		throw dequeError();
	}
	else
	{
		front++;
		T* item = &queArray[front];
		count--;
		return item;
	}
}

template <typename T>			// peek function
T* queue<T>::peek() 
{
	if (isempty())
	{
		throw pekError();
	}
	else
	{
		T* retval = &queArray[0];
		return retval;
	}

}

template <typename T>		// length function
int queue<T>::length()
{
	return SIZE;
}

template <typename T>		// isempty function
bool queue<T>::isempty() 
{
	if (count)				// if count is anything other than 0 this executes as true
	{
		return false;
	}
	else
	{
		return true;
	}
}

template <typename T>		// isfull function
bool queue<T>::isfull() 
{
	if (count < SIZE)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template <typename T>
void queue<T>::makeempty() 
{
	front = -1;
	back = -1;
	count = 0;
	~queue();
}
#endif // QUEUE_H
