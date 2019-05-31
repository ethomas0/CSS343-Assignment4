#pragma once
#include <iostream>
#include "bintree.h"

using namespace std;

class InventoryDatabase
{
public:
	void processInventory(ifstream& inventoryFile);            // process inventory
	Movie* getMovie(string movieInfo, char code);          // retrieve movie from BST
	void displayAll();	//Displays all genres of movies in their respective order
private:

	vector<string> errors;                      // error collector
	BinTree drama;                                  // BST for drama movies
	BinTree classics;                               // BST for classics movies
	BinTree comedy;                                 // BST for comedy movies
};


