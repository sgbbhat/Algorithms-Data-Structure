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
	head = NULL;
	curr = NULL;
	temp = NULL;
}

// Adding a node to the linked list
void List::addNode(int addData)
{
	nodePtr n = new node;
	n->next = NULL;
	n->data = addData;

	if(head != NULL)
	{
		curr = head;
		while(curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = n;
	}
	else
	{
		head = n;			// In new node created is the first node
	}
}


// Deleting a node from the list
void List::delData(int delData)
{
	nodePtr delPtr = NULL;
	temp = head;
	curr = head;

	while(curr != NULL && curr->data != delData)
	{
		temp = curr;
		curr = curr->next;
	}

	if(curr == NULL)
	{
		cout << delData <<" was not on the list\n";
		delete delPtr;
	}
	else
	{
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		if(delPtr == head)
		{
			head = head->next;
			temp = NULL;
		}
		delete delPtr;
		cout << delData <<" was deleted\n";
	}
}

// Print the entire list
void List::printList()
{
	curr = head;
	while(curr != NULL)
	{
		cout << curr->data <<endl;
		curr = curr->next;
	}
}