/*
 * Queue.h
 *
 *  Created on: Feb 15, 2017
 *      Author: shreeganesh
 */

#ifndef QUEUE_H_
#define QUEUE_H_

class Queue {
private:
	struct node
	{
		int value;
		struct node * next;
	};
	node * front;
	node * rear;
public:
	Queue();
	virtual ~Queue();
	void Enqueue(int value);
	void Dequeue();
	int Front();
	bool IsEmpty();
};

#endif /* QUEUE_H_ */
