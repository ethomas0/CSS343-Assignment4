//---------------------------inventorymanager.cpp-------------------------------
// Purpose: 
//   --Read given file then sort and insert
//     movies to a spacific BSTrees (Drama,Classiscs, Comedy). 
//     Also, displays all BTrees and keep track of invalid movies. 
//------------------------------------------------------------------------------

#include "inventorymanager.h"
//---------------------------processInventory-----------------------------------
// --Process inventory commands from file (infile).
// --Uses factory method (MovieFactory) to create pointer object to Movie.
//------------------------------------------------------------------------------
void InventoryManager::processInventory(ifstream& infile)
{
	string commandLine;                                     // hold movie information

	for (;;) 
	{

		getline(infile, commandLine);                       // inser info into string
		if (infile.eof()) break;                  // no more lines of data

		Movie* a = MovieFactory::createMovie(commandLine);  // pointer to the object movie

		switch (commandLine[0])                             // check what object type to insert curent movie
		{
		case Drama::GENRE:
			dramaBST.insert(a);             // insert Drama movie
			break;
		case Comedy::GENRE:
			comedyBST.insert(a);            // insert Comedy movie
			break;
		case  Classics::GENRE:
			classicsBST.insert(a);          // insert Classics movie
			break;
		default:
			addError(commandLine);         // add unkown movie (error)
			break;
		}
	}
	//displayErrors(); // display errors 
}

//---------------------------retireveMovie--------------------------------------
// --Retrieves movie from appropriate BST.
//------------------------------------------------------------------------------
Movie* InventoryManager::retriveMovie(Movie* movieData, const char& genre)
{
	switch (genre)
	{
	case 'D':
		return dramaBST.retrieve(movieData);
		break;
	case 'F':
		return comedyBST.retrieve(movieData);
		break;
	case 'C':
		return classicsBST.retrieve(movieData);
		break;
	default:
		return nullptr;
		break;
	}
	
}

//---------------------------displayAll-----------------------------------------
// --Displays all BSTs (e.g. Comedies, Dramas, Classics).
//------------------------------------------------------------------------------
void InventoryManager::displayAll()
{
	cout << endl;
	cout << "_____________________________________________________________________________" << endl << endl;
	cout << "                                Display Comedies " << endl;
	cout << "_____________________________________________________________________________" << endl;
	cout << " Title                           Year Director          Stock" << endl;
	comedyBST.displayAll();

	cout <<  "_____________________________________________________________________________" << endl << endl;
	cout << "                                Display Dramas " << endl;
	cout <<  "_____________________________________________________________________________" << endl;
	cout << " Director             Title                    Year     Stock" << endl;
	dramaBST.displayAll();

	cout << "_____________________________________________________________________________" << endl << endl;;
	cout << "                                Display Classics " << endl;
	cout << "_____________________________________________________________________________" << endl;
	cout << " Month  Year  Major actor        Title                  Director       Stock" << endl;
	classicsBST.displayAll();

	cout << "_____________________________________________________________________________" << endl;
	cout << endl << endl;
}

//---------------------------addError-------------------------------------------
// --Collects errors that have been detected while attempting to create movie(s).
//------------------------------------------------------------------------------
void InventoryManager::addError(string error)
{
	string temp = "  ";
	temp += error;
	errorCollection.push_back(temp);
	
}

//---------------------------displayError---------------------------------------
// --Displays all errors found while attempting to create movie(s).
//------------------------------------------------------------------------------
void InventoryManager::displayErrors() const
{
	cout << endl;
	cout << "_____________________________________________________________________________" << endl << endl;
	cout << "                                Invalid movie report" << endl << endl;

	for (int i = 0; i < errorCollection.size(); i++)
	{
		cout << errorCollection[i] << "\n";
	}

	cout << endl;
	cout << "_____________________________________________________________________________" << endl;
}
