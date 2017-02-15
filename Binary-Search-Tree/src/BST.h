/*
 * BST.h
 *
 *  Created on: Feb 2, 2017
 *      Author: shreeganesh
 */

#include <cstdlib>
#include <iostream>

class BST{
    private:
        struct node{
            int key;
            node * left;
            node * right;
        };

        node * root;
        void AddLeafPrivate(int key, node * ptr);
        void PrintInOrderPrivate(node * ptr);
        node * ReturnNodePrivate(int key, node* ptr);
        int FindSmallestPrivate(node * ptr);
        void RemoveNodePrivate(int key, node * parent);
        void RemoveRootMatch();
        node * ReturnNode(int key);			// Return node related to the key
        node * createLeaf(int key);			// Create Leaf node
        void RemoveSubTree(node * ptr);

    public:
        BST();
        ~BST();
        void AddLeaf(int key);				// Add Leaf node
        void PrintInOrder();				// Print
        int ReturnRootNode();
        void PrintChildren(int key);
        int FindSmallest();
        void RemoveNode(int key);
        void RemoveMatch(node * parent, node * match, bool left);
};
