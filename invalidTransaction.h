//------------------------------ invalidTransaction.h ------------------------
// --Krystal Levin & Ethan Thomas
//----------------------------------------------------------------------------

#ifndef INVALIDTRANSACTION_H
#define INVALIDTRANSACTION_H
#include "transaction.h"

//--------------------------- class InvalidTransaction -----------------------
// Purpose
//	 -- Inventory is a class for handeling invalid transactions and is 
//		inherited from Transaction
//----------------------------------------------------------------------------

class InvalidTransaction : public Transaction
{
public:
	InvalidTransaction(const string&/*, CustomerManager&, InventoryManager&*/); //constructor
	~InvalidTransaction();											 // destructor

	static const char CODE = 'X';	//Transaction code
};
#endif // !INVALIDTRANSACTION_H

