
#include<iostream>
#include <fstream> 
#include "store.h" 


using namespace std;

int main()
{
	ifstream infile1("data4commands.txt");
	if (!infile1) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	ifstream infile2("data4customers.txt");
	if (!infile2) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	ifstream infile3("data4movies.txt");
	if (!infile3) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	Store firstStore;
	firstStore.buildStore(infile2, infile3);
	firstStore.processCommands(infile1); 

	return 0;
}
