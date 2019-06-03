//class Movie
//base class for Comedy, Drama, and Classics
#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
//--------------------------  class Movie -----------------------------------
// ADT Comedy: abstract class Movie. Abstact class for child classes Drama,
// Comdedy, Classiscs. Can not be created. Used only for inheretance purpose.
// General movie contains information about title, director, year, and stock.
//
// Implementation and assumptions:
//   -- Implement as a abstract class
//  -- Implement with following futures:
//      printMovieInfo(), ==, !=, >, <
//---------------------------------------------------------------------------
class Movie 
{
public:
	virtual ~Movie() {};                // destructor
	
	virtual string createMovieInfo() const = 0;               //  pure virtual printInfo
	virtual string createCustomerHistory() const = 0;    // pure virtual printInfoForCustomer

	virtual bool increaseStock(int);    // increase stock
	virtual bool decreaseStock();       // decrease stock
	virtual int getStock();             // return current stock



	
	virtual bool operator==(const Movie* rhs) const =0; // pure virtual isEqual operator
	virtual bool operator!=(const Movie* rhs) const =0;
	virtual bool operator>(const Movie* rhs) const =0;    // operator=>
	virtual bool operator<(const Movie* rhs) const =0;   
	
	

protected:

	Movie();                            // constructor (protected) to avoid declaration of the object
	void parseNLoadString(const string& movieInfo);     // helper method for copy constractor


	//movie data
	char type;                          // hold type
	int stock;                          // hold stock
	string director;                    // hold director
	string title;                       // hold title
	int year;                           // hold year

};
#endif
