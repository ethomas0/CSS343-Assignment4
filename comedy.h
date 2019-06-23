//---------------------------- comedy.h ------------------------------------
// --Krystal Levin & Ethan Thomas
//--------------------------------------------------------------------------

#ifndef COMEDY_H
#define COMEDY_H
#include <string>
#include "movie.h"
using namespace std;
//---------------------------- Class Comedy --------------------------------
// Purpose:
//   -- Child class of Movie. Comedy Movie sorts by
//      title and year.
//
// Implementation and assumptions:
//   -- Implement as a child class of Movie.
//   -- Implement with following futures:
//      createMovieInfo, createCustomerHistory, ==, !=, >, <
//---------------------------------------------------------------------------
class Comedy: public Movie
{
public:

	Comedy(const string&);                            // constructor
	Comedy(const string&, const int&);                // constructor
	virtual ~Comedy();                                // destructor

	static const char GENRE = 'F';                   // static indentifier for a class 

	virtual string createMovieInfo() const;           // creates a formated string of movie info for output
	virtual string createCustomerHistory() const;    // creates a string of movie info for customer transaction history
	
	
	
protected:

	virtual bool operator==(const Movie* rhs) const; 
	virtual bool operator!=(const Movie* rhs) const;
	virtual bool operator>(const Movie* rhs) const;    
	virtual bool operator<(const Movie* rhs) const;

};
#endif
