/*
 * Queue.cpp
 *
 *  Created on: Feb 15, 2017
 *      Author: shreeganesh
 */

#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue() {
	front = -1;
	rear = -1;
	for(int i= 0; i < QUEUE_SIZE ; i++)
	{
		queue[i] = 0;
	}
}

Queue::~Queue() {
	// TODO Auto-generated destructor stub
}

/*
 * Function to determine if the queue is empty
 */
bool Queue::IsEmpty()
{
	if(front == -1 && rear == -1)
		return true;
	else
		return false;
}

/*
 * Function to check if the array if full
 */
bool Queue::IsFull()
{
	int sizeOfArrary = sizeof(queue)/ sizeof(queue[0]);
	if(rear == sizeOfArrary - 1)
	{
		return true;
	}
	else
		return false;
}

/*
 * Function  to add elements to the array
 */
void Queue::Enqueue(int value)
{
	if(((rear+1) % QUEUE_SIZE) == front)
	{
		cout<<"Queue is full "<<endl;
		exit(2);
	}
	else if(IsEmpty())
	{
		front = rear = 0;
	}
	else
	{
		rear = (rear + 1) % QUEUE_SIZE;
	}
	queue[rear] = value;
	cout<<"Value "<< value<<" added to the queue"<<endl;
}

/*
 * Function to remove items from the queue
 */
void Queue::Dequeue()
{
	if(IsEmpty())
	{
		cout<<"Queue is Empty"<<endl;
	}
	else if(front == rear)
	{
		front = rear = -1;
	}
	else
	{
		cout<<"Item dequeued : "<<queue[front]<<endl;
		front = (front + 1) % QUEUE_SIZE;
	}
}

int Queue::Front()
{
	if(IsEmpty())
	{
		cout<< "Queue is empty"<<endl;
		return -1;
	}
	else
		return queue[front];
}
