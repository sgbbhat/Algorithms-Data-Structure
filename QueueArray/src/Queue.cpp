/*
 * Queue.cpp
 *
 *  Created on: Feb 15, 2017
 *      Author: shreeganesh
 */

#include "Queue.h"

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

