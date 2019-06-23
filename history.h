//----------------------------------- history.h -----------------------------
// --Krystal Levin & Ethan Thomas
//---------------------------------------------------------------------------

#ifndef HISTORY_H
#define HISTORY_H
#include "transaction.h"

//----------------------------- class History -------------------------------
// Purpose:
//	 -- History is a class for viewing customer transaction history
//	    and is inherited from Transaction
//---------------------------------------------------------------------------

class History : public Transaction
{
public:
	History(const string&, CustomerManager&, InventoryManager&); // Constructor
	~History();											 // Destructor

	static const char CODE = 'H';	//Transaction Code
};
#endif

