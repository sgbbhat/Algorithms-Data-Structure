/*
 * main.cpp
 *
 *  Created on: Feb 2, 2017
 *      Author: shreeganesh
 */

#include <cstdlib>
#include <iostream>
#include "BST.h"

using namespace std;

int main(int argc, char** argv) {
    int TreeKeys[16] = {50,76,21,4,32,64,15,52,14,100,83,2,3,70, 87,80};
    BST myTree;
    int input = 0;
    cout<<"Printing the tree in order"<<endl<<"before adding numbers"<<endl;
    myTree.PrintInOrder();

    for(int i = 0; i< 16; i++ ){                    // Adding keys to the tree
        myTree.AddLeaf(TreeKeys[i]);
    }

    cout<<"Printing the tree in order"<<endl<<"after adding numbers"<<endl;

    myTree.PrintInOrder();							// Printing elements in the tree

    for(int i=0; i<16; i++)
    {
    	  myTree.PrintChildren(TreeKeys[i]);		// Printing childrens of a node
    }
    cout<<"Smallest element in a tree is "<<myTree.FindSmallest()<<endl;

    cout<<"Enter the key to delete and -1 to stop the process"<<endl;


    while(input != -1)
    {
    	cout<<"Delete node : "<<endl;
    	cin>>input;
    	if(input != -1)
    	{
    		cout<<endl;
    		myTree.RemoveNode(input);
    		myTree.PrintInOrder();
    	}
    }

    return 0;
}

/*
 * Deconstructor for the Binary Search Tree Project.
 */
BST::~BST()
{
	RemoveSubTree(root);
}

void BST::RemoveSubTree(node * ptr)
{
	if(ptr != NULL)
	{
		if(ptr->left != NULL)
		{
			RemoveSubTree(ptr->left);
		}
		if(ptr->right != NULL)
		{
			RemoveSubTree(ptr->right);
		}
		cout<<"Deleting the node containing the key "<<ptr->key<<endl;
		delete ptr;
	}
}
