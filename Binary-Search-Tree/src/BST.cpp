//============================================================================
// Name        : Binary-Search-Tree.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdlib>
#include <iostream>
#include "BST.h"

using namespace std;

BST::BST(){
    root = NULL;
}

/*
 * Function to create leaf nodes
 */
BST::node * BST::createLeaf(int key){
    node * n = new node;
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    return n;
}

/*
 * Function to add node to a Binary Search tree.
 */
void BST::AddLeaf(int key){
    AddLeafPrivate(key, root);
}

void BST::AddLeafPrivate(int key, node* ptr){
    if(root == NULL){                   // Check if root node is pointing to NULL ptr
        root = createLeaf(key);
    }
    else if(key < ptr->key){           // Compare the value of key passed with key of left node
        if(ptr->left != NULL){
            AddLeafPrivate(key, ptr->left);
        }
        else{
            ptr->left = createLeaf(key);
        }
    }
    else if(key > ptr->key){           // Compare the value of key passed with key of left node
        if(ptr->right != NULL){        // Keep moving as long as the last node pointing to NULL reached
            AddLeafPrivate(key, ptr->right);
        }
        else{
            ptr->right = createLeaf(key);
        }
    }
    else{
        cout<<"Key"<< " has been already added to the list"<<endl;
    }
}

/*
 * Function that uses an in order traversal to print the contents of a
 * binary search tree from lowest to highest value.
 */
void BST::PrintInOrder(){
    PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node * ptr){
    if(root != NULL){
        if(ptr->left != NULL){
            PrintInOrderPrivate(ptr->left);
        }
        cout<<ptr->key<< " ";

        if(ptr->right != NULL){
            PrintInOrderPrivate(ptr->right);
        }
    }
    else{
        cout<<"Tree is empty"<<endl;
    }
}

/*
 * A helper function that is capable of returning a pointer to a node
 * which matches a given key value.
 */
BST::node * BST::ReturnNode(int key){
    return ReturnNodePrivate(key, root);
}

BST::node* BST::ReturnNodePrivate(int key, node* ptr)
{
    if(ptr != NULL)
    {
        if(ptr->key == key)
        {
            return ptr;
        }
        else
        {
            if(key < ptr->key)
            {
                return ReturnNodePrivate(key, ptr->left);
            }
            else
            {
                return ReturnNodePrivate(key, ptr->right);
            }
        }
    }
    else
    {
    	return NULL;
    }
}

/*
 * Function that returns key value of the root.
 */
int BST::ReturnRootNode()
{
	if(root != NULL)
	{
		return root->key;

	}
	else
	{
		return -1000;
	}

}
/*
 *  Function to display children of a parent node.
 */
void BST::PrintChildren(int key)
{
	node * ptr = ReturnNode(key);
	if(ptr!= NULL)
	{
		cout<<"\nParent node value "<<ptr->key<<endl;

		ptr->left == NULL ?
				cout<<"Left child is NULL"<<endl : cout<<"Left child is "<<ptr->left->key<<endl ;
		ptr->right == NULL ?
				cout<<"Right child is NULL"<<endl : cout <<"Right child is "<<ptr->right->key<<endl;
	}
	else
	{
		cout<<"Key"<<key<< " is not in the tree";
	}
}

/*
 * Function to find the smallest key value in the binary search tree.
 */
int BST::FindSmallest()
{
	return FindSmallestPrivate(root);
}

int BST::FindSmallestPrivate(node * ptr)
{
	if(root == NULL)
	{
		cout<<"Tree is empty"<<endl;
		return -1000;
	}
	else
	{
		if(ptr->left != NULL)
		{
			return FindSmallestPrivate(ptr->left);
		}
		else
		{
			return ptr->key;
		}
	}
}

/*
 *  Function for deleting a node in the binary search tree
 */
void BST::RemoveNode(int key)
{
	RemoveNodePrivate(key, root);
}

void BST::RemoveNodePrivate(int key, node * parent)
{
	if(root != NULL)
	{
		if(root->key == key)
		{
			RemoveRootMatch();
		}
		else
		{
			if(key < parent->key && parent->left != NULL)
			{
				parent->left->key == key ?
						RemoveMatch(parent, parent->left, true):
						RemoveNodePrivate(key, parent->left);
			}
			else if(key > parent->key && parent->right != NULL)
			{
				parent->right->key == key ?
						RemoveMatch(parent, parent->right, false):
						RemoveNodePrivate(key, parent->right);
			}
			else
			{
				cout<<"Key "<<key<< "was not found in the tree"<<endl;
			}
		}
	}
	else
	{
		cout<<"Tree is empty"<<endl;
	}
}

/*
 * A helper function that is capable of removing the root node from our binary search tree.
 */
void BST::RemoveRootMatch()
{
	if(root != NULL)
	{
		node * delptr = root;
		int rootkey = root->key;
		int smallestInRightSubTree;

		// case - 0 : Root node has 0 children
		if(root->left == NULL && root->right == NULL)
		{
			root = NULL;
			delete delptr;
		}
		// case - 1 : Root has one child
		else if(root->left == NULL && root->right != NULL)
		{
			root = root->right;
			delptr->right = NULL;
			delete delptr;
			cout<<"Root node with key"<<rootkey<<" was deleted"<<endl<<
					"The new root contains the key"<<root->key<<endl ;
		}
		// case - 2 : 2 children
		else
		{
			smallestInRightSubTree = FindSmallestPrivate(root->right);
			RemoveNodePrivate(smallestInRightSubTree, root);
			root->key = smallestInRightSubTree;
			cout<<"Root key containing key "<<rootkey<<" was overwritten with the key"<<root->key<<endl;
		}
	}
	else
	{
		cout<<"Root is empty"<<endl;
	}
}

/*
 *  A helper function that removes a non-root node from the binary search tree.
 */
void BST::RemoveMatch(node * parent, node * match, bool left)
{
	if(root != NULL)
	{
		node * delptr;
		int matchkey = match->key;
		int smallestInRightSubTree;

		// case - 0 : 0 children
		if(match->left == NULL && match->right == NULL)
		{
			delptr = match;
			left = true ?
					parent->left = NULL : parent->right = NULL;
			delete delptr;
			cout<<"Node containing key "<<matchkey<<" was removed"<<endl;
		}

		// case - 1 : 1 children
		else if(match->left == NULL && match->right != NULL)
		{
			left = true ?
					(parent->left = match->right) : (parent->right = match->right);
			match->right = NULL;
			delptr = match;
			delete delptr;
			cout<<"Node containing key "<<matchkey<<" was removed"<<endl;
		}
		else if(match->left != NULL && match->right == NULL)
		{
			left = true ?
					(parent->left = match->left) : (parent->right = match->left) ;
			match->left = NULL;
			delptr = match;
			delete delptr;
			cout<<"Node containing key "<<matchkey<<" was removed"<<endl;
		}

		// case - 2 : 2 children
		else
		{
			smallestInRightSubTree = FindSmallestPrivate(root->right);
			RemoveNodePrivate(smallestInRightSubTree, match);
			match->key = smallestInRightSubTree;
		}
	}
	else
	{
		cout<<"Can not remove match. The tree is empty";
	}

}
