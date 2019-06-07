/*
 * Transaction Class Implementation File  @file transaction.cpp
 *
 * Transaction is the parent class for different types of transaction
 *
 * Transaction main function processCommands is the fall back for when
 * a transaction could not be processed or invalid. Should this base
 * function be called the information sent to it will be stored in
 * error collection.
 *
 * @Author: 	Krystle S Levin -kslevin@uw.edu
 *				Ethan Thomas	-
 *
 * @Purpose:	Course Assignment 4 for CSS 343
 *				i.e. Data Structures, Algorithms and Discrete Mathematics
 *
 * @Created on:	June 2, 2019
 * @last Modification:	June 6, 2019
 *
 */
#include "transaction.h"


//----------------------------------------------------------------------------
//------------------------------- Constructor --------------------------------
//----------------------------------------------------------------------------
Transaction::Transaction()
{
	//TODO: Initialize errorCollection?
}

//----------------------------------------------------------------------------
//-------------------------------- Destructor --------------------------------
//----------------------------------------------------------------------------
Transaction::~Transaction()
{
	errorCollection.clear();
}


//----------------------------------------------------------------------------
//---------------------------- Utility Functions -----------------------------
//----------------------------------------------------------------------------
/*****************************************************************************
 * Function: processCommands
 *
 * PSA: IF COMMANDS ARE BEING SENT TO THIS FUNCTION IT MEANS THE TRANSACTION
 *		CODE IS INVALID AND WILL BE SENT TO ERROR COLLECTION
 *
 * @Param : 		 char type is the code that caused the error
 * @Post-condition:	the code will be added to erroCollection and the resto of 
 *					the line will be discarded
*****************************************************************************/
void Transaction::processCommands(char type, istream& commandFile) {
	string discard;
	getline(commandFile, discard);	//dicards the rest of the line

	//Adding error to errorCollection:
	errorCollection.push_back(type + " is not a type of transaction");
}



/*****************************************************************************
 * Function: printErrors
 * @Param : 		n/a
 * @Post-condition: Prints all collected error from transaction processing
*****************************************************************************/
void Transaction::printErrors() {
	cout << endl;
	cout << "_____________________________________________________________________________" << endl << endl;
	cout << "                          Invalid Transaction report" << endl << endl;

	for (int i = 0; i < errorCollection.size(); i++){
		cout << errorCollection[i] << "\n";

	}

	cout << endl;
	cout << "_____________________________________________________________________________" << endl;
}