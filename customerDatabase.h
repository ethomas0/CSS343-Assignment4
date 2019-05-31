#pragma once
#include <iostream>
#include "history.h"
#include "customer.h"

using namespace std;

int const ROWS = 101;
int const COLUMNS = 199;

class CustomerDatabase
{
public:

	CustomerDatabase();                   // constructor
	~CustomerDatabase();                  // destructor
	void proccessCustomers(ifstream& customerFile);   // process file with customers

private:
	bool addCustomertoHashTable(Customer newCustomer);
	void retreiveCustomerFromHash();

	struct HashTable {
		Customer theCustomer;                 	  // the customer
		History  customerHistory;  	  // The name of the Customer
	};

	HashTable tableOfCustomers[ROWS][COLUMNS];  // HashTable
};


