//============================================================================
// Name        : Linked-List.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include "list.h"

using namespace std;

int main()
{
	List L1;
	L1.addNode(10);
	L1.addNode(9);
	L1.addNode(8);
	L1.printList();
	L1.delData(9);
	L1.printList();
	return 0;
}
