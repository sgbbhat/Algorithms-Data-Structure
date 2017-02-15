/*
 * Queue.h
 *
 *  Created on: Feb 15, 2017
 *      Author: shreeganesh
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#define QUEUE_SIZE 10

class Queue {
private:
	int queue[QUEUE_SIZE];
	int front ;
	int rear ;

public:
	Queue();
	virtual ~Queue();
	bool IsEmpty();
	bool IsFull();
	void Enqueue(int value);
	void Dequeue();
	int Front();
};

#endif /* QUEUE_H_ */
