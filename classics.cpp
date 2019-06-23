//--------------------------- classics.cpp ----------------------------------
// --Krystal Levin & Ethan Thomas
//---------------------------------------------------------------------------


//--------------------------  class Classics --------------------------------
// Purpose:
//   -- child class of Movie. Classical movie has extra info:
//      month and majorActor. Also, classical movie sort by majoractor, month,
//      and year.
//
// Implementation and assumptions:
//   -- Implement as a child class of Movie
//   -- Implement with following futures:
//      createMovieInfo, createCustomerHistory,
//		==, !=, >, <, and isEqual 
//   -- Assumption: each Classics movie that has same director, same
//      title, same year and month, but has different Major will be 
//      considirate as a different Classic movie.
//----------------------------------------------------------------------------

#include "classics.h"
#include <sstream>

//------------------------------ Destructor ----------------------------------
//
//----------------------------------------------------------------------------
Classics::~Classics()
{
	//empty on purpose
}

//----------------------- Constructor ----------------------------------------
// --Constructor
//----------------------------------------------------------------------------
Classics::Classics(const string& actor, const int& releaseMonth, const int& releaseYear)
{
	this->majorActor = actor;
	this->month = releaseMonth;
	this->year = releaseYear;
}

//------------------------ Constructor ---------------------------------------
// --Constructor
// --Uses helper method parseNLoadString()
//----------------------------------------------------------------------------
Classics::Classics(const string& movieInfo)
{
	parseNLoadString(movieInfo);
}

//------------------------- parseNloadString ---------------------------------
// --Helper method for constractor. 
// --Parses the string into a smaller pieces. From these pieces
//   assign inforamtion to a current movie.
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


//------------------------------ createMovieInfo -----------------------------
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

//------------------------------ createCustomerHistory -----------------------
// --Creates a formated string with all the movie info for customer history
//----------------------------------------------------------------------------
string Classics::createCustomerHistory() const
{
	ostringstream movieInfo;

	movieInfo << setw(10) << " Classic:  " << month << " " << year << ' ' << majorActor << title << director;

	return  movieInfo.str();
}


//--------------------------------- isEqual ----------------------------------
// --Only used in BinTree if a customer is trying to borrow a Classic and the 
//   stock is zero. Will then try and find alternate Classic that has same
//   title, month, and year, but not same major actor.
//----------------------------------------------------------------------------
bool Classics::isEqual(const Movie* rhs) const
{
	const Classics* rhsCopy = (const Classics*)rhs;
	return ((title == rhsCopy->title) && (year == rhsCopy->year) && (month == rhsCopy->month) && majorActor != rhsCopy->majorActor);
}


//------------------------ operator== ---------------------------------------
// --Compares current object Movie with other object Movie.
// --Returns true if majorActor, year, and month are the same
//   else returns false.
//----------------------------------------------------------------------------
bool Classics::operator==(const Movie* rhs) const
{
	const Classics* rhsCopy = (const Classics*)rhs;
	return ((majorActor == rhsCopy->majorActor) && (year == rhsCopy->year) && (month == rhsCopy->month));
	
}

	

//------------------------ operator!= ---------------------------------------
// --Compares current object Movie with other object Movie.
// --Returns true if majorActor, year, or month are not the same
//   else returns false.
//----------------------------------------------------------------------------
bool Classics::operator!=(const Movie* rhs) const
{
	return !(this == rhs);
}

//------------------------ operator> ----------------------------------------
// --Compares current object Movie with other object Movie.
// --Returns true if year is greater.
// --If year is the same, then checks month and returns true if greater.
// --If year and month are the same, then checks majorActor and returns true
//   if greater.
// --Else returns false.
//----------------------------------------------------------------------------
bool Classics::operator>(const Movie * rhs) const
{
	const Classics*  rhsCopy = (const Classics*)rhs;

	return ((year > rhsCopy->year) || ((year == rhsCopy->year) && (month > rhsCopy->month))
		|| ((year == rhsCopy->year) && (month == rhsCopy->month) && (majorActor > rhsCopy->majorActor)));
}

//------------------------ operator< ----------------------------------------
// --Compares current object Movie with other object Movie.
// --Returns true if (this) does not equal rhs and is not greater than rhs
//   else it returns false.
//----------------------------------------------------------------------------
bool Classics::operator<(const Movie * rhs) const
{
	return ((this != rhs) && !(this > rhs));
}
