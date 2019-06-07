/*
 * Borrow Class Implementation File  @file Borrow.cpp
 *
 * Borrow is inherited from Transaction
 *
 * Borrow processes a borrow transaction by deincrementing
 * the stock of a particular movie by 1 and recording the
 * transaction in the history of the associated customer.
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
#include "borrow.h"



Borrow::Borrow()
{
}


Borrow::~Borrow()
{
}

//----------------------------------------------------------------------------
//---------------------------- Utility Functions -----------------------------
//----------------------------------------------------------------------------
/*****************************************************************************
 * Function: Borrow:: processCommands
 * @Param : 		 The command type has already been extracted from the file
 *					 the rest of the Command file is formatted in the following 
 *					 way:
 *						(int) customerId, (char)MovieType, (char)moveGenre,
 *							with the rest of the line containing movie info
 *							of the movie to be borrowed
 *
 * @Post-condition:  If the movie is found in the store's inventory, the 
 *					 stock will be decreased by 1, and the transaction
 *					 will be recorded in the customer transaction history
 *			
 *					 If the movie is not found in the inventory an error
 *					 report will be sent to error collection.
*****************************************************************************/

void Borrow::processCommands(char type, ifstream& commandFile) { 
	int customerID;
	char movieType; //will be D for DVD
	char genre;

	commandFile >> customerID >> movieType >> genre;

	if (Movie* moviePtr = theShelves.retreiveMovie(genre, commandFile)) {

		//moviePtr-> **SOME FUNCTION TO REDUCE INVENTORY BY 1 **

		transactee.getCustomer(customerID)->newTransaction(type, moviePtr);
	}
	else {
		errorCollection.push_back("Sorry, we do not have"+ moviePtr->movieInfo());
	}

}