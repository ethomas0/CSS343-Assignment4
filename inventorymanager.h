//--------------------------inventorymanager.h-------------------------------
#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "movie.h"
#include "bintree.h"
#include "moviefactory.h"
//--------------------------  class InventoryManager ------------------------
// Purpose: 
//   -- Read given file then sort and insert
//      movies to a spacific BinTrees (Drama,Classiscs, Comedy). 
//      Also, displays all BinTrees and keep track of invalid movies. 
//
// Implementation and assumptions:
//   -- Implement as manager class
//   -- Implement with using factory pattern:
//      MovieFactory class.
//   -- Implement with following futures:
//      proccessInvetory, retriveMovie, displayAll, classicRetrieve,
//		addError, displayErrors
//---------------------------------------------------------------------------

class InventoryManager
{
public:

	void processInventory(ifstream &);                 // proccess invetory
	Movie* retrieveMovie(const string&);
	void displayAll()const;
	Movie* classicRetrieve(Movie*);

private:

	void addError(const string&);                             // add errors from all invalid movie
	void displayErrors() const;                        // displays all invalid movies that has been detected

	vector<string> errorCollection;                     // error collector
	BinTree dramaBST;                                  // BStrees for drama movies
	BinTree classicsBST;                               // BStrees for classics movies
	BinTree comedyBST;                                 // BStrees for comedy movies
};
#endif // !INVENTORYMANAGER_H
