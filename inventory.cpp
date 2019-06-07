/*
 * Inventory Class Implementation File  @file inventory.cpp
 *
 * Inventory is inherited from Transaction
 *
 * Inventory prints out the entire Inventory of the store.
 *
 * @Author: 	Krystle S Levin -kslevin@uw.edu
 *				Ethan Thomas	-
 *
 * @Purpose:	Course Assignment 4 for CSS 343
 *				i.e. Data Structures, Algorithms and Discrete Mathematics
 *
 * @Created on:	June 2, 2019
 * @last Modification:	June 6, 2019
 *
 */
#include "inventory.h"

Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}
/*****************************************************************************
 * Function:	processCommands
 * @Param : 		 The command type has already been extracted from the file
 *					 There is no more data in the rest of the file line
 *
 * @Post-condition:  The entire store inventory will be printed.
*****************************************************************************/
void Inventory::processCommands(char type, ifstream& commandFile) {
	theShelves.displayAll();

}