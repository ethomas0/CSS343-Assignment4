//------------------------------- customermanager.h -------------------------
// --Krystal Levin & Ethan Thomas
//---------------------------------------------------------------------------

#ifndef CUSTOMERMANAGER_H
#define CUSTOMERMANAGER_H
#include <fstream>
#include "customer.h"
#include "hashTable.h"
#include <string>
using namespace std;

//-------------------------- class CustomerManager ---------------------------
// Purpose:
//	 -- CustomerManager proccess customers: puts customers 
//      into HashTble. CustomerManager can also retrieve the customer.
//
// Implementation and assumptions:
//   -- Implement as manager class
//   -- Implement with following futures: 
//      proccessCustomer(), getCustomer()
//---------------------------------------------------------------------------

class CustomerManager
{
public:
	CustomerManager();                   // constructor
	~CustomerManager();                  // destructor
	void proccessCustomers(ifstream& customerFile);   // process file with customers
	Customer* getCustomer(int);						  // returns a customer	

private:
	HashTable customerStorage;			//stores all customers
};
#endif // !CUSTOMERMANAGER_H


