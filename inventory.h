//---------------------------------- inventory.h -----------------------------
// --Krystal Levin & Ethan Thomas
//----------------------------------------------------------------------------

#ifndef INVENTORY_H
#define INVENTORY_H
#include "transaction.h"

//----------------------------- class Inventory ------------------------------
// --Purpose:
//	  -- Inventory is a class for viewing the store's Inventory and is 
//		 inherited from Transaction
//----------------------------------------------------------------------------

class Inventory : public Transaction
{
public:
	Inventory(const string&, CustomerManager&, InventoryManager&);		// Constructor
	~Inventory();												// Destructor

	static const char CODE = 'I';		// Transacation Code
};
#endif // !INVENTORY_H

