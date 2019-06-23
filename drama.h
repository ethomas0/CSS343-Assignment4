//-------------------------------- drama.h ----------------------------------
// --Krystal Levin & Ethan Thomas
//---------------------------------------------------------------------------
#ifndef DRAMA_H
#define DRAMA_H
#include <string>
#include "movie.h"
#include <iostream>
#include <fstream>
using namespace std;
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
class Drama : public Movie
{
public:

	Drama(const string&);                            // constructor
	Drama(const string&, const string&);             // constructor 
	virtual ~Drama();                                // destructor

	static const char GENRE = 'D';                   // static indentifier for a class 

	virtual string createMovieInfo() const;               // virtual createMovieInfo
	virtual string createCustomerHistory() const;    // virtual createCustomerHistory
	

protected:

	bool operator==(const Movie* rhs) const;   // == operator
	bool operator!=(const Movie* rhs) const; // != operator
	bool operator>(const Movie* rhs) const; // greater than operator
	bool operator<(const Movie* rhs) const;  // less than operator 
};
#endif
