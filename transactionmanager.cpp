//--------------------------- transactionmanager.cpp --------------------------
// --Krystal Levin & Ethan Thomas
//---------------------------------------------------------------------------

#include "transactionmanager.h"

//------------------------- class TransactionManager ------------------------
// Purpose:
//	 -- Transaction Manager Processes the transaction file
//---------------------------------------------------------------------------

//----------------------------- Constructor ---------------------------------
//
//---------------------------------------------------------------------------
TransactionManager::TransactionManager()
{
	//empty on purpose
}

//----------------------------- Destructor ----------------------------------
//
//---------------------------------------------------------------------------
TransactionManager::~TransactionManager()
{
	//empty on purpose
}


//--------------------------- readCommands -----------------------------------
// --Function: read commands
// --Param:
//	  --commandFile is a file with commands with 1 command per line
// --Post-condition:
//	  --transaction commands are turned into a  string and then
//		sent to be processed by transaction factory.
//----------------------------------------------------------------------------
void  TransactionManager::readCommands(ifstream& commandFile, CustomerManager& theCustomers, InventoryManager& theInventory)
{
	//char type = ' ';
	string commandLine;

	while (!commandFile.eof()) 			// do until end of file has been reached
	{	getline(commandFile, commandLine);	// get single command

		TransactionFactory doTransaction(commandLine, theCustomers, theInventory); // send it to transaction factory
		string addToErrors = doTransaction.getErrors();

		if (addToErrors != "" && addToErrors[0] == 'E')
		{
			errorCollection.push_back(doTransaction.getErrors());
		}
	}

	cout << "------------------ Transaction Errors --------------------" << "\n";

	for (int i = 0; i < errorCollection.size(); i++)
	{
		
		cout << errorCollection[i] << "\n"; 
	}
}
	
