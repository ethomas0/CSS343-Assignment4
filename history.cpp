/*
 * History Class implentation File  @file History.cpp
 *
 * History is inherited from Transaction
 *
 * History prints out the history of a specified customer.
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
#include "history.h"

History::History()
{
}


History::~History()
{
}
/*****************************************************************************
 * Function: Borrow:: processCommands
 * @Param : 		 The command type has already been extracted from the file
 *					 the rest of the Command file line contains only the 
 *					 customerId, which is extracted as type int.
 *
 * @Post-condition:  If the customer exists in the system their history is
 *					 printed, if not an error is sent to error collection
*****************************************************************************/
void History::processCommands(char type, ifstream& commandFile) {
	int customerID;
	commandFile >> customerID;

	if(transactee.getCustomer(customerID) == NULL ){
		errorCollection.push_back("Sorry, Customer ID: "+to_string(customerID)+" does not exist");
	}
	else {
		transactee.getCustomer(customerID)->printHistory();
	}
}