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
	//TODO: destruct errorCollection
}


//----------------------------------------------------------------------------
//---------------------------- Utility Functions -----------------------------
//----------------------------------------------------------------------------
/*****************************************************************************
 * Function: processCommands
 * @Param : 		 commandFile where the command char has already be read
 * @Post-condition:
*****************************************************************************/
void Transaction::processCommands(ifstream& commandFile) {
	/*	
	 *
	 *				  TODO: ERROR CATCHING
	 *	 If commands are being processed here it means 
	 *	that it is an invalid instruction: add to errors
	 * 
	 *  errorCollection.push_back( getline()??);  //still working on syntax
	 *
	 */
}

/*****************************************************************************
 * Function: printErrors
 * @Param : 		
 * @Post-condition:
*****************************************************************************/
void Transaction::printErrors() {

	// traverse error collection
	// NOTE: newest Transaction Last 

}