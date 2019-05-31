#pragma once
#include "customerDatabase.h"

class Inventory : public Transaction
{
public:

	Inventory();                 // constructor
	~Inventory();                // destructor
	static const char MyType = 'I';           // static identifier for the class
	virtual void processCommands(CustomerDatabase&, InventoryDatabase&); // process Transaction
};


