/*
 * CustomerMAnager Class Header File  @file customerManager.h
 *
 * CustomerManager is a class for customer processing
 *
 * @Author: 	Krystle S Levin -kslevin@uw.edu
 *
 * @Purpose:	Course Assignment 4 for CSS 343
 *				i.e. Data Structures, Algorithms and Discrete Mathematics
 *
 * @Created on:	June 2, 2019
 * 				*last Modification:	June 6, 2019
 *
 */

#pragma once
#include <fstream>

#include "customer.h"
#include "hashTable.h"
#include <string>

using namespace std;


class CustomerManager{
public:
	CustomerManager();                   // constructor
	~CustomerManager();                  // destructor
	void proccessCustomers(ifstream& customerFile);   // process file with customers
	Customer* getCustomer(int);						  // returns a customer
	

private:
	HashTable customerStorage;			//stores all customers
};


