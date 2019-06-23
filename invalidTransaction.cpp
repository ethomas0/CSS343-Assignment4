/*
 * Invalid Transaction Class Implementation File  @file invalidTransaction.cpp
 *
 * Inventory is a class for handeling invalid transactions
 * and is inherited from Transaction
 *
 * @Author: 	Krystle S Levin -kslevin@uw.edu
 *				Ethan Thomas
 * @Purpose:	Course Assignment 4 for CSS 343
 *				i.e. Data Structures, Algorithms and Discrete Mathematics
 *
 * @Created on:	June 2, 2019
 * @last Modification:	June 10, 2019
 *
 */
//----------------------------- invalidTransaction.cpp ------------------------
// --Krystal Levin & Ethan Thomas
//-----------------------------------------------------------------------------

#include "invalidTransaction.h"

 //--------------------------- class InvalidTransaction -----------------------
 // Purpose
 //	 -- Inventory is a class for handeling invalid transactions and is 
 //		inherited from Transaction
 //----------------------------------------------------------------------------


//------------------------------- Constructor --------------------------------
// --Param:
//	  --commandLine is a string containing the transaction code 'x'
// --Post-condition:
//	  --Reports invalid transaction to the output.
//----------------------------------------------------------------------------
 InvalidTransaction::InvalidTransaction(const string& commandLine)
{
	if (commandLine != "")
	{
		newError = "ERROR:   " + commandLine + " is an invalid transaction";
	}
	
}

 //---------------------------- Destructor ------------------------------------
 //
 //----------------------------------------------------------------------------
InvalidTransaction::~InvalidTransaction()
{
	//empty on purpose
}
