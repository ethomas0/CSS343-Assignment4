/*
 * Customer Class Implementation File  @file customer.cpp
 *
 * Customer is a class used to create customer objects
 *
 * All customers have a customerID a first and a last name
 * and a customer history which is stored in a linked list
 * Using a stack type structure where the most recent transaction
 * is listed at the front of the list.
 *
 * @Author: 	Krystle S Levin -kslevin@uw.edu
 * @Purpose:	Course Assignment 4 for CSS 343
 *				i.e. Data Structures, Algorithms and Discrete Mathematics
 *
 * @Created on:	June 2, 2019
 * @last Modification:	June 6, 2019
 *
 */

#include "customer.h"


//----------------------------------------------------------------------------
//------------------------------- Constructor --------------------------------
//----------------------------------------------------------------------------
/*****************************************************************************
 * Default Constructor:
 * @Param : 		N/A
 * @Post-condition: sets ID to -1, lastName and firstName to en empty string
*****************************************************************************/
Customer::Customer()
{
	ID = -1;              		// customer id
	lastName = "";               // customer last name
	firstName = "";
	head == NULL;
}
Customer::Customer(int newID, string newLastName, string newFirstName){
	ID = newID;              		// customer id
	lastName= newLastName;               // customer last name
	firstName = newFirstName;
	head == NULL;
}


Customer::~Customer(){
	TransactionLog* temp;

	while (head != NULL) {
		temp = head;
		head->transaction = NULL;

		delete head->info;
		head->info = NULL;

		head = head->next;
		delete temp;
	}
	delete temp;
	delete head;
}

/*****************************************************************************
 * Function: newTransaction
 * @Param : 		 type is of type char representing the type of transaction
 *					 theMovie is a movie pointing to the movie assocaited to 
 *					 customer transaction.
 * @Post-condition:  the transaction will be added to customer history
*****************************************************************************/
bool Customer::newTransaction(char type, Movie* theMovie) {
	head->next = head;
	head->transaction = type;
	head->info = theMovie;

}


/*****************************************************************************
 * Function: printHistory
 * @Param :			N/A
 * @Post-condition: Prints the entire customer transaction history
*****************************************************************************/
void Customer::printHistory() {
	cout << getName() << ": ID# " << IDOutput <<endl; 

	TransactionLog * current = head;

	bool done = false;

	while (!done) {
		cout << head->transaction;
		//print movie info

		if (current->next == NULL)
			done == true;
		else
			current = current->next;
	}


}
/*****************************************************************************
 * Function: getID
 * @Param :			N/A
 * @Post-condition: Returns the int value of the customer's ID
*****************************************************************************/
int Customer::getIDNum()const{
	return ID;
}

/*****************************************************************************
 * Function: getName
 * @Param :			N/A
 * @Post-condition: returns the string value of the customers whole name
*****************************************************************************/
string Customer::getName()const{
	return firstName + " " + lastName;
}

/*****************************************************************************
 * Function: getLastName
 * @Param :			N/A
 * @Post-condition: returns the string value of the customer's last name
*****************************************************************************/
string Customer::getLastName()const{
	return lastName;
}

/*****************************************************************************
 * Function: getFirstName
 * @Param :			N/A
 * @Post-condition: returns the string value of the customer's first name
*****************************************************************************/
string Customer::getFirstName()const{
	return firstName;
}

/*****************************************************************************
 * Function: IDOutput (private function)
 * @Param :			N/A
 * @Post-condition: formats the customer ID into a string so any leadng 0's 
 *					may also be printed to the output window
*****************************************************************************/
string Customer::IDOutput() {
	string toString = "";

	if (ID > 999)
		toString += ID;

	else if (ID % 1000 == ID)
		toString += ("0" + ID);

	else if(ID % 100 == ID)
		toString += ("00" + ID);

	else if (ID % 10 == ID)
		toString += ("000" + ID);

	return toString;
}
