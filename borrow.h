//----------------------------borrow.h---------------------------------------
// --Krystal Levin & Ethan Thomas
//---------------------------------------------------------------------------

#ifndef BORROW_H
#define BORROW_H
#include "transaction.h"

//--------------------------  class Borrow ----------------------------------
// Purpose: 
//	 -- Child class of Transaction. Borrows movie for customer
//		and updates the InventoryManager
//
// Implementation and assumptions:
//   -- Implement as a child class of Transaction
//   -- Implement with following futures:
//      Borrow (as Borrow is constructed it also creates the transaction or
//		error code depending on situation)
//---------------------------------------------------------------------------
class Borrow : public Transaction
{
public:
	Borrow(const string&, CustomerManager&, InventoryManager&);	// constructor
	~Borrow();												// destructor

	static const char CODE = 'B';							// Transaction Code
};
#endif

