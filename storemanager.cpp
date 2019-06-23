//----------------------------- storemanager.cpp ----------------------------
// --Krystal Levin & Ethan Thomas
//---------------------------------------------------------------------------

#include <string>
#include "string.h"
#include <iostream>
#include <fstream>
#include "storemanager.h"

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

//----------------------------- buildStore ----------------------------------
// --Processes inventory file(movieFile) and customer file(customerFile)
//---------------------------------------------------------------------------
void StoreManager::buildStore(ifstream& movieFile, ifstream& customerFile)
{
	allInventory.processInventory(movieFile);
	allCustomers.proccessCustomers(customerFile);
}

//------------------------------ readCommands -------------------------------
// --Processes transaction commmands file (commands)
//---------------------------------------------------------------------------
void StoreManager::readCommands(ifstream& commands)
{
	allTransactions.readCommands(commands, allCustomers, allInventory);
}
