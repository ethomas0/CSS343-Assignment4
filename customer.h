//------------------------------ customer.h ---------------------------------
// --Krystal Levin & Ethan Thomas
//---------------------------------------------------------------------------

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <fstream> 
#include <iostream>
#include <string> 
#include "movie.h"
using namespace std;

//--------------------------  class Customer  -------------------------------
// Purpose: 
//	 -- Customer class contains ID, first, and last name. Also,
//      customer keeps track of their borrowed and returned movies.
//
// Implementation and assumptions:
//   -- Implement with  a linked list 
//   -- Implement with following futures: 
//      newTransaciton, printHistory, getIDNum, getName, getfirstName,
//		getLastName, checkIfBorrowed.
//---------------------------------------------------------------------------

class Customer
{
public:

	Customer();							// default constructor
	Customer(int, string, string);		// constructor with parameters
	~Customer();						// destructor
	bool newTransaction(char, Movie*);  // adds transaction to customer history

	void printHistory() const;				// print customer borrow and return history
	int getIDNum()const;				// return customer ID
	string getID()const;						// get customer ID
	string getName()const;				// returns string of customer full name
	string getFirstName()const;			// returns the string of the customer first name
	string getLastName()const;			// returns the string of the custome last name
	bool checkIfBorrowed(Movie*)const; // checks if customer is returning a movie they borrowed

private: 
	
	int ID;               				// customer id
	string lastName;					// customer last name
	string firstName;					// customer first name
	

// structure for customer transaction history
	struct  TransactionLog
	{
		TransactionLog* next;        // next
		char transaction;			// transaction type (B or R)
		Movie* info;				// pointer to the movie
		bool rented;
		TransactionLog(char type, Movie* movie) : transaction(type), info(movie), next(nullptr), rented(false) {};
	};
	TransactionLog* head;
	

};
#endif

