/*
 * Return Class Header File  @file return.h
 *
 * Return is inherited from Transaction
 *
 * Return processes a return transaction by incrementing
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
#pragma once
#include "transaction.h"


class Return : public Transaction 
{
public:

	Return();                 // constructor
	~Return();                // destructor
	static const char MyType = 'R';           // static identifier for the class
	virtual void processCommands(char, ifstream&); // process Transaction

};


