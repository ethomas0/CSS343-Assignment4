#include "classics.h"
#include <sstream>

//------------------------------ ~Classics()----------------------------------
// --Destructor
//----------------------------------------------------------------------------
Classics::~Classics()
{
}

//------------------------Classics(const string&)-----------------------------
// --Constructor
// --Uses helper method parseNLoadString()
//----------------------------------------------------------------------------
Classics::Classics(const string& movieInfo)
{
	parseNLoadString(movieInfo);
}

//------------------------Classics(const string&)-----------------------------
// --Copy Constructor
//----------------------------------------------------------------------------
Classics::Classics(const string& actor, const int& releaseMonth, const int& releaseYear)
{
	this->majorActor = actor;
	this->month = releaseMonth;
	this->year = releaseYear;
}

//------------------------------createMovieInfo()-----------------------------
// --Creates a formated string with all the movie info for output to console
//----------------------------------------------------------------------------
string Classics::createMovieInfo() const
{
	ostringstream movieInfo;

	movieInfo << " " << setw(7) << left << month << setw(6) << left << year <<
		setw(18) << left << majorActor << setw(23) << left <<
		title << setw(17) << left << director << setw(5) << left << stock << endl;

	return  movieInfo.str();
}

//------------------------------createCustomerHistory()-----------------------
// --Creates a formated string with all the movie info for customer history
//----------------------------------------------------------------------------
string Classics::createCustomerHistory() const
{
	ostringstream movieInfo;

	movieInfo << " classic: " << month << " " << year << ' ' << majorActor << title << director;

	return  movieInfo.str();
}

//-------------------------parseNloadString()---------------------------------
// --helper method for constractor. 
// --Parses the string into a smaller pieces. From these pieces
//   assign inforamtion to a current movie
//----------------------------------------------------------------------------
void Classics::parseNLoadString(const string& movieInfo)
{
	stringstream ss;
	ss << movieInfo;

	string temp;                 // hold sub string from info string
	char delimiter = ',';        //delimiter

	getline(ss, temp, delimiter);      // get type of movie (char)
	type = temp[0];
	getline(ss, temp, delimiter);      // get stock number (int)
	stringstream(temp) >> stock;
	getline(ss, director, delimiter);  // get director string
	getline(ss, title, delimiter);     // get title string
	ss >> temp;                  // add second name to first name
	majorActor += temp;
	majorActor += ' ';
	ss >> temp;                 // add second name to first name
	majorActor += temp;
	ss >> month;                // add month
	ss >> year;                 // add month
}

//-------------------------operator==----------------------------------------
// --compares current object Movie with other object Movie
// --Returns true if majorActor, year, and month are the same
//   else returns false
//----------------------------------------------------------------------------
bool Classics::operator==(const Movie* rhs) const
{
	const Classics* rhsCopy = (const Classics*) rhs;

	return ((majorActor == rhsCopy->majorActor) && (year == rhsCopy->year) && (month == rhsCopy->month));
}

//-------------------------operator!=----------------------------------------
// --compares current object Movie with other object Movie
// --Returns true if majorActor, year, or month are not the same
//   else returns false
//----------------------------------------------------------------------------
bool Classics::operator!=(const Movie* rhs) const
{
	return !(this == rhs);
}

//-------------------------operator>-----------------------------------------
// --compares current object Movie with other object Movie
// --Returns true if year is greater.
// --If year is the same, then checks month and returns true if greater
// --If year and month are the same, then checks majorActor and returns true
//   if greater 
// --Else returns false
//----------------------------------------------------------------------------
bool Classics::operator>(const Movie * rhs) const
{
	const Classics*  rhsCopy = (const Classics*)rhs;

	return ((year > rhsCopy->year) || ((year == rhsCopy->year) && (month > rhsCopy->month))
		|| ((year == rhsCopy->year) && (month == rhsCopy->month) && (majorActor > rhsCopy->majorActor)));
}

//-------------------------operator<-----------------------------------------
// --compares current object Movie with other object Movie
// --Returns true if (this) does not equal rhs and is not greater than rhs
//   else it returns false
//----------------------------------------------------------------------------
bool Classics::operator<(const Movie * rhs) const
{
	return ((this != rhs) && !(this > rhs));
}
