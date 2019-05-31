#pragma once
#include "transaction.h"

class History : public Transaction
{
public:

	History();                 // constructor
	~History();                // destructor
	static const char MyType = 'H';           // static identifier for the class
	virtual void processCommands(CustomerDatabase&, InventoryDatabase&); // process Transaction
};


