//---------------------------- moviefactory.cpp -----------------------------
// --Krystal Levin & Ethan Thomas
//---------------------------------------------------------------------------

#include "moviefactory.h"
//--------------------------  class MovieFactory ----------------------------
// Purpose: 
//   -- MovieFactory class uses factory method pattern to create
//      new moive form input string.
//
// Implementation and assumptions:
//   -- Implement as factory method
//   -- Implement with following futures:
//      static poitner to the Movie createMovie
//---------------------------------------------------------------------------

//----------------------------- createMovie ---------------------------------
// --Creates a new movie based on genre (commandLine[0]) using factory
//	 factory method
//---------------------------------------------------------------------------
Movie* MovieFactory::createMovie(const string& commandLine)
{
	Movie*  addToInventory = nullptr;               //  pointer to movie
	switch (commandLine[0])    // get first character of  string array
	{
	case Drama::GENRE:
		addToInventory = (Movie*) new Drama(commandLine);  // create Drama
		break;
	case Comedy::GENRE:
		addToInventory = (Movie*) new Comedy(commandLine);  // create Comedy
		break;
	case Classics::GENRE:
		addToInventory = (Movie*) new Classics(commandLine); // create Classics
		break;
	default:
		break;
	}
	return addToInventory; // return movie
}
