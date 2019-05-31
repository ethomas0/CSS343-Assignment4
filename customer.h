#pragma once
#include<iostream>
#include "movie.h"


using namespace std;

class Customer
{
public:

	Customer();			     // default constructor
	Customer(int, string, string); // constructor
	~Customer();                    // destructor
	bool movieBorrow(Movie*);       // borrow movie
	bool movieReturn(Movie*);       // return movie

	void printHistory();           // print customer borrow and return history
	int getIDNum() const;          // return customer ID

private:

	bool returnMovie(Movie*);      // returns one or many movie(s) for customer (if possible)
	bool borrowMovie(Movie*);      // borrows one or many movie(s) for customer (if possible) 
	int ID;               		// customer id
	string lastName;               // customer last name
	string firstName;              // customer first name

	


	// structure for customer transaction history
	struct  TransactionLog
	{
		TransactionLog* next;
		char transaction;   // transaction type (Borrow or Return)
		Movie* info;       // pointer to the movie
	};
	TransactionLog* head;

};


