//------------------------------ drama.cpp ----------------------------------
// --Krystal Levin & Ethan Thomas
//---------------------------------------------------------------------------

#include "drama.h"
#include <sstream>

//---------------------------- class Drama ----------------------------------
// Purpose:
//   -- Child class of Movie. Dramma Movie sorts
//      by director and title.
//
// Implementation and assumptions:
//   -- Implement as a child class of Movie
//   -- Implement with following futures:
//      createMovieInfo, createCustomerHistory, ==, !=, >, <
//---------------------------------------------------------------------------


//-------------------------- Constructor --------------------------------------
// --Uses helper function parseNLoadString
//-----------------------------------------------------------------------------
Drama::Drama(const string& movieInfo)
{
	parseNLoadString(movieInfo);
}

//---------------------------Constructor -------------------------------------
// 
//----------------------------------------------------------------------------
Drama::Drama(const string& releaseTitle, const string& releaseDir)
{
	this->title = releaseTitle;
	this->director = releaseDir;
}

//------------------------- Destructor ----------------------------------------
// 
//-----------------------------------------------------------------------------
Drama::~Drama()
{
	//empty on purpose
}

//----------------------------- createMovieInfo ------------------------------
// --Creates a formated string with all the movie info for output to console
//----------------------------------------------------------------------------
string Drama::createMovieInfo() const
{
	ostringstream movieInfo;

	movieInfo << setw(21) << left << director << setw(21) << left << title;
	movieInfo << setw(9) << right << year << setw(8) << right << stock << endl;

	return movieInfo.str();
}

//----------------------------- createCustomerHistory   ----------------------
// --Creates a formated string with all the movie info for customer history
//----------------------------------------------------------------------------
string Drama::createCustomerHistory() const
{
	ostringstream movieInfo;

	movieInfo << setw(10) << " Drama: " << director << " " << title;
	movieInfo << " " << year;

	return movieInfo.str();
}

//------------------------ operator== ----------------------------------------
// --Compares current object Movie with other object Movie.
// --Returns true if title and director are the same
//   else returns false.
//----------------------------------------------------------------------------
bool Drama::operator==(const Movie* rhs) const
{
	const Drama* rhsCopy = (const Drama*)rhs;

	return ((title == rhsCopy->title) && (director == rhsCopy->director));
}

//------------------------ operator!= ----------------------------------------
// --Compares current object Movie with other object Movie.
// --Returns true if title or director are not the same
//   else returns false.
//----------------------------------------------------------------------------
bool Drama::operator!=(const Movie* rhs) const
{
	return !(this == rhs);
}

//------------------------ operator> -----------------------------------------
// --Compares current object Movie with other object Movie.
// --Returns true if director is greater.
// --If director is the same, then checks title and returns true if greater.
// --Else returns false.
//----------------------------------------------------------------------------
bool Drama::operator>(const Movie* rhs) const
{
	const Drama* rhsCopy = (const Drama*)rhs;

	return ((director > rhsCopy->director) || ((director == rhsCopy->director) && (title > rhsCopy->title)));
}

//------------------------ operator< -----------------------------------------
// --Compares current object Movie with other object Movie.
// --Returns true if (this) does not equal rhs and is not greater than rhs.
// --Else it returns false.
//----------------------------------------------------------------------------
bool Drama::operator<(const Movie* rhs) const
{
	return ((this != rhs) && !(this > rhs));
}
