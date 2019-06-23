//---------------------------- customer.cpp ---------------------------------
// --Ethan Thomas
//---------------------------------------------------------------------------

//--------------------------  class Customer  -------------------------------
// Purpose: 
//	 -- Customer class contains ID, first, and last name. Also,
//      customer keeps track of their borrowed and returned movies.
//
// Implementation and assumptions:
//   -- Implement with  a linked list 
//   -- Implement with following futures: 
//      newTransaciton, printHistory, getIDNum, getName, getfirstName,
//		getLastName, checkIfBorrowed.
//---------------------------------------------------------------------------

#include "customer.h"


//--------------------------- Default Constructor ---------------------------
// --Default Constructor:
// --Param: N/A
// --Post-condition: 
//	 --Sets ID to -1, lastName and firstName to en empty string.
//---------------------------------------------------------------------------
Customer::Customer()
{
	ID = -1;              		 // customer id
	lastName = "";               // customer last name
	firstName = "";
	head = nullptr;
}
//-------------------------- Constructor -----------------------------------
// --Constructor Overload:
// --Param : 		
//	  --newID is an Int >= 0 and < 10000 
//	  --first and last name are strings
// --Post-condition: 
//    --sets the customers ID, first name and last name according
//		to the parameters. Transaction log is initialized to nullptr.
//---------------------------------------------------------------------------

Customer::Customer(int newID, string newLastName, string newFirstName)
{
	if (newID < 0 || newID > 9999)
	{
		return;
	}
		
	ID = newID;              		// customer id
	lastName= newLastName;          // customer last name
	firstName = newFirstName;		// customer first name
	head = nullptr;					// transaction history doesn't exist yet
}


//------------------------------ Destructor ---------------------------------
// --Destructor:
// --Param: N/A
// --Post-condition: 
//	  --De-allocates memory used for Transaction Log.
//---------------------------------------------------------------------------
Customer::~Customer()
{										// delete history
	TransactionLog* current = head;		// temporary pointer
	while (current != nullptr)
	{									// traverse the entire LL
		head = head->next;				// set head to head next
		current->info = nullptr;		// set to null pointer
		delete current;					// delete the pointer
		current = head;					// set temp to head
	}
}

//--------------------------- newTransaction --------------------------------
// --Function: newTransaction
// --Param:
//	  --type is of type char representing the type of transaction.
//	  --theMovie is a movie from the inventory pointing to the 
//	    movie assocaited to customer transaction.
// --Post-condition:  
//	  --The transaction will be added to customer history.
//---------------------------------------------------------------------------
bool Customer::newTransaction(char type, Movie* theMovie) 
{

	TransactionLog* ptr = new TransactionLog(type, theMovie); // temp pointer
	if (type == 'B')
	{
		ptr->rented = true;
	}

	if (head == nullptr)		// If it is the first transaction
	{
		head = ptr;				// make temp pointer the new head
	}
	else					// If the customer has a history
	{
		ptr->next = head;		// Move head down
		head = ptr;				// Insert at the front of transaction history
	}	

	return true;				// Insertion complete
}

//------------------------ checkIfBorrowed ----------------------------------
// --Function: checkIfBorrowed
// --Param:			
//	  --char type is 'R'
//	  --theMovie is a pointer to the movie that the customer wishes to return.
// --Post-condition: 
//	  --Will return true if the movie is found in customer
//		history with rented marked true, false otherwise.
//---------------------------------------------------------------------------
bool Customer::checkIfBorrowed(Movie* theMovie)const
{
	TransactionLog* current = head;	// Temp pointer for transactionLog traversal
	bool foundItem = false;

	if (current == nullptr)			// If transactionLog is empty
	{
		return foundItem;				// The customer hasn't borrowed any movies
	}		

	while (current != nullptr)		// Traverse entire TransactionLog
	{
		if (current->transaction == 'B' && current->info == theMovie && current->rented == true)
		{
			current->rented = false;	// Movie has been borrowed, mark as returned
			foundItem = true;
			return foundItem;				// continue to adding to customer history
		}

		current = current->next;
	}
	return foundItem;
}

//----------------------------- printHistory --------------------------------
// --Function: printHistory
// --Param: N/A
// --Post-condition:
//	  --Prints the entire customer transaction history in order
//		of newest to oldest.
//---------------------------------------------------------------------------
void Customer::printHistory() const
{
	cout << "_____________________________________________________________________________" << endl << endl;
	cout << getName() << ": ID# " << getID() << endl << "Rental History: "<< endl;  //printing customer info

	TransactionLog* current = head;	// setting ptr to start of transaction history

	while (current != nullptr)		// Traverse entire transaction history
	{
		if (current->transaction == 'B')
		{ 
			cout<<("Borrowed " + current->info->createCustomerHistory())<<endl;
		}
		else 
		{
			cout<<("Returned " + current->info->createCustomerHistory())<<endl;
		}

		current = current->next;		//set current to next for next transaction
	}

	cout << "_____________________________________________________________________________" << endl << endl;
	cout << endl;

}

//------------------------------ getIDNum -----------------------------------
// --Function: getID
// --Param: N/A
// --Post-condition: 
//	  --Returns the int value of the customer's ID.
//---------------------------------------------------------------------------
int Customer::getIDNum()const
{
	return ID;
}

//------------------------------ getName -----------------------------------
// --Function: getName
// --Param: N/A
// --Post-condition:
//	  --returns the string value of the customers whole name.
//---------------------------------------------------------------------------
string Customer::getName()const
{
	return firstName + " " + lastName;
}

//---------------------------- getLastName ---------------------------------
// --Function: getLastName
// --Param: N/A
// --Post-condition:
//	  --Returns the string value of the customer's last name.
//---------------------------------------------------------------------------
string Customer::getLastName()const
{
	return lastName;
}

//---------------------------- getFirstName --------------------------------
// --Function: getFirstName
// --Param: N/A
// --Post-condition:
//	  --Returns the string value of the customer's first name.
//---------------------------------------------------------------------------
string Customer::getFirstName()const
{
	return firstName;
}

//------------------------------ getID --------------------------------------
// --Function: getID 
// --Param: N/A
// --Post-condition:
//	  --Formats the customer ID into a string so any leadng 0's 
//  	may also be printed to the output window.
//---------------------------------------------------------------------------
string Customer::getID()const
{
	string toString = "";

	if (ID > 999)				// If no leading 0's
	{
		toString = to_string(ID);
	}
	else if (ID % 1000 == ID)	// If 1 leading 0
	{
		toString = ("0" + to_string(ID));
	}
	else if (ID % 100 == ID)		// If 2 leading 0's
	{
		toString = ("00" + to_string(ID));
	}
	else if (ID % 10 == ID)		// If 3 leading 0's
	{
		toString = ("000" + to_string(ID));
	}
	
	return toString;
	
}
