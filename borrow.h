/*
 * Borrow Class Header File  @file Borrow.h
 *
 * Borrow is inherited from Transaction
 *
 * Borrow processes a borrow transaction by deincrementing 
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
#include "customerManager.h"
#include "customer.h"

class Borrow : public Transaction
{
public:

	Borrow();							// constructor
	~Borrow();							// destructor

	virtual void processCommands(char, ifstream&); // process Transaction

};


