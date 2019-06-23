//------------------------------- inventory.cpp ------------------------------
// --Krystal Levin & Ethan Thomas
//----------------------------------------------------------------------------

#include "inventory.h"

//----------------------------- class Inventory ------------------------------
// --Purpose:
//	  -- Inventory is a class for viewing the store's Inventory and is 
//		 inherited from Transaction
//----------------------------------------------------------------------------


//------------------------------- Constructor --------------------------------
//
// --Param:
//	  --commandLine is a string containing the transaction code 'I'
// --Post-condition:
//	  --Calls Inventory Manager to execute the display all function.
//----------------------------------------------------------------------------
 Inventory::Inventory(const string& commandLine, CustomerManager& theCustomers, InventoryManager& theInventory)
{
	theInventory.displayAll(); // ask inventory manager to display all
}

//----------------------------- Destructor -----------------------------------
//
//----------------------------------------------------------------------------
Inventory::~Inventory()
{
	//empty on purpose
}
