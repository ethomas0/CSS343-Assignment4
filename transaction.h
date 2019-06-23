//-------------------------------- transaction.h ----------------------------
// --Krystal Levin & Ethan Thomas
//---------------------------------------------------------------------------

#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "customermanager.h"
#include "inventorymanager.h"

//-------------------------------- class Transaction ------------------------
// Purpose:
//	 -- Transaction is the parent class for all transactions
//---------------------------------------------------------------------------

class Transaction
{
public:
	Transaction();				// constructor: necessary for inheritance
	virtual ~Transaction();		// virtual desrtuctor

	static const char DVD = 'D';	// All transactions are for DVD's
	string getError() const;

protected:
	string newError;
};
#endif

