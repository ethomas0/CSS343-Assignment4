#pragma once
#include "transaction.h"
#include "customerManager.h"
#include "customer.h"

class Borrow : public Transaction
{
public:

	Borrow();							// constructor
	~Borrow();							// destructor

	virtual void processCommands(char, ifstream&); // process Transaction

};


