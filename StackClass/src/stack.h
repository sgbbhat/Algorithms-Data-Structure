/*
 * stack.h
 *
 *  Created on: Feb 9, 2017
 *      Author: shreeganesh
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef STACK_H_
#define STACK_H_

class stack{
private:

	struct item{
		string name;
		int value;
		item * prev;
	};

	item * stackPtr;

public:

	stack();

	~stack();

	void push(string name, int value);

	void pop();

	void readItem(item * r);

	void print();

};



#endif /* STACK_H_ */
