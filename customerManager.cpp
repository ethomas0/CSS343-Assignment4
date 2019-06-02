#include "customerManager.h"



CustomerManager::CustomerManager()
{
}


CustomerManager::~CustomerManager()
{
}

//----------------------------------------------------------------------------
//--------------------------- Utility Functions ------------------------------
//----------------------------------------------------------------------------
/*****************************************************************************
 * Function: processCustomers
 * @Param : 		 customerFile is a valid file of customer data where each 
 *					 line is in the format: 
 *						int ID, string LastName, string firstName
 *
 * @Post-condition:  Creates customer objects with the specified data and
 *					 adds them to the customer Database
 *					 (i.e the HashTable: tableOfCustomers)
*****************************************************************************/
void CustomerManager::proccessCustomers(ifstream& customerFile) {
	int fileID;
	string lastName, firstName;

	while(!customerFile.eof()){
		customerFile >> fileID >> lastName >> firstName;
		
		customerStorage.addCustomertoHash(new Customer(fileID, lastName, firstName));
		
	}

}
