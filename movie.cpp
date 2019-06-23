//---------------------------------- movie.cpp -------------------------------
// --Krystal Levin & Ethan Thomas
//----------------------------------------------------------------------------

#include "movie.h"
#include <sstream>

//----------------------------- Construstor ----------------------------------
// 
//----------------------------------------------------------------------------
Movie::Movie()
{
	type = ' ';
	stock = 0;
	director = "";
	title = "";
	year = 0;
}


//------------------------ parseNloadString ----------------------------------
// --Helper method for constractor. 
// --Parses the string into a smaller pieces. From these pieces
//   assign inforamtion to a current movie.
//----------------------------------------------------------------------------
void Movie::parseNLoadString(const string& movieInfo)
{
	stringstream ss;                 // string reader
	ss << movieInfo;                      // insert string info into reader

	string temp;                     //  temp string to parse the string
	

	getline(ss, temp, ',');          // get movie type
	type = temp[0];                  // assign movie type
	getline(ss, temp, ',');          // get stock
	stringstream(temp) >> stock;  // assign stock // done this way since getline wants a string not int
	getline(ss, director, ',');      // assign director
	getline(ss, title, ',');         // assign title
	getline(ss, temp, ',');          // get year
	stringstream(temp) >> year;      // assign year // done this way since getline wants a string not int
}

//------------------------ increaseStock --------------------------------------
//  --Increase stock of current movievby one
//-----------------------------------------------------------------------------
bool Movie::increaseStock()
{	
	this->stock++;
	return true;		
}

//------------------------ getStock   ------------------------------------------
// --returns current stock of the movie
//------------------------------------------------------------------------------
int Movie::getStock() 
{
	return stock;
}

//-------------------------- decreaseStock  ------------------------------------
// --Decreases current stock of the movie.
// --If stock is less than or equal zero, stock will be the same and return false,
//	 else will return true after decreasing stock by one
//------------------------------------------------------------------------------
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
