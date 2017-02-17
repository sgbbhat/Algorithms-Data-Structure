//============================================================================
// Name        : QueueLinkedList.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
	// Testing Queue implementation
	Queue Task;
	Task.Enqueue(10);
	Task.Enqueue(20);
	Task.Enqueue(30);
	Task.Enqueue(40);
	Task.Enqueue(50);
	Task.Enqueue(60);
	cout<<Task.Front()<<endl;
	Task.Dequeue();
	cout<<Task.Front()<<endl;
	Task.Dequeue();
	cout<<Task.Front()<<endl;
	return 0;
}
