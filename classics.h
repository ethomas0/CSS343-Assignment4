#ifndef CLASSICS_H
#define CLASSICS_H
#include <string>
#include "movie.h"
using namespace std;
//--------------------------  class Classics --------------------------------
// ADT Classics: child class of Movie. Classical movie has extra info:
// month and majorActor. Also, classical movie sort by majoractor, month,
// and year.
//
// Implementation and assumptions:
//   -- Implement as a child class of Movie
// -- Implement with following futures:
//      createMovieInfo(), ==, !=, >, <
//   -- Assumption: each Classics movie that has same director, same
//      title, same year and month, but has different Major will be 
//      considirate as a diffrent  classic movie.
//---------------------------------------------------------------------------
class Classics : public Movie
{
public:

	~Classics();                                // destructor
	Classics(const string&);                            // constructor
	Classics(const string&, const int&, const int&);    // copy constructor

	virtual string createMovieInfo() const;               //  virtual createMovieInfo
	virtual string createCustomerHistory() const;    // virtual createCutomerHistory

	static const char GENRE = 'C';                   // static identifier for the class


protected:

	void parseNLoadString(const string& movieInfo);     // helper method for copy constractor
	bool operator==(const Movie* rhs) const;   // equal comparison operator
	bool operator!=(const Movie* rhs) const; // not equal comparison operator
	bool operator>(const Movie* rhs) const; // greater than operator
	bool operator<(const Movie* rh) const;  // less than operator 

	int month;                                          // hold month                                
	string majorActor;                                  // hold majorActor
};
#endif
