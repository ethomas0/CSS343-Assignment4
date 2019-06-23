//---------------------------- bintree.cpp ----------------------------------
// -- Krystal Levin & Ethan Thomas
//---------------------------------------------------------------------------


//--------------------------  class BinTree  --------------------------------
// Purpose: 
//   -- a tree data structure in which each node (root) has at 
//      most two children(left,right), and each node points to info(Movie).
//
// Implementation and assumptions:
//   -- Implement as a binary search tree.
//   -- default constructor set root to nullptr.
//   -- Implement with following futures: 
//      retrieve, retrieveClassic, makeEmpty, insert,
//		 and displayAll.		
//   -- BinTree doesn't contain duplicate data
//      duplicate  data deletes whithin insert method. Two Classic Movies
//		with same title, month, and year are not considered duplicate if they
//		have different major actors.
//---------------------------------------------------------------------------

#include "bintree.h"


//---------------------- Default Constructor --------------------
// --Creates an empty BSTree.
//---------------------------------------------------------------
BinTree::BinTree()
{
	this->root = nullptr;
}



//---------------------- Destructor -----------------------------
// --Calls makeEmpty to delete a BSTree.
//---------------------------------------------------------------
BinTree::~BinTree()
{
	makeEmpty();
}

//---------------------- makeEmpty ------------------------------
// --Deletes entire BinTree.
// --Uses helper function makeEmptyHelpter.
//---------------------------------------------------------------
void BinTree::makeEmpty()
{
	makeEmptyHelper(root);
}

//---------------------- makeEmptyHelper ------------------------
// --Helper function for makeEmpty.
// --Deletes all nodes of a tree
//   and sets nodes to nullptr.
//---------------------------------------------------------------
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

//------------------------ isEmpty --------------------------------
// --Checks whether a BinTree is empty or not
// --Returns true if empty, else returns false
// --------------------------------------------------------------
//bool BinTree::isEmpty() const
//{
//	return (root == nullptr);
//}

//---------------------- retrieve -------------------------------
// --Checks whether or not a NodeData is in a BinTree.
// --If found returns a pointer to that node else returns
//   nullptr.
// --Uses helper function retrieveHelper.
//---------------------------------------------------------------
Movie* BinTree::retrieve(const Movie* movieInfo)
{
	return retriveBSTreeElement(root, movieInfo);
}

//---------------------- retrieveBSTreeElement ------------------
// --Helper function for retrieve.
// --If item is found, will return a pointer to item else returns
//   nullptr.
// --------------------------------------------------------------
Movie* BinTree::retriveBSTreeElement(Node*& current, const Movie* findMovie) const
{
	// base case 01:
	// item does not exist 
	if (current == nullptr)
	{
		delete findMovie;	// prevents memory leak
		return  nullptr;
	}
	// base case 02:
	// check if root contains the same data
	if (*current->info == findMovie)
	{
		delete findMovie;	// prevents memory leak
		return current->info;
	}
	// do binary search:
	// if findMovie is less than current->info go left
	else if (*current->info > findMovie)
	{
		return retriveBSTreeElement(current->left, findMovie);
	}
	// findMovie is greater, go right
	else
	{
		return retriveBSTreeElement(current->right, findMovie);
	}
}

//--------------------- retrieveClassic -------------------------
// --Used just for Classics movies to find an alternate version
//	 of the film that has same title, month, and year but not
//	 the same major actor.
// --Uses helper method retrieveClassicHelper.
//---------------------------------------------------------------
Movie * BinTree::retrieveClassic(const Movie* findMovie)
{
	const Classics* rhsCopy = (const Classics*)findMovie;
	return retrieveClassicHelper(root, rhsCopy);
}

//--------------------- retrieveClassicHelper -------------------
// --Helper function that finds an alternate version of Classics
//   movie that has same title, month, and year but not the same
//   major actor.
// --Uses Classics isEqual function instead of == operator.
//---------------------------------------------------------------
Movie * BinTree::retrieveClassicHelper(Node *& current, const Classics* findMovie) const
{
	// base case 01:
	// item does not exist 
	if (current == nullptr)
	{
		return  nullptr;
	}
	// base case 02:
	// check if root contains the same data, but not same major Actor
	if (findMovie->isEqual(current->info))
	{
		return current->info;
	}
	// do binary search:
	// if findMovie is less than current->info go left
	else if (*current->info > findMovie)
	{
		return retrieveClassicHelper(current->left, findMovie);
	}
	// findMovie is greater, go right
	else
	{
		return retrieveClassicHelper(current->right, findMovie);
	}
}

//---------------------- insert ---------------------------------
// --Inserts a new node containing NodeData into a BinTree.
// --Uses helper function insertHelper.
//---------------------------------------------------------------
bool BinTree::insert(Movie* value)
{
	return insertHelper(this->root, value);
}

//---------------------- insertHelper ---------------------------
// --Helper function to insert
// --If NodeData does not already exsist in tree then it will 
//   insert and return true. Does not allow duplicates. 
// --If duplicate is found then does nothing and returns false.
//---------------------------------------------------------------
bool BinTree::insertHelper(Node*& current, Movie* value)
{
	// Insert new node here
	if (current == nullptr)
	{
		current = new Node(value);
		return true;
	}
	else if (*current->info > value)
	{
		// Traverse left side of tree
		insertHelper(current->left, value);
	}
	else if (*value > current->info)
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


//---------------------- displayAll -----------------------------
// --Displays BinTree in order using helper function
//---------------------------------------------------------------
void BinTree::displayAll() const
{
	inorderDisplay(root);
	cout << endl;
}

//---------------------- inorderDisplay--------------------------
// --Helper function for displayAll
// --Prints in order
//---------------------------------------------------------------
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

