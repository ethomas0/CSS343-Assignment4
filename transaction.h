#pragma once
#include <iostream>
#include <vector> 
#include "inventoryDatabase.h"
#include "movie.h"

using namespace std;

class Transaction
{
public:
	Transaction();              // constructor
	virtual ~Transaction() {};  // destructor

// processes commands
	virtual void processCommands(CustomerDatabase&, InventoryDatabase&);
	void printErrors();                              // prints error massages
	static const char DVD = 'D';                 // shared by all transactions
protected:

	vector <string> errorCollection;   //vector that holds all type of errors during                reading of the commands
};


