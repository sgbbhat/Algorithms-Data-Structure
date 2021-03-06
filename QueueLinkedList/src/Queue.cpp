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
	front = NULL;
	rear = NULL;;
}

Queue::~Queue() {
}

/*
 * Function to check if queue is empty
 */
bool Queue::IsEmpty()
{
	if(front == NULL && rear== NULL)
		return true;
	else
		return false;
}

/*
 * Function to add elements to queue
 */
void Queue::Enqueue(int value)
{
	node * temp = (node *) malloc(sizeof(node*)) ;
	temp->value = value;
	temp->next = NULL;

	if(front == NULL && rear == NULL)
	{
		front = rear = temp ;
		return;
	}
	rear->next = temp;
	rear = temp;
}

/*
 * Function to remove elements from the queue
 */
void Queue::Dequeue()
{
	node * temp = (node *) malloc(sizeof(node*)) ;
	if(front == NULL)
	{
		return;
	}
	else if(front == rear)
	{
		front = rear = NULL;
	}
	temp = front;
	front = front->next;
	free(temp);
}

int Queue::Front()
{
	return front->value;
}
