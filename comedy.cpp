#include "comedy.h"
//-------------------------Comedy()--------------------------------------------
// --Constructor
//-----------------------------------------------------------------------------
Comedy::Comedy(const string& movieInfo)
{
	parseNLoadString(movieInfo);
}

//-----------------Comedy(const string&, const int&)--------------------------
// --Copy constractor
//----------------------------------------------------------------------------
Comedy::Comedy(const string& releaseTitle, const int& releaseYear)
{
	this->title = releaseTitle;
	this->year = releaseYear;
}

//------------------------- ~Comedy()------------------------------------------
// --Destructor
//-----------------------------------------------------------------------------
Comedy::~Comedy() 
{

}

//-------------------------operator==----------------------------------------
// --Compares current object Movie with other object Movie
// --Returns true if title and year are the same
//   else returns false
//----------------------------------------------------------------------------
bool Comedy::operator==(const Movie* rhs) const
{
	const Comedy* rhsCopy = (const Comedy*)rhs;
	return ((title == rhsCopy->title) && (year == rhsCopy->year));
}

//-------------------------operator!=----------------------------------------
// --Compares current object Movie with other object Movie
// --Returns true if title or year are not the same
//   else returns false
//----------------------------------------------------------------------------
bool Comedy::operator!=(const Movie* rhs) const
{
	return !(this == rhs);
}

//-------------------------operator>-----------------------------------------
// --Compares current object Movie with other object Movie
// --Returns true if title is greater.
// --If title is the same, then checks year and returns true if greater
// --Else returns false
//----------------------------------------------------------------------------
bool Comedy::operator>(const Movie* rhs) const
{
	const Comedy* rhsCopy = (const Comedy*)rhs;
	return ((title > rhsCopy->title) || ((title == rhsCopy->title) && (year > rhsCopy->year)));
}

//-------------------------operator<-----------------------------------------
// --Compares current object Movie with other object Movie
// --Returns true if (this) does not equal rhs and is not greater than rhs
//   else it returns false
//----------------------------------------------------------------------------
bool Comedy::operator<(const Movie* rhs) const
{
	return ((this != rhs) && !(this > rhs));
}

//------------------------------createMovieInfo()-----------------------------
// --Creates a formated string with all the movie info for output to console
//----------------------------------------------------------------------------
string Comedy::createMoveInfo() const 
{
	ostringstream movieInfo;

	movieInfo << setw(33) << left << title << setw(1) << right << year
		<< setw(20) << left << director << setw(20) << left << stock << endl;

	return movieInfo.str();
}

//------------------------------createCustomerHistory()-----------------------
// --Creates a formated string with all the movie info for customer history
//----------------------------------------------------------------------------
string Comedy::createCustomerHistory() const
{
	ostringstream movieInfo;

	movieInfo << " comedy: " << title << " " << director
		<< " " << year;;

	return movieInfo.str();
}
