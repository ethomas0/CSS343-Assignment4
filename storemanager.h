//---------------------------------- storemanager.h -------------------------
// --Krystal Levin & Ethan Thomas
//---------------------------------------------------------------------------

#ifndef STOREMANAGER_H
#define  STOREMANAGER_H
#include <string>
#include "string.h"
#include <iostream>
#include <fstream>
#include "customermanager.h"
#include "inventorymanager.h"
#include "transactionmanager.h"

//--------------------------  class StoreManager ----------------------------
// Purpose:
//   -- Store Manager class: high level manager for other manager
//      classes such as: CustomerManager, InventoryManager, ComandLoaderManager.
//
// Implementation and assumptions:
//   -- Implement as a manager class
//   -- Implement with following futures:
//      buildStore, readCommands
//---------------------------------------------------------------------------
class StoreManager
{
public:

	void buildStore(ifstream&, ifstream&);               // build store by  creating movie and customer base
	void readCommands(ifstream&);                      // proccess commands lines

private:
	CustomerManager allCustomers;                     // Customer manager object
	InventoryManager allInventory;                   // Inventroy manager object
	TransactionManager allTransactions;                         // comands  manager object
};
#endif
