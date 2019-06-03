#include "drama.h"
#include <sstream>

//--------------------------Drama()--------------------------------------------
// --Constructor
//-----------------------------------------------------------------------------
Drama::Drama(const string& movieInfo)
{
	parseNLoadString(movieInfo);
}

//------------------Drama(const string&, const int&)--------------------------
// --Copy constractor
//----------------------------------------------------------------------------
Drama::Drama(const string& releaseTitle, const int& releaseYear)
{
	this->title = releaseTitle;
	this->year = releaseYear;
}

//------------------------- ~Drama()------------------------------------------
// --Destructor
//-----------------------------------------------------------------------------
Drama::~Drama()
{
}

//------------------------------createMovieInfo()-----------------------------
// --Creates a formated string with all the movie info for output to console
//----------------------------------------------------------------------------
string Drama::createMoveInfo() const
{
	ostringstream movieInfo;

	movieInfo << setw(21) << left << director << setw(21) << left << title;
	movieInfo << setw(9) << right << year << setw(8) << right << stock << endl;

	return movieInfo.str();
}

//------------------------------createCustomerHistory()-----------------------
// --Creates a formated string with all the movie info for customer history
//----------------------------------------------------------------------------
string Drama::createCustomerHistory() const
{
	ostringstream movieInfo;

	movieInfo << " drama: " << director << " " << title;
	movieInfo << " " << year;

	return movieInfo.str();
}

//-------------------------operator==----------------------------------------
// --Compares current object Movie with other object Movie
// --Returns true if title and director are the same
//   else returns false
//----------------------------------------------------------------------------
bool Drama::operator==(const Movie* rhs) const
{
	const Drama* rhsCopy = (const Drama*)rhs;

	return ((title == rhsCopy->title) && (director == rhsCopy->director));
}

//-------------------------operator!=----------------------------------------
// --Compares current object Movie with other object Movie
// --Returns true if title or director are not the same
//   else returns false
//----------------------------------------------------------------------------
bool Drama::operator!=(const Movie* rhs) const
{
	return !(this == rhs);
}

//-------------------------operator>-----------------------------------------
// --Compares current object Movie with other object Movie
// --Returns true if director is greater.
// --If director is the same, then checks title and returns true if greater
// --Else returns false
//----------------------------------------------------------------------------
bool Drama::operator>(const Movie* rhs) const
{
	const Drama* rhsCopy = (const Drama*)rhs;

	return ((director > rhsCopy->director) || ((director == rhsCopy->director) && (title > rhsCopy->title)));
}

//-------------------------operator<-----------------------------------------
// --Compares current object Movie with other object Movie
// --Returns true if (this) does not equal rhs and is not greater than rhs
//   else it returns false
//----------------------------------------------------------------------------
bool Drama::operator<(const Movie* rhs) const
{
	return ((this != rhs) && !(this > rhs));
}
