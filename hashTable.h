//------------------------------ hashTable.h --------------------------------
// --Krystal Levin & Ethan Thomas
//---------------------------------------------------------------------------

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "customer.h" 
using namespace std;
//-------------------------- class HashTable --------------------------------
// Purpose:
//	 --HashTable is a class built to safely store up to 10,000 customer ID's
//	   in a 101 x 199 two - dimentional matrix, or table. The algorithm 
//	   determines the ID location by placing the customer in the table 
//	   location[(ID + i ^ 2) % 101][(ID + i ^ 2) % 199] where
//	   i is the number of "hits" or tries to place the ID in the table
//---------------------------------------------------------------------------

int const ROWS = 101;
int const COLUMNS = 199;
class HashTable
{
public:
	HashTable();		//constructor
	~HashTable();		//destructor
	Customer* retrieveCustomer(const int&)const;				//getFunction
	bool addCustomerToHash(Customer* newCustomer);	//addFunction
	bool removeCustomer(const int&);						//deleteFunction


private:
	Customer* customerTable[ROWS][COLUMNS];			//The table

};
#endif

