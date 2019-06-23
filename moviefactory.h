//---------------------------------- moviefactory.h--------------------------
// --Krystal Levin & Ethan Thomas
//---------------------------------------------------------------------------

#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H


#include "movie.h"
#include "drama.h"
#include "comedy.h"
#include "classics.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

//--------------------------  class MovieFactory ----------------------------
// Purpose: 
//   -- MovieFactory class uses factory method pattern to create
//      new moive form input string.
//
// Implementation and assumptions:
//   -- Implement as factory method
//   -- Implement with following futures:
//      static poitner to the Movie createMovie
//---------------------------------------------------------------------------
class MovieFactory
{
public:

	static Movie* createMovie(const string&); // create pointer to the object Movie
};
#endif // !MOVIEFACTORY_H
