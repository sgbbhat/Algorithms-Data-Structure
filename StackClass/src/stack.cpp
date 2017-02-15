/*
 * stack.cpp
 *
 *  Created on: Feb 9, 2017
 *      Author: shreeganesh
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "stack.h"

/*
 * 	Constructor
 */
stack::stack()
{
	stackPtr = NULL;
}

/*
 * 	Destructor
 */
stack::~stack()
{
	item * p1;
	item * p2;

	p1 = stackPtr;

	while(p1 != NULL)
	{
		p2 = p1;
		p1 = p1->prev;
		p2->prev = NULL;
		delete p2;
	}
}

/*
 * 	Remove valoe from the top
 */
void stack::push(string name, int value)
{
	item * n = new item;
	n->name = name;
	n->value = value;

	if(stackPtr == NULL)
	{
		stackPtr = n;
		stackPtr->prev = NULL;
	}
	else
	{
		n->prev = stackPtr;
		stackPtr = n;
	}
}

void stack::pop()
{
	if(stackPtr == NULL)
	{
		cout << "There is nothing on the stack "<<endl;
	}
	else
	{
		item * p = stackPtr;
		readItem(p);
		stackPtr = stackPtr->prev;
		p->prev = NULL;
		delete p;
	}

}

void stack::readItem(item * r)
{
	cout<< "-----------------------"<<endl;
	cout<< "name : "<< r->name<<endl;
	cout<< "value : "<< r->value<<endl;

	cout<< "-----------------------"<<endl;
}

void stack::print()
{
	item * p = stackPtr;

	while(p != NULL)
	{
		readItem(p);
		p = p->prev;
	}

}

