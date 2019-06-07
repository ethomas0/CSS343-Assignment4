/*
 * HashTable Class Implementation File  @file hashTable.cpp
 *
 * HashTable is a class built to safely store up to 10,000 customer ID's
 * in a 101 x 199 two-dimentional matrix, or table
 *
 * The algorithm determines the ID location by placing the customer
 * In the table location [(ID + i^2) % 101][(ID +i^2) % 199] where
 * i is the number of "hits" or tries to place the ID in the table
 *
 *
 * @Author: 	Krystle S Levin -kslevin@uw.edu
 * @Purpose:	Course Assignment 4 for CSS 343
 *				i.e. Data Structures, Algorithms and Discrete Mathematics
 * @Created on:	June 2, 2019
 * 				*last Modification:	June 2, 2019
 *
 */
#include "hashTable.h"

//----------------------------------------------------------------------------
//------------------------------- Constructor --------------------------------
//----------------------------------------------------------------------------
/*****************************************************************************
 * Default Constructor
 * @Param : 		N/A
 * @Post-condition: fills the table with NULL pointers
*****************************************************************************/
HashTable::HashTable(){
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLUMNS; c++) {
			customerTable[r][c] = NULL;
		}
	}

}
//----------------------------------------------------------------------------
//-------------------------------- Destructor --------------------------------
//----------------------------------------------------------------------------
/*****************************************************************************
 * Default Constructor:
 * @Param : 		N/A
 * @Post-condition: Deallocates memory by deleating any existing pointers and
 *				    setting all table values to NULL
*****************************************************************************/

HashTable::~HashTable(){
	for (int r = 0; r < ROWS; r++) {			// traversing all rows
		for (int c = 0; c < COLUMNS; c++) {		// traversing all columns
			if (customerTable[r][c] != NULL) {		// if a pointer exists
				delete customerTable[r][c];		    // delete pointer
				customerTable[r][c] = NULL;			// setting table spot back to null
			}
		}
	}
}

/*****************************************************************************
 * Function: addCustomertoDatabase
 * @Param : 		 The newCustomer to be added has non-empty strings and
 *					 a customer ID>= 0
 *
 * @Post-condition:  The customer is added to the Hash table at the location
 *					 [iSquared + ID % Rows][iSquared + ID % COLUMNS]
 *					 where I= the number of 'hit' in the table
 *					 and ROWS and COLUMNS are the prime numbers 101 and 199
 *					 respectively, generating space for 20099 possible ID's
*****************************************************************************/
bool HashTable::addCustomertoHash(Customer* newCustomer) {
	int IDnumber = newCustomer->getIDNum();

	if (IDnumber < 0 || newCustomer->getName() == " ") //if it is default customer = invalid input
		return false;

	int i = 0;
	bool done = false;

	while (!done) { //Hash algorithm: [iSquared + ID % Rows][iSquared + ID % COLUMNS]
		int iSquared = i * i;

		//IF table of customers is empty: fill with newCustomer
		if (customerTable[(iSquared + IDnumber) % ROWS][(iSquared + IDnumber) % COLUMNS] == NULL) {
			customerTable[(iSquared + IDnumber) % ROWS][(iSquared + IDnumber) % COLUMNS] = newCustomer;
			done = true;
			return true;
		}

		//IF table of customers has the same customer, we are done
		if (customerTable[(iSquared + IDnumber) % ROWS][(iSquared + IDnumber) % COLUMNS] == newCustomer) {
			done = true;
			return true;
		}

		//ELSE: table of customers is already full at location
		//at this point newCustomer has not been added to hash 

		i++;		//increment i by +1 and retry	

		if (i == 9999) //max number of entries, prevents unlikelyhood of infinite loop
			break;

	}

	return false;
}

/*****************************************************************************
 * Function: remove Customer
 * @Param : 		 Existing ID is the ID of the customer to be removed
 *
 * @Post-condition:  If the customer exists in the table A pointer to the
 *					 customer is returned. If the customer does not exist
 *					 then NULL is returned.
*****************************************************************************/
bool HashTable::removeCustomer(int existingID) {
	int i = 0;
	bool done = false;

	while (!done) {
		int iSquared = i * i;

		if (customerTable[(iSquared + existingID) % ROWS][(iSquared + existingID) % COLUMNS] == NULL)
			return false; //customer does not exist


		//Customer Exists in Table
		int currentID = customerTable[(iSquared + existingID) % ROWS][(iSquared + existingID) % COLUMNS]->getIDNum();

		//If it's a match:
		if (currentID == existingID) { //if ID's Match then we are done
			delete customerTable[(iSquared + existingID) % ROWS][(iSquared + existingID) % COLUMNS];
			customerTable[(iSquared + existingID) % ROWS][(iSquared + existingID) % COLUMNS] = NULL;
			done = true;
			
		}
		
		//Else: increment i by 1 and try again
		i++;
		if (i == 9999) //max number of entries, prevents infinite loop if customer does not exist
			break;
	}

	return false; //Customer was never found

}


/*****************************************************************************
 * Function: retreive Customer
 * @Param : 		 Existing ID is the ID of the customer to be retrieved
 *
 * @Post-condition:  If the customer exists in the table A pointer to the
 *					 customer is returned. If the customer does not exist
 *					 then NULL is returned.
*****************************************************************************/
Customer* HashTable::retreiveCustomer(int existingID) {
	int i = 0;
	bool done = false;
	Customer* temp;

	while (!done) { 
		int iSquared = i * i;

		temp = customerTable[(iSquared + existingID) % ROWS][(iSquared + existingID) % COLUMNS];


		int currentID = temp->getIDNum();

		if (currentID == existingID) { //if ID's Match then we are done
			done = true;
			return temp;
		}

		if (i == 9999) //max number of entries, prevents infinite loop if customer does not exist
			break;
	}

	return NULL; //Customer was never found

}

