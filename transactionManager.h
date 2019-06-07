/*
 * TransactionManager Class header File  @file transactionManager.h
 *
 * TransactionMnager is a class that uses a Factory Method to Process
 * transaction commands based on the char type given in the command file
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
#include <string>
#include <fstream>
#include "transaction.h"

#include "borrow.h"
#include "return.h"
#include "history.h"
#include "inventory.h"

using namespace std;
class TransactionManager
{
public:
	TransactionManager();						    // Constructor
	~TransactionManager();							// destructor
	void startTransaction(ifstream& commandList);	// Factory Function

private:
	Transaction* setTransaction;
};

