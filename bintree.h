//---------------------------- bintree.h ------------------------------------
// -- Krystal Levin & Ethan Thomas
//---------------------------------------------------------------------------
#ifndef BINTREE_H
#define BINTREE_H
#include <string>
#include <iostream>
#include "classics.h"
#include "movie.h" 

//--------------------------  class BinTree  --------------------------------
// Purpose: 
//   -- a tree data structure in which each node (root) has at 
//      most two children(left,right), and each node points to info(Movie).
//
// Implementation and assumptions:
//   -- Implement as a binary search tree.
//   -- default constructor set root to nullptr
//   -- Implement with following futures: 
//      retrieve, retrieveClassic, makeEmpty, insert,
//		 and displayAll.		
//   -- BinTree doesn't contain duplicate data
//      duplicate  data deletes whithin insert method. Two Classic Movies
//		with same title, month, and year are not considered duplicate if they
//		have different major actors.
//---------------------------------------------------------------------------
class BinTree 
{

public:

	BinTree();							   // constructor
	~BinTree();							   // destructor
	
	void makeEmpty();					   // empties Bintree
	//bool isEmpty() const;                  // checks if Bintree is empty

	Movie* retrieve(const Movie*);			// retrives data from BinTree
	Movie* retrieveClassic(const Movie*);	// retrieves alt Classic from BinTree
	bool insert(Movie*);					// recurisve insert
	void displayAll() const;				// displays BinTree in order


private:

	struct Node
	{
		Movie* info;						// pointer to data object
		Node* left;							// left subtree pointer
		Node* right;						// right subtree pointer
		Node(Movie* data) :info(data), left(nullptr), right(nullptr) {}; // Node constructor
	};
	Node* root;								// root of the tree 

	//helpers
	void makeEmptyHelper(Node*&);									// helper for makeEmpty
	void inorderDisplay(Node*) const;								// helper for displayAll
	Movie* retriveBSTreeElement(Node*&, const Movie*) const;		// helper for retrieve
	Movie* retrieveClassicHelper(Node*&, const Classics*)const;		// helper for retrieveClassic
	bool insertHelper(Node*&, Movie*);								// helper for insert
	
};

#endif
