/*
 * Transaction Class Header File  @file transaction.h
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
#pragma once
#include <iostream>
#include <vector> 
#include "customer.h"
#include "movie.h"

using namespace std;

class Transaction
{
public:
	Transaction();              // constructor
	virtual ~Transaction() {};  // destructor

// processes commands
	virtual void processCommands(ifstream&);
	void printErrors();                              // prints error massages
	static const char DVD = 'D';                 // shared by all transactions

protected:

	vector <string> errorCollection;   //vector that holds all type of errors during                reading of the commands
};


