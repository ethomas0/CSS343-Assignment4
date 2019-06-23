//---------------------------- borrow.h -------------------------------------
// --Krystal Levin & Ethan Thomas
//---------------------------------------------------------------------------

//--------------------------  class Borrow ----------------------------------
// Purpose: 
//	 -- Child class of Transaction. Borrows movie for customer
//		and updates the InventoryManager
//
// Implementation and assumptions:
//   -- Implement as a child class of Transaction
//   -- Implement with following futures:
//      Borrow (as Borrow is constructed it also creates the transaction or
//		error code depending on situation)
//---------------------------------------------------------------------------

#include "borrow.h"


// -------------------------- Constructor -------------------------------------
//	Param : 		 
//	  -- CommandLine is a string containing the transaction code
//		 the customer ID, the type of movie (DVD) and the first
//		 two sorting attributes of the movie to be borrowed.
//	Post
//	  -- Condition: executes the borrow function retreiving the movie 
//		 from the InventoryManager and the customer borrowing
//		 the movie from CustomerManager. If both the movie and
//		 the customer exist then the movie is checked out and
//		 the movie stock is decreased by 1.
//-----------------------------------------------------------------------------
Borrow::Borrow(const string& commandLine, CustomerManager& theCustomers, InventoryManager& theInventory)
{
	char code;
	int customerID;
	string movieType;
	stringstream ss;
	

	ss << commandLine;								// getting command line for manipulation	
	ss >> code >> customerID >> movieType;			// extracting needed information

	string remainder(ss.str().substr(ss.tellg()));	// getting the remaining information
	

	Movie* moviePtr = theInventory.retrieveMovie(remainder); // checking if in inventory



	if (moviePtr == nullptr)					// if not in inventorys end to error collection
	{ 
		newError= "ERROR:   Sorry " + remainder + " could not be found in the inventory";
		return;
	}

	Customer* customer = theCustomers.getCustomer(customerID); // check if customer exists 

	if (customer == nullptr)				// if not in inventory send to error collection
	{ 
		newError = "ERROR:   Sorry there are no customers with ID #" + to_string(customerID);
		return; 
	}



	//both customer and the movie exist in store databases
	if (moviePtr->decreaseStock()) // check if stock > 0
	{
		customer->newTransaction(CODE, moviePtr);	// send transaction to customerHistory
	}
	else if (remainder[1] == 'C') // just for Classic movies; stock for prefered choice was 0
	{
		Movie* altClassic = nullptr;
		altClassic = theInventory.classicRetrieve(moviePtr); // check if Store has same movie, but different major actor

		if(altClassic != nullptr && altClassic->decreaseStock()) // check if movie exsists and stock > 0
		{
			customer->newTransaction(CODE, altClassic); // send transaction to customerHistory
		}
		else
		{
			newError = "ERROR:   Customer " + customer->getName()+ " ID: " + customer->getID() + ": Sorry" + remainder + "  stock was 0";
			return;
		}
	}
	else 
	{

		newError = "ERROR: Customer " + customer->getName() + " ID: " + customer->getID() + ": Sorry" + remainder +  " the stock was 0";
	}

}

// ---------------------------- Destructor ------------------------------------
// 
//-----------------------------------------------------------------------------
Borrow::~Borrow()
{
	//empty on purpose
}
