/*
 * list.cpp
 *
 *  Created on: Feb 3, 2017
 *      Author: shreeganesh
 */

#include <iostream>
#include <cstdlib>
#include "list.h"

using namespace std;

List::List()
{
	headptr = NULL;
	currptr = NULL;
	tempptr = NULL;
}

// Adding a node to the linked list
void List::addNode(int addData)
{
	node * n = new node;
	n->next = NULL;
	n->data = addData;

	if(headptr != NULL)
	{
		currptr = headptr;
		while(currptr->next != NULL)
		{
			currptr = currptr->next;
		}
		currptr->next = n;
	}
	else
	{
		headptr = n;			// In new node created is the first node
	}
}

// Deleting a node from the list
void List::delData(int delData)
{
	node * delptr = NULL;
	tempptr = headptr;
	currptr = headptr;

	while(currptr != NULL && currptr->data != delData)
	{
		tempptr = currptr;
		currptr = currptr->next;
	}

	if(currptr == NULL)
	{
		cout << delData <<" was not on the list\n";
		delete delptr;
	}
	else
	{
		delptr = currptr;
		currptr = currptr->next;
		tempptr->next = currptr;
		if(delptr == headptr)
		{
			headptr = headptr->next;
			tempptr = NULL;
		}
		delete delptr;
		cout << delData <<" was deleted\n";
	}
}

// Print the entire list
void List::printList()
{
	currptr = headptr;
	while(currptr != NULL)
	{
		cout << currptr->data <<endl;
		currptr = currptr->next;
	}
}
