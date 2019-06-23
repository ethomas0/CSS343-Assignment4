//-------------------------- transactionfactory.cpp -------------------------
// --Krystal Levin & Ethan Thomas
//---------------------------------------------------------------------------

#include "transactionfactory.h"

//-------------------------- class TransactionFactory -----------------------
// Purpose:
//	 -- Transaction Factory determines the type of transaction to be executed
//---------------------------------------------------------------------------

 
//------------------------------- Constructor --------------------------------
// --Param : 		 
//	  --commandLine is a string containing the transaction code
//		the customer ID, the type of movie (DVD) and the first
//		two sorting attributes of the movie to be borrowed
// --Post-condition:
//	  --Send the transaction information to its respective
//		transaction type. If the transaction code or movie type
//---------------------------------------------------------------------------
TransactionFactory::TransactionFactory(const string& commandLine, CustomerManager& theCustomers, InventoryManager& theInventory) {
	//Initializing temp variables
	Transaction* newTransaction = nullptr;

	char transactionType(' '), movieType(' ');
	int IDdummy = 0;


	stringstream ss;            // string reader
	ss << commandLine;			// getting command line for manipulation and analyzation
	ss >> transactionType;		// getting transaction type

	if (transactionType == 'B' || transactionType == 'R') //If its a borrow or return transaction
	{	ss >> IDdummy >> movieType;							// get additional info

		if (movieType != Transaction::DVD)					// Make sure its correct type of movie
		{
			transactionType = InvalidTransaction::CODE;		// If not, set transaction to invalid transaction code
		}
			
	}
	//string transactionError = "";

	switch (transactionType)
	{ 
	case Inventory::CODE:
		newTransaction= new Inventory(commandLine, theCustomers, theInventory);
		break;

	case History::CODE: 
		newTransaction = new History(commandLine, theCustomers, theInventory);
		break;

	case Borrow::CODE:
		newTransaction = new Borrow(commandLine, theCustomers, theInventory);

		break;

	case Return::CODE:
		newTransaction = new Return(commandLine, theCustomers, theInventory);
		break;

	default:
		newTransaction = new InvalidTransaction(commandLine);
		break;
	}

	error = newTransaction->getError();


	delete newTransaction;
}

//---------------------------------- getErrors ------------------------------
// --Returns a string of erros
//---------------------------------------------------------------------------
string TransactionFactory::getErrors() const
{
	return error;
}


