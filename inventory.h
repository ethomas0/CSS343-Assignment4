/*
 * Inventory Class header File  @file inventory.h
 *
 * Inventory is inherited from Transaction
 *
 * Inventory prints out the entire Inventory of the store.
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

class Inventory : public Transaction
{
public:

	Inventory();                 // constructor
	~Inventory();                // destructor
	static const char MyType = 'I';           // static identifier for the class
	virtual void processCommands(char, ifstream& commandFile); // process Transaction
};


