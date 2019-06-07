// ------------------------------bintree.cpp--------------------------------
// Purpose: 
// --a tree data structure in which each node (root) has at 
//     most two children(left,right), and each node points to data(Movie).
//
// Implementation and assumptions:
//   -- Implement as a binary search tree
//   -- default constructor set root to NULL
//   -- Implement with following futures: 
//      retireve, makeEmpty, insert.
//   -- BinTree doesn't contain duplicate data
//      duplicate  data deletes whithin insert method
// -------------------------------------------------------------------------

#include "bintree.h"


// --------------------- Default Constructor --------------------
// --Creates an empty BSTree
// --------------------------------------------------------------
BinTree::BinTree()
{
	this->root = nullptr;
}



// --------------------- Destructor -----------------------------
// --Calls makeEmpty to delete a BSTree
// --------------------------------------------------------------
BinTree::~BinTree()
{
	makeEmpty();
}

// --------------------- makeEmpty ------------------------------
// --Deletes and entire BSTree
// --Uses helper function makeEmptyHelpter
// --------------------------------------------------------------
void BinTree::makeEmpty()
{
	makeEmptyHelper(root);
}

// --------------------- makeEmptyHelper ------------------------
// --Helper function for makeEmpty
// --Deletes all nodes of a tree
//   and sets nodes to nullptr
// --------------------------------------------------------------
void BinTree::makeEmptyHelper(Node*& current)
{
	if (current != nullptr)
	{
		// Post order traversal
		makeEmptyHelper(current->left);
		makeEmptyHelper(current->right);

		// Deletes NodeData
		delete current->info;
		current->info = nullptr;

		// Deletes Node
		delete current;
		current = nullptr;
	}
}

// --------------------- isEmpty --------------------------------
// --Checks whether a BSTree is empty or not
// --Returns true if empty, else returns false
// --------------------------------------------------------------
bool BinTree::isEmpty() const
{
	return (root == nullptr);
}

// --------------------- retrieve -------------------------------
// --Checks whether or not a NodeData is in a BST
// --If found returns a pointer to that node
// --Uses helper function retrieveHelper
// --------------------------------------------------------------
Movie* BinTree::retrieve(const Movie* movieInfo)
{
	return retriveBSTreeElement(root, movieInfo);
}

// --------------------- retrieveBSTreeElement ------------------
// --Helper function for retrieve()
// --If item is found, will return a pointer to item
// --------------------------------------------------------------
Movie* BinTree::retriveBSTreeElement(Node*& current, const Movie* findMovie) const
{
	// base case 01:
	// item does not exist 
	if (current == nullptr)
	{
		return  nullptr;
	}
	// base case 02:
	// check if root contains the same data
	if (current->info == findMovie)
	{
		return current->info;
	}
	// do binary search:
	// if findMovie is more than current->info go left
	else if (current->info > findMovie)
	{
		return retriveBSTreeElement(current->left, findMovie);
	}
	// findMovie is less, go right
	else
	{
		return retriveBSTreeElement(current->right, findMovie);
	}
}



// --------------------- insert ---------------------------------
// --Inserts a new node containing NodeData into a BST
// --Uses helper function insertHelper
// --------------------------------------------------------------
bool BinTree::insert(Movie* value)
{
	return insertHelper(this->root, value);
}

// --------------------- insertHelper ---------------------------
// --Helper function to insert
// --If NodeData does not already exsist in tree then it will 
//   insert and return true. Does not allow duplicates. 
// --If duplicate is found then does nothing and returns false
// --------------------------------------------------------------
bool BinTree::insertHelper(Node*& current, Movie* value)
{
	// Insert new node here
	if (current == nullptr)
	{
		current = new Node(value);
		return true;
	}
	else if (value < current->info)
	{
		// Traverse left side of tree
		insertHelper(current->left, value);
	}
	else if (value > current->info)
	{
		// Traverse right side of tree
		insertHelper(current->right, value);
	}
	else
	{
		// Node is already in tree
		return false;
	}
}


// --------------------- displayAll ---------------------------------
// --Displays BST in order using helper function
// --------------------------------------------------------------
void BinTree::displayAll() const
{
	inorderDisplay(root);
	cout << endl;
}

// --------------------- inorderDisplay--------------------------
// --Helper function for displayAll()
// --Prints in order
// --------------------------------------------------------------
void BinTree::inorderDisplay(Node* current) const
{
	if (current != nullptr)
	{
		// Traverse left side of tree
		inorderDisplay(current->left);
		// Print current data
		cout << current->info->createMovieInfo();
		// Traverse right side of tree
		inorderDisplay(current->right);
	}
}

