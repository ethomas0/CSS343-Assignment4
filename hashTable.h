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
	Customer* customerTable[ROWS][COLUMNS];

};

