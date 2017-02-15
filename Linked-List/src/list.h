/*
 * list.h
 *
 *  Created on: Feb 3, 2017
 *      Author: shreeganesh
 */


#include <iostream>
#include <cstdlib>

class List{
private:

	typedef struct node {
		int data;
		node * next;
	} * nodePtr;

	nodePtr head;
	nodePtr curr;
	nodePtr temp;

public:
	List();
	void addNode(int addData);				// Add data
	void delData(int delData);				// Delete data
	void printList();						// Print the content
};