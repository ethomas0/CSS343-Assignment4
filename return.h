//--------------------------------- return.h --------------------------------
// --Krystal Levin & Ethan Thomas
//---------------------------------------------------------------------------

#ifndef RETURN_H
#define RETURN_H

#include "transaction.h"

//---------------------------------------------------------------------------
// Purpose:
//	 -- Return is a class for returning movies and is inherited 
//		from Transaction
//---------------------------------------------------------------------------

class Return :
	public Transaction
{
public:
	Return(const string&, CustomerManager&, InventoryManager&);	//constructor
	~Return();

	static const char CODE = 'R';		// Transaction code
};
#endif // !RETURN_H


