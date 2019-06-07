/*
 * History Class Header File  @file History.h
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
#pragma once
#include "transaction.h"

class History : public Transaction
{
public:

	History();                 // constructor
	~History();                // destructor
	static const char MyType = 'H';           // static identifier for the class
	virtual void processCommands(char, ifstream&); // process Transaction
};


