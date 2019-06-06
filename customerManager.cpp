/*
 * CustomerMAnager Class Implementation File  @file customerManager.cpp
 *
 * CustomerManager is a class for customer processing
 *
 * @Author: 	Krystle S Levin -kslevin@uw.edu
 *
 * @Purpose:	Course Assignment 4 for CSS 343
 *				i.e. Data Structures, Algorithms and Discrete Mathematics
 *
 * @Created on:	June 2, 2019
 * 				*last Modification:	June 6, 2019
 *
 */

#include "customerManager.h"



CustomerManager::CustomerManager()
{
}


CustomerManager::~CustomerManager()
{
}

//----------------------------------------------------------------------------
//--------------------------- Utility Functions ------------------------------
//----------------------------------------------------------------------------
/*****************************************************************************
 * Function: processCustomers
 * @Param : 		 customerFile is a valid file of customer data where each 
 *					 line is in the format: 
 *						int ID, string LastName, string firstName
 *
 * @Post-condition:  Creates customer objects with the specified data and
 *					 adds them to the customer Database
 *					 (i.e the HashTable: tableOfCustomers)
*****************************************************************************/
void CustomerManager::proccessCustomers(ifstream& customerFile) {
	int fileID;
	string lastName, firstName;

	while(!customerFile.eof()){		// until end of file
		customerFile >> fileID >> lastName >> firstName;	// get Info

		//Then add to storage:
		customerStorage.addCustomertoHash(new Customer(fileID, lastName, firstName));
		
	}

}

/*****************************************************************************
 * Function: getCustomer
 *			 retreives the customer from the customerStorage hash table
 *
 * @Param : 		 int is the ID of the customer wished to be retreived
 *
 * @Post-condition:  Returns a pointer to the customer in customerStorage
*****************************************************************************/
Customer* CustomerManager::getCustomer(int existingID) {

	//search customer storage for the customer pointer

	return customerStorage.retreiveCustomer(existingID); 
}
