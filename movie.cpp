#include "movie.h"
#include <sstream>

//------------------------- Movie()-------------------------------------------
// --Constructor
//----------------------------------------------------------------------------
Movie::Movie()
{
	type = ' ';
	stock = 0;
	director = "";
	title = "";
	year = 0;
}

//-------------------------parseNloadString()---------------------------------
// --helper method for constractor. 
// --Parses the string into a smaller pieces. From these pieces
//   assign inforamtion to a current movie
//----------------------------------------------------------------------------
void Movie::parseNLoadString(const string& movieInfo)
{
	stringstream ss;                 // string reader
	ss << movieInfo;                      // insert string info into reader

	string temp;                     //  temp string to parse the string
	char delimiter = ',';			// delimiter

	getline(ss, temp, delimiter);          // get movie type
	type = temp[0];                  // assign movie type
	getline(ss, temp, delimiter);          // get stock
	stringstream(temp) >> stock;  // assign stock // done this way since getline wants a string not int
	getline(ss, director, delimiter);      // assign director
	getline(ss, title, delimiter);         // assign title
	getline(ss, temp, delimiter);          // get year
	stringstream(temp) >> year;      // assign year // done this way since getline wants a string not int
}

//-------------------------increaseStock()-------------------------------------
//  --increase stock of current movie
//    takes one parameter: int addStock
// --Returns true if stock was added
//   else returns false is stock number is negative
//-----------------------------------------------------------------------------
bool Movie::increaseStock(int addToStock)
{
	if (addToStock < 0)
	{ 
		return false; 
	}
	else
	{
		stock += addToStock;
		return true;
	}
	
}

//-------------------------getStock()-------------------------------------------
// --returns current stock of the movie
//------------------------------------------------------------------------------
int Movie::getStock() 
{
	return stock;
}

//---------------------------decreaseStock()------------------------------------
// --decreases current stock of the movie
// --if stock is less or equal zero, stock will be the same and return false,
//	 else will return true after decreasing stock by one
bool Movie::decreaseStock()
{
	if (stock <= 0) 
	{ 
		return false; 
	}
	else
	{
		stock--;    // dicrease sctock
		return true;
	}
	
}
