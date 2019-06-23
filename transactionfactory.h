//--------------------------- transactionfactory.h --------------------------
// --Krystal Levin & Ethan Thomas
//---------------------------------------------------------------------------

#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include "customermanager.h"
#include "inventorymanager.h"
#include "transaction.h"
#include "inventory.h"
#include "history.h"
#include "borrow.h"
#include "return.h"
#include "invalidTransaction.h"

//-------------------------- class TransactionFactory -----------------------
// Purpose:
//	 -- Transaction Factory determines the type of transaction to be executed
//---------------------------------------------------------------------------

class TransactionFactory
{
public:
	TransactionFactory(const string&, CustomerManager&, InventoryManager&); // constructor
	string getErrors() const;
private:
	string error;
};
#endif // !TRANSACTIONFACTORY_H
