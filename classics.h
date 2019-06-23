//---------------------------- classics.h -----------------------------------
// --Krystal Levin & Ethan Thomas
//---------------------------------------------------------------------------

#ifndef CLASSICS_H
#define CLASSICS_H
#include <string>
#include "movie.h"
using namespace std;
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
class Classics : public Movie
{
public:

	~Classics();										// destructor
	Classics(const string&);                            // constructor
	Classics(const string&, const int&, const int&);    // constructor

	virtual string createMovieInfo() const;            // returns string of formated movie info
	virtual string createCustomerHistory() const;    // returns string of movie info for customer transactions
	//string getMajorActor()const;

	static const char GENRE = 'C';                   // static identifier for the class
	bool isEqual(const Movie* rhs)const;		// used for alterante classic movie with same title, month, and year, but different title


protected:

	void parseNLoadString(const string& movieInfo);     // helper method for constractor
	bool operator==(const Movie* rhs) const;			// equal comparison operator
	bool operator!=(const Movie* rhs) const;			// not equal comparison operator
	bool operator>(const Movie* rhs) const;				// greater than operator
	bool operator<(const Movie* rh) const;				// less than operator 

	int month;                                          // hold month                                
	string majorActor;                                  // hold major actor
};
#endif
