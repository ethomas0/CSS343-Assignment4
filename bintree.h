//----------------------------bintree.h--------------------------------------
#ifndef BINTREE_H
#define BINTREE_H
#include <string>
#include <iostream>
#include "movie.h"

//--------------------------  class BinTree  --------------------------------
// Purpose: 
//   -- a tree data structure in which each node (root) has at 
//      most two children(left,right), and each node points to data(Movie).
//
// Implementation and assumptions:
//   -- Implement as a binary search tree
//   -- default constructor set root to NULL
//   -- Implement with following futures: 
//      retireve, makeEmpty, insert.
//   -- BinTree doesn't contain duplicate data
//      duplicate  data deletes whithin insert method
//---------------------------------------------------------------------------
class BinTree 
{

public:

	BinTree();							   // constructor
	~BinTree();							   // destructor
	
	void makeEmpty();					   // empty out BinTree
	bool isEmpty() const;                  // true if tree is empty, otherwise false

	Movie* retrieve(const Movie*); // retrive data from BinTree
	bool insert(Movie*);         // recurisve insert
	void displayAll() const;


private:

	struct Node
	{
		Movie* info;						// pointer to data object
		Node* left;							// left subtree pointer
		Node* right;						// right subtree pointer
		Node(Movie* data) :info(data), left(nullptr), right(nullptr) {};
	};
	Node* root;								// root of the tree

	//helpers
	void makeEmptyHelper(Node*&);            // helper for makeEmpty()
	void inorderDisplay(Node*) const; // helper for operator<<()
	Movie* retriveBSTreeElement(Node*&, const Movie*) const; // helper for retrive()
	bool insertHelper(Node*&, Movie*);
	
};

#endif
