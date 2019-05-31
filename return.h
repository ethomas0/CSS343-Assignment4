#pragma once
#include "transaction.h"
#include "customerDatabase.h"

class Return : public Transaction 
{
public:

	Return();                 // constructor
	~Return();                // destructor
	static const char MyType = 'R';           // static identifier for the class
	virtual void processCommands(CustomerDatabase&, InventoryDatabase&); // process Transaction
protected:

	void returnMovie(Customer*, Movie*);   // borrowed movie for customer
};


