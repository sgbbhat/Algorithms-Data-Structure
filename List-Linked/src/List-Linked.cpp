//============================================================================
// Name        : List-Linked.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class LinkedList
{
private:
	struct node
	{
		int data;
		node * next;
	} ;

	node * currptr;
	node * headptr;
	node * tempptr;

public:
	LinkedList();
	void addNode(int Data);
	void deleteNode(int Data);
	void printList();
};

LinkedList::LinkedList()
{
	currptr = NULL;
	headptr = NULL;
	tempptr = NULL;
}

void LinkedList::addNode(int Data)
{
	node * n = new node();
	n->data = Data;
	n->next = NULL;

	currptr = headptr;

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
		headptr = n;
	}

	cout<<Data<< " added" <<endl;
}

void LinkedList::deleteNode(int Data)
{
	node * delptr = new node();
	currptr = headptr ;
	tempptr = headptr ;

	while(currptr->next != NULL && currptr->data != Data)
	{
		tempptr = currptr ;
		currptr = currptr->next;
	}

	if(currptr == NULL)
	{
		cout <<Data<<" could not be found"<<endl;
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
	}
}

void LinkedList::printList()
{
	currptr = headptr;
	while(currptr != NULL)
	{
		cout<< currptr->data<<endl;
		currptr = currptr->next;
	}
}

int main()
{
	LinkedList List1;
	List1.addNode(10);
	List1.addNode(20);
	List1.addNode(30);
	List1.addNode(40);
	List1.addNode(50);

	List1.printList();
	return 0;
}
