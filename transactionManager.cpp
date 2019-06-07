/*
 * TransactionManager Class Implementation File  @file transactionManager.cpp
 *
 * TransactionMnager is a class that uses a Factory Method to Process 
 * transaction commands based on the char type given in the command file
 *
 * @Author: 	Krystle S Levin -kslevin@uw.edu
 * @Purpose:	Course Assignment 4 for CSS 343
 *				i.e. Data Structures, Algorithms and Discrete Mathematics
 *
 * @Created on:	June 2, 2019
 * @last Modification:	June 6, 2019
 *
 */

#include "transactionManager.h" 
#include "transaction.h" 


TransactionManager::TransactionManager()
{
}

//----------------------------------------------------------------------------
//-------------------------------- Destructor --------------------------------
//----------------------------------------------------------------------------
TransactionManager::~TransactionManager()
{
	delete setTransaction;
	setTransaction = NULL;
}
//----------------------------------------------------------------------------
//---------------------------- Utility Functions -----------------------------
//----------------------------------------------------------------------------
/*****************************************************************************
 * Function: startTransaction
 * @Param : 		 in commandFile the first char in the line is the type
 *					 of transaction to be processed
 *
 * @Post-condition:  startTransaction will use a factory method to determine 
 *					 the type of transaction and then process the commands
 *					 accordingly.
*****************************************************************************/
void TransactionManager::startTransaction(ifstream& commandFile) {
	char type;
	
	while (!commandFile.eof()) {
		commandFile >> type;

		switch (type) {
			case 'B':
				setTransaction=new Borrow();		
				break;

			case 'R':
				setTransaction = new Return();
				break;

			case 'I':
				setTransaction = new Inventory();
				break;

			case 'H':
				setTransaction = new History();
				break;

			default:
				setTransaction = new Transaction();
				break;
		}

		setTransaction->processCommands(commandFile);
	}
}
