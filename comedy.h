#ifndef COMEDY_H
#define COMEDY_H
#include <string>
#include "movie.h"
using namespace std;
//-----------------------------class Comedy --------------------------------
// ADT Comedy: child class of Movie. Comedy Movie sorts by
// title and year
//
// Implementation and assumptions:
//   -- Implement as a child class of Movie
//   -- Implement with following futures:
//      createMovieInfo(), ==, !=, >, <
//---------------------------------------------------------------------------
class Comedy : public Movie
{
public:

	Comedy(const string&);                            // constructor
	Comedy(const string&, const int&);                // copy constructor
	virtual ~Comedy();                                // destructor

	static const char GENRE = 'F';                   // static indentifier for a class 

	virtual string createMoveInfo() const;               // virtual createMovieInfo
	virtual string createCustomerHistory() const;    // virtual createCustomerHistory
	
	
protected:

	virtual bool operator==(const Movie* rhs) const;  
	virtual bool operator!=(const Movie* rhs) const;
	virtual bool operator>(const Movie* rhs) const;    
	virtual bool operator<(const Movie* rhs) const;

};
#endif
