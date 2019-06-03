#ifndef DRAMA_H
#define DRAMA_H
#include <string>
#include "movie.h"
#include <iostream>
#include <fstream>
using namespace std;
//----------------------------class Drama --------------------------------
// ADT Drama: child class of Movie. Dramma Movie sorts
// by director and title.
//
// Implementation and assumptions:
//   -- Implement as a child class of Movie
//   -- Implement with following futures:
//      createMovieInfo(), ==, !=, >, <
//---------------------------------------------------------------------------
class Drama : public Movie
{
public:

	Drama(const string&);                            // constructor
	Drama(const string&, const int&);                // copy constructor
	virtual ~Drama();                                // destructor

	static const char GENRE = 'F';                   // static indentifier for a class 

	virtual string createMoveInfo() const;               // virtual createMovieInfo
	virtual string createCustomerHistory() const;    // virtual createCustomerHistory

protected:

	bool operator==(const Movie* rhs) const;   // == operator
	bool operator!=(const Movie* rhs) const; // != operator
	bool operator>(const Movie* rhs) const; // greater than operator
	bool operator<(const Movie* rhs) const;  // less than operator 
};
#endif
