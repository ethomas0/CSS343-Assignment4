#pragma once
#include "movie.h"
class Classics : public Movie
{
public:

	Classics(int stock, string director, string title, string majorActor, int month, int year);  // constructor
	~Classics();                                // destructor

	bool operator==(const Movie* rhs) const = 0;   // equal comparison operator
	bool operator!=(const Movie* rhs) const = 0; // not equal comparison operator
	bool operator>(const Movie* rhs) const = 0; // greater than operator
	bool operator<(const Movie* rh) const = 0;  // less than operator 

	void printMovieInfo() const;              // return string of full movie  info 

	static const char CODE = 'C';                   // static identifier for the class
protected:
	int month;
	string majorActor;
};


