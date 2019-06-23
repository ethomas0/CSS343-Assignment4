//------------------------- transactionmanager.h ----------------------------
// --Krystal Levin & Ethan Thomas
//---------------------------------------------------------------------------

#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H
#include "inventorymanager.h"
#include  "customermanager.h"
#include "transactionfactory.h"

//------------------------- class TransactionManager ------------------------
// Purpose:
//	 -- Transaction Manager Processes the transaction file
//---------------------------------------------------------------------------
class TransactionManager
{
public:
	TransactionManager();
	virtual ~TransactionManager();
	void readCommands(ifstream&, CustomerManager&, InventoryManager&);    // read commands

private:
	vector<string> errorCollection;
                               
	
};
#endif
