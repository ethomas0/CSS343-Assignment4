//------------------------------- history.cpp -------------------------------
// --Krystal Levin & Ethan Thomas
//---------------------------------------------------------------------------

#include "history.h"

//----------------------------- class History -------------------------------
// Purpose:
//	 -- History is a class for viewing customer transaction history
//	    and is inherited from Transaction
//---------------------------------------------------------------------------


 
 //------------------------------- Constructor --------------------------------
//
// --Param:
//	  --commandLine is a string containing the transaction code,
//		the customer ID, the type of movie (DVD) and the first
//		two sorting attributes of the movie to be borrowed.
// --Post-condition: 
//	  --If the customer exists in the customer database then their transaction
//		history is printed
//----------------------------------------------------------------------------
 History::History(const string& commandLine, CustomerManager& theCustomers, InventoryManager& theInventory)
{
	char code;
	int customer_id;				// hold customer id
	Customer * customer = nullptr;	// hold pointer to the object customer

	stringstream ss;				   // string reader
	ss << commandLine;                 // insert string into reader

	ss >> code >> customer_id;		// extract the code and the customer ID
	customer = theCustomers.getCustomer(customer_id);     // get pointer to the customer

	if (customer == nullptr)		// check if customer exist
	{	
		newError = "ERROR:   " + to_string(customer_id) + " is not in the customer Database";
	}
	else
	{
		customer->printHistory();   // if so, print customer history
	}	
}

 //------------------------------- Destructor ---------------------------------
 //
 //----------------------------------------------------------------------------
History::~History()
{
	//empty on purpose
}
