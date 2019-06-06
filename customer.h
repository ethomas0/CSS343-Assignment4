/*
 * Customer Class Header File  @file customer.h
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

#pragma once
#include <fstream> 
#include <iostream>
#include <string> 
#include "movie.h"


using namespace std;

class Customer
{
public:

	Customer();							// default constructor
	Customer(int, string, string);		// constructor with parameters
	~Customer();						// destructor
	bool newTransaction(char, Movie*);  //adds transaction to customer history

	void printHistory();				// print customer borrow and return history
	int getIDNum()const;				// return customer ID
	string getName()const;				// returns string of customer full name
	string getLastName()const;			// returns the string of the custome last name
	string getFirstName()const;			// returns the string of the customer first name

private: 
	int ID;               			// customer id
	string lastName;                // customer last name
	string firstName;               // customer first name
	string IDOutput();

// structure for customer transaction history
	struct  TransactionLog
	{
		TransactionLog* next;		// pointer to next transaction
		char transaction;			// transaction type (Borrow or Return)
		Movie* info;				// pointer to the movie
	};
	TransactionLog* head;

};


