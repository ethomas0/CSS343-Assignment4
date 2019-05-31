#pragma once
#include "movie.h"
class Comedy : public Movie
{
public:
	Comedy();
	Comedy(int stock, string director, string title, int year);  // constructor
	~Comedy();                                // destructor

	bool operator==(const Movie* rhs) const =0;   // == operator
	bool operator!=(const Movie* rhs) const = 0; // != operator
	bool operator>(const Movie* rhs) const =0; // greater than operator
	bool operator<(const Movie* rhs) const =0;  // less than operator 

	void printMovieInfo() const;              // return string of movie info 
       
       static const char CODE = 'F';                   // static identifier for the class   
};  


