//-------------------------- customermanager.cpp -----------------------------
// --Krystal Levin & Ethan Thomas
//----------------------------------------------------------------------------



#include "customermanager.h"
//-------------------------- class CustomerManager ---------------------------
// Purpose:
//	 --CustomerManager proccess customers: puts customers 
//     into HashTble. CustomerManager can also retrieve the customer.
//
// Implementation and assumptions:
//   -- Implement as manager class
//   -- Implement with following futures: 
//      proccessCustomer(), getCustomer()
//---------------------------------------------------------------------------


//-------------------------- Default Constructor ----------------------------
//
//---------------------------------------------------------------------------
CustomerManager::CustomerManager()
{
	//empty on purpose
}

//----------------------------- Destructor ----------------------------------
//
//---------------------------------------------------------------------------
CustomerManager::~CustomerManager()
{
	//empty on purpose
}

//--------------------------- processCustomers -------------------------------
// --Function: processCustomers
// --Param:
//	  --customerFile is a valid file of customer data where each
//		line is in the format: int ID, string LastName, string firstName
//
// --Post-condition:
//	  --Creates customer objects with the specified data and adds them to 
//		the customer Database (i.e the HashTable : tableOfCustomers)
//----------------------------------------------------------------------------
void CustomerManager::proccessCustomers(ifstream& customerFile)
{
	int fileID;
	string lastName, firstName;

	while(!customerFile.eof())		// until end of file
	{	
		customerFile >> fileID >> lastName >> firstName;	// get Info

		//Then add to storage:
		customerStorage.addCustomerToHash(new Customer(fileID, lastName, firstName));
		
	}

}

//------------------------------ getCustomer ----------------------------------
// --Function: getCustomer retreives the customer from the customerStorage 
//			   hash table
// --Param:
//	  --int is the ID of the customer wished to be retreived
// --Post-condition:
//	  --Returns a pointer to the customer in customerStorage
//----------------------------------------------------------------------------
Customer* CustomerManager::getCustomer(int existingID)
{

	//search customer storage for the customer pointer
	return customerStorage.retrieveCustomer(existingID); 
}
