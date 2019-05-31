#pragma once
#include "movie.h"
class Drama : public Movie
{
public:
	Drama();
	Drama(int stock, string director, string title, int year);  // constructor
	~Drama();                                // destructor

	bool operator==(const Movie* rhs) const = 0;   // == operator
	bool operator!=(const Movie* rhs) const = 0; // != operator
	bool operator>(const Movie* rhs) const = 0; // greater than operator
	bool operator<(const Movie* rhs) const = 0;  // less than operator 

	void printMovieInfo() const;              // return string of movie  info  

	static const char CODE = 'D';                   // static identifier for the class   
};


