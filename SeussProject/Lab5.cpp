//============================================================================
// Name    	: Lab5.cpp
// Author  	: Kyle Oak
// Version 	:
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "hashMap.hpp"
#include "hashNode.hpp"
#include "makeSeuss.hpp"
#include <time.h>
using namespace std;
int main() {
	srand(time(NULL));
	cout << "The last two arguments determine which hashing function to use, and which collision function to use." << endl;
	cout << "First hashing function and first collision method." << endl;
	makeSeuss *mk1 = new makeSeuss("DrSeuss.txt","truetrue.txt",true,true);
	cout << "First hashing function and second collision method." << endl;
	makeSeuss *mk2 = new makeSeuss("DrSeuss.txt","truefalse.txt", true, false);
	cout << "Second hashing function and first collision method." << endl;
	makeSeuss *mk3 = new makeSeuss("DrSeuss.txt","falsetrue.txt", false, true);
	cout << "Second hashing function and second collision method." << endl;
	makeSeuss *mk4 = new makeSeuss("DrSeuss.txt","falsefalse.txt", false, false);
	return 0;
}

