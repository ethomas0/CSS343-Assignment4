/*
 * HashTable Class Header File  @file hashTable.h
 *
 * HashTable is a class built to safely store up to 10,000 customer ID's 
 * in a 101 x 199 two-dimentional matrix, or table
 *
 * The algorithm determines the ID location by placing the customer
 * In the table location [(ID + i^2) % 101][(ID +i^2) % 199] where
 * i is the number of "hits" or tries to place the ID in the table
 *
 *
 * @Author: 	Krystle S Levin -kslevin@uw.edu
 * @Purpose:	Course Assignment 4 for CSS 343
 *				i.e. Data Structures, Algorithms and Discrete Mathematics
 * @Created on:	June 2, 2019
 * 				*last Modification:	June 2, 2019
 *
 */
#pragma once
#include "customer.h" 

using namespace std;

int const ROWS = 101;
int const COLUMNS = 199;

class HashTable{

public:
	HashTable();		//constructor
	~HashTable();		//destructor
	Customer* retreiveCustomer(int);				//getFunction
	bool addCustomertoHash(Customer* newCustomer);	//addFunction
	bool removeCustomer(int);						//deleteFunction


private:
	Customer* customerTable[ROWS][COLUMNS];			//The table

};

