/*
 * BinTree Class Header File  @file bintree.h
 *
 * Class Specifications:
 * This project is to create a binary search tree class called BinTree
 *
 * For further specifications see README.txt
 *
 * @Author: 	Krystle S Levin -kslevin@uw.edu
 * @Purpose:	Course Assignment 2 for CSS 343 
 *				i.e. Data Structures, Algorithms and Discrete Mathematics 
 * @Created on:	April 10, 2019
 * 				last Modification:	April 28, 2019
 */
 
#include "nodeData.h"

#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>
#include <algorithm>
using namespace std;

class BinTree {				
//overload output stream:
	friend ostream& operator <<(ostream &, const BinTree&);	
	
public:
	BinTree();								// constructor
	BinTree(const BinTree &);				// copy constructor
	~BinTree();								// destructor, calls makeEmpty	
	
	
//Class Functions
	bool isEmpty() const;					// true if tree is empty, otherwise false
	void makeEmpty();						// make the tree empty so isEmpty returns true

	
//Overload Functions	
	BinTree& operator=(const BinTree &);	//Assignment Operator
	
//Comparison Operators
	bool operator==(const BinTree &) const;	//True if equal
	bool operator!=(const BinTree &) const;	//True if not equal
	
//Accessors and Modifiers
	bool insert(NodeData*);
	bool retrieve(const NodeData &, NodeData* &);
	int  getHeight (const NodeData &) const;
	void bstreeToArray(NodeData* []);
	void arrayToBSTree(NodeData* []);
	
	void displaySideways() const;			// Instructor provided below, 
											// displays the tree sideways

	private:
	struct Node {
		NodeData* data;						// pointer to data object
		Node* left;							// left subtree pointer
		Node* right;						// right subtree pointer
	};
	Node* root;								// root of the tree

// utility functions
	void inOrderTraversal(Node*) const;

	void makeEmptyRecursiveHelper(Node*&);	   		// helps makeEmpty
	void printInOrderTraversal(Node*) const;   		// helps << overload operator
	void copyNode(Node*, Node*&);					// helps = assignment operator 
	bool compareAllNodes(Node*, Node*) const; 		// helps comparison operators
	bool insertHelper(Node*&, NodeData*);			// helps insert function	
	bool recursiveFind(Node* &, const NodeData &, NodeData* &) const;
													// helps retrieve function
	int getHeightHelper(const NodeData&, Node*) const;
													// helps get height function
	int calculateHeight(Node*) const;				// does calculation for getHeightHelper
	int toArrayHelper(Node*, NodeData* []);			// helps bsTreetoArray function									
	void toBinTreeHelper(Node*, NodeData* [], int, int);						
	
	
	void sideways(Node*, int) const;		    // Instructor provided:
												// helper for displaySideways()

};

#endif