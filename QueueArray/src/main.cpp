//============================================================================
// Name        : QueueArray.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Queue.h"

using namespace std;

// Testing queue implementation
int main() {

	Queue Task;
	Task.Enqueue(2);
	Task.Enqueue(3);
	Task.Enqueue(4);
	cout<<"Front : "<<Task.Front()<<endl;
	Task.Dequeue();
	cout<<"Front : "<<Task.Front()<<endl;
	Task.Dequeue();
	Task.Dequeue();
	cout<<"Front : "<<Task.Front()<<endl;
	return 0;
}
