//------------------------------ return.cpp ---------------------------------
// --Krystal Levin & Ethan Thomas
//---------------------------------------------------------------------------

#include "return.h"

//---------------------------------------------------------------------------
// Purpose:
//	 -- Return is a class for returning movies and is inherited 
//		from Transaction
//---------------------------------------------------------------------------


 
//------------------------------- Constructor --------------------------------
// --Param:
//	  --commandLine is a string containing the transaction code
//		the customer ID, the type of movie (DVD) and the first
//		two sorting attributes of the movie to be returned
// --Post-condition:
//	  --executes the return function by retreiving the movie
//		from the InventoryManager and the customer borrowing
//		the movie from CustomerManager. If both the movie and
//		the customer exist  and the movie has been borrowed by
//		the customer then the movie is returned and the movie
//		stock is increased by 1.
//----------------------------------------------------------------------------
 Return::Return(const string& commandLine, CustomerManager& theCustomers, InventoryManager& theInventory)
{
	stringstream ss;
	ss << commandLine;	// inserting commandLine into 

	char code;
	int customerID;
	string movieType;

	ss >> code >> customerID >> movieType;			// getting values to use for processing

	string remainder(ss.str().substr(ss.tellg()));	// getting the rest for movie retreival

	Movie* moviePtr = theInventory.retrieveMovie(remainder);		// search inventory for movie

	if (moviePtr == nullptr) //if movie does not exist
	{	
		newError = "ERROR:   Sorry " + remainder + " could not be found in the inventory";
		return;
	}

	Customer* customer = theCustomers.getCustomer(customerID);	// search database for customer
	if (customer == nullptr) // if customer ID could not be found
	{	
		newError = "ERROR:   Sorry there are no customers with ID #" + to_string(customerID);
		return;
	}

	if (customer->checkIfBorrowed(moviePtr))
	{
		customer->newTransaction(CODE, moviePtr);
		moviePtr->increaseStock();
	}
	else if (remainder[1] == 'C') // just for Classic movies; stock for prefered choice was 0
	{
		Movie* altClassic = nullptr;
		altClassic = theInventory.classicRetrieve(moviePtr); // check if Store has same movie, but different major actor

		if (altClassic != nullptr && customer->checkIfBorrowed(altClassic)) // check if movie exsists and stock > 0
		{
			customer->newTransaction(CODE, altClassic); // send transaction to customerHistory
			altClassic->increaseStock();
		}
		else
		{
			newError = "ERROR:   The customer " + customer->getName() +" ID:" + to_string(customerID) + " did not borrow " + remainder;
		}		
	}	
	else // customer never borrrowed movie
	{
		newError = "ERROR:   The customer " + customer->getName() +" ID:" + to_string(customerID) + " did not borrow " + remainder;
	}
		

}

//------------------------------ Destructor ----------------------------------
//
//----------------------------------------------------------------------------
Return::~Return()
{
	//empty on purpose
}
