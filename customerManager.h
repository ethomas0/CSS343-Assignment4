#pragma once
#include <fstream>
//#include "history.h"
#include "customer.h"
#include "hashTable.h"
#include <string>


#include "hashTable.h"
using namespace std;


class CustomerManager
{
public:

	CustomerManager();                   // constructor
	~CustomerManager();                  // destructor
	void proccessCustomers(ifstream& customerFile);   // process file with customers
	

private:
	
	HashTable customerStorage;

};


