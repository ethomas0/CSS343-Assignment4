#pragma once
#include "transaction.h"

class Inventory : public Transaction
{
public:

	Inventory();                 // constructor
	~Inventory();                // destructor
	static const char MyType = 'I';           // static identifier for the class
	virtual void processCommands(ifstream& commandFile); // process Transaction
};


