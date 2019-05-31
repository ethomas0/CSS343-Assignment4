#pragma once
#include <iostream> 

using namespace std;

class Movie
{
public:

	virtual ~Movie() {};                // destructor

	virtual bool operator==(const Movie* rhs) const = 0;   // == operator
	virtual bool operator!=(const Movie* rhs) const = 0; // != operator
	virtual bool operator>(const Movie* rhs) const = 0; // greater than operator
	virtual bool operator<(const Movie* rhs) const = 0;  // less than operator

	virtual void printMovieInfo() const = 0;      //  prints movies information

	virtual bool increaseStock(const int& amount) = 0;    // increase stock
	virtual bool dicreaseStock(const int& amount) = 0;    // decrease stock
	virtual int getStock();                      // return current stock

protected:

	explicit Movie();                            // constructor


	char type;                          // holds a movie type
	int stock;                          // holds movie stock
	string director;                    // holds a movie director
	string title;                       // holds a movie title
	int year;                           // holds a movie year 
};


