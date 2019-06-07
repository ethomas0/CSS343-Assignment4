#include "moviefactory.h"

Movie * MovieFactory::createMovie(const string& commandLine)
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
		addToInventory = nullptr;                     // NULL
		break;
	}
	return addToInventory; // return movie
}
