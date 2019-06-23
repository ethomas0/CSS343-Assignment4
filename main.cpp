#include "storemanager.h"
#include <iostream>
using namespace std;

//// Used for memory leak detection
//#if defined(_WIN32) || defined(_WIN64)
//#include "vld.h"
//#endif

int main()
{
	ifstream infile1("data4movies.txt");
	if (!infile1) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	ifstream infile2("data4commands.txt");
	if (!infile2) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	ifstream infile3("data4customers.txt");
	if (!infile3) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	StoreManager store;                   // allocate store
	store.buildStore(infile1, infile3);   // proccess movies and customers
	store.readCommands(infile2);        // proccess commanads

	infile1.close();
	infile2.close();
	infile3.close();

	//system("pause");
	return 0;
}
