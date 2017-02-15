//============================================================================
// Name        : StackClass.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

int main()
{
	stack paul;

	// Add items to the stack
	paul.push("Paul", 3);
	paul.push("Caleb", 2);
	paul.push("Cofee", 1);

	// Print contents of the stack
	paul.print();

	cout<<"POPING"<<endl;

	// Removing items from the stack
	paul.pop();

	cout<<"Print remaining"<<endl;

	// Print contents of the stack
	paul.print();
}
