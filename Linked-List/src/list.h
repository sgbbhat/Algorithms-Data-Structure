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

	struct node {
		int data;
		node * next;
	} ;

	node * headptr;
	node * currptr;
	node * tempptr;

public:
	List();
	void addNode(int addData);				// Add data
	void delData(int delData);				// Delete data
	void printList();						// Print the content
};
