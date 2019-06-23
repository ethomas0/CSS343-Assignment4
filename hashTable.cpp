//--------------------------- hashTable.cpp ---------------------------------
// --Krystal Levin & Ethan Thomas
//---------------------------------------------------------------------------

#include "hashTable.h"

//-------------------------- class HashTable --------------------------------
// --Purpose:
//	  --HashTable is a class built to safely store up to 10,000 customer ID's
//		in a 101 x 199 two - dimentional matrix, or table. The algorithm 
//		determines the ID location by placing the customer in the table 
//		location[(ID + i ^ 2) % 101][(ID + i ^ 2) % 199] where
//		i is the number of "hits" or tries to place the ID in the table
//---------------------------------------------------------------------------



//------------------------------- Default Constructor ------------------------
// --Default Constructor
// --Param: N/A
// --Post-condition:
//	  --Fills the table with nullptrs
//----------------------------------------------------------------------------
HashTable::HashTable()
{
	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLUMNS; c++)
		{
			customerTable[r][c] = nullptr;			//Initializing Table to Null
		}
	}

}

//-------------------------------- Destructor --------------------------------
// --Default Constructor:
// --Param: N/A
// --Post-condition:
//	  --Deallocates memory by deleating any existing pointers and setting
//		all table values to nullptr
//----------------------------------------------------------------------------
HashTable::~HashTable()
{
	for (int r = 0; r < ROWS; r++)	// traversing all rows
	{			
		for (int c = 0; c < COLUMNS; c++)// traversing all columns
		{			
			if (customerTable[r][c] != nullptr) // if a pointer exists
			{	
				delete customerTable[r][c];		    // delete pointer
				customerTable[r][c] = nullptr;			// setting table spot back to null
			}
		}
	}
}

//---------------------------- addCustomerToHash -----------------------------
// --Function: addCustomertoDatabase
// --Param:
//	  --The newCustomer to be added has non-empty strings and a customer ID >= 0
// --Post-condition:  
//	  --The customer is added to the Hash table at the location
//		[iSquared + ID % Rows][iSquared + ID % COLUMNS]
//		where I= the number of 'hit' in the table
//		and ROWS and COLUMNS are the prime numbers 101 and 199
//		respectively, generating space for 20099 possible ID's
//----------------------------------------------------------------------------

bool HashTable::addCustomerToHash(Customer* newCustomer)
{
	int IDnumber = newCustomer->getIDNum();
	unsigned int i = 0;
	bool done = false;

	if (IDnumber < 0 || newCustomer->getName() == " ") //if it is default customer = invalid input
	{
		return done;
	}
		

	while (!done && i < 9999) //Hash algorithm: [iSquared + ID % Rows][iSquared + ID % COLUMNS]
	{	
		unsigned long int iSquared = i * i;

		//IF table of customers is empty: fill with newCustomer
		if(customerTable[(iSquared + IDnumber) % ROWS][(iSquared + IDnumber) % COLUMNS] == nullptr)
		{
			customerTable[(iSquared + IDnumber) % ROWS][(iSquared + IDnumber) % COLUMNS] = newCustomer;
			done = true;
			return done;
		}

		//IF table of customers has the same customer, we are done
		if (customerTable[(iSquared + IDnumber) % ROWS][(iSquared + IDnumber) % COLUMNS] == newCustomer)
		{
			done = true;
			return done;
		}

		//ELSE: table of customers is already full at location
		//at this point newCustomer has not been added to hash 

		i++;		//increment i by +1 and retry
	}

	return done;
}

//------------------------------ removeCustomer ------------------------------
// --Function: removeCustomer
// --Param: 		 
//	  --existingID is the ID of the customer to be removed
// --Post-condition:
//	  --If the customer exists in the table A pointer to the customer is
//		returned. If the customer does not exist then nullptr is returned.
//----------------------------------------------------------------------------
bool HashTable::removeCustomer(const int& existingID) 
{
	unsigned int i = 0;
	bool done = false;
	Customer* temp = nullptr;

	while (!done && i < 9999)
	{
		unsigned long int iSquared = i * i;

		if (customerTable[(iSquared + existingID) % ROWS][(iSquared + existingID) % COLUMNS] == nullptr)
		{
			return done; //customer does not exist
		}

		//Customer Exists in Table
		temp = customerTable[(iSquared + existingID) % ROWS][(iSquared + existingID) % COLUMNS];

		//If it's a match:
		if (temp->getIDNum() == existingID)
		{ //if ID's Match then we are done
			delete customerTable[(iSquared + existingID) % ROWS][(iSquared + existingID) % COLUMNS];
			customerTable[(iSquared + existingID) % ROWS][(iSquared + existingID) % COLUMNS] = nullptr;
			done = true;
			return done;
		}
		
		//Else: increment i by 1 and try again
		i++;
	}

	return done; //Customer was never found
}

//-------------------------- retrieveCustomer --------------------------------
// --Function: retrieveCustomer
// --Param:
//	  --Existing ID is the ID of the customer to be retrieved
// --Post-condition:
//	  --If the customer exists in the table A pointer to the customer is 
//		returned. If the customer does not exist then nullptr is returned.
//----------------------------------------------------------------------------
Customer* HashTable::retrieveCustomer(const int& existingID)const
{
	unsigned int i = 0;
	bool done = false;
	Customer* temp = nullptr;

	while (!done && i < 9999)
	{ 
		unsigned long int iSquared = i * i;

		temp = customerTable[(iSquared + existingID) % ROWS][(iSquared + existingID) % COLUMNS];


	/*	int currentID = temp->getIDNum();*/

		if (temp != nullptr && temp->getIDNum() == existingID)
		{ //if ID's Match then we are done
			done = true;
		}

		i++;
	}

	return temp;

}

