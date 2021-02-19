/*
* File:   bagtestmain.cpp
* Author: Prof Sipantzi -- CSIS 215 -- Programming Assignment 1 -- Bag Dictionary
*
* Created on July 14, 2012, 11:45 AM
* Updated pointers to smart pointers in ABag and BDictionary on 12/14/2018
*/

#include <string>
#include <sstream>
#include <iostream>

#include "ABag.h"
#include "BDictionary.h"


using namespace std;

const size_t DICTIONARY_SIZE = 10;

void wait(); //Used to pause screen output

/*
* Tests BDictionary with int and string objects only.
*/


int main(int argc, char** argv) {

	std::cout << "<Jack Tidball> -- CSIS 215 Programming Assignment 1 -- Bag Dictionary" << endl << endl;

	
	BDictionary<int, string> myIntStrDict(DICTIONARY_SIZE);
	BDictionary<string, int> myStrIntDict(DICTIONARY_SIZE);

	// myIntStrDict tests
	// INSERT: myIntStrDict
	cout << "Testing dictionary with <int, string> KV Pair\n";
	for (int i = 1; i <= DICTIONARY_SIZE; i++) {
		stringstream sn;
		sn << "Beth " << i * 10;
		myIntStrDict.insert(i * 10, sn.str());
	}
	cout << "INSERT: Size of myIntStrDict is " << myIntStrDict.size() << endl;

	// REMOVEANY: myIntStrDict
	string strData;
	if (myIntStrDict.removeAny(strData) == true) {
		cout << "REMOVEANY: My string data is " << strData << endl;
	}
	else {
		cout << "RemoveAny() failed -- dictionary is empty.\n";
	}
	cout << "Size of myIntStrDict is " << myIntStrDict.size() << "\n";

	// FIND: test for myIntStrDict.find
	int intKey = 40;
	if (myIntStrDict.find(intKey, strData) == true) {
		cout << "FIND: My data at key==" << intKey << " is: " << strData << "\n";
		cout << "Size of myIntStrDict is " << myIntStrDict.size() << "\n";
	}
	else {
		cout << "Could not find a record at " << intKey << "\n";
	}

	// REMOVE: myIntStrDict
	intKey = 60;
	if (myIntStrDict.remove(intKey, strData) == true) {
		cout << "REMOVE: Removed key " << intKey << " which was " << strData << "\n";
	}
	else {
		cout << "Could not find key " << intKey << "\n";
	}
	cout << "Size of my dictionary is " << myIntStrDict.size() << "\n";

	// CLEAR: myIntStrDict
	myIntStrDict.clear();
	cout << "CLEAR: Size of myIntStrDict is " << myIntStrDict.size() << "\n\n";

	/* end myIntStrDict tests ---------------------------------------------*/

	// myStrIntDict tests
	// INSERT: myStrIntDict

	
	cout << "Testing dictionary with <string, int> KV Pair\n";
	myStrIntDict.insert("Terri", 57);
	myStrIntDict.insert("Beth", 53);
	myStrIntDict.insert("Jeremy", 19);
	myStrIntDict.insert("Nathan", 17);
	myStrIntDict.insert("Zipper", 2);
	myStrIntDict.insert("Button", 1);
	myStrIntDict.insert("Kiwi", 7);
	myStrIntDict.insert("Masoala", 10);

	cout << "INSERT: Size of myStrIntDict is " << myStrIntDict.size() << endl;

	// REMOVEANY: myStrIntDict
	int intData;
	if (myStrIntDict.removeAny(intData) == true) {
		cout << "REMOVEANY: My int data is " << intData << endl;
	}
	else {
		cout << "RemoveAny() failed -- dictionary is empty.\n";
	}
	cout << "Size of myIntStrDict is " << myStrIntDict.size() << "\n";

	// FIND: myStrIntDict.find
	string strKey = "Kiwi";
	if (myStrIntDict.find(strKey, intData) == true) {
		cout << "FIND: " << strKey << "\'s age is " << intData << endl;
		cout << "Size of myStrIntDict is " << myStrIntDict.size() << "\n";
	}
	else {
		cout << "Could not find a record at " << strKey << "\n";
	}

	// REMOVE: myStrIntDict
	strKey = "Button";
	if (myStrIntDict.remove(strKey, intData) == true) {
		cout << "REMOVE: Removed key " << strKey << " which was " << intData << "\n";
	}
	else {
		cout << "Could not find key " << strKey << "\n";
	}
	cout << "Size of my dictionary is " << myStrIntDict.size() << "\n";

	// CLEAR: myStrIntDict
	myStrIntDict.clear();
	cout << "CLEAR: Size of myStrIntDict is " << myStrIntDict.size() << "\n\n";

	// end myStrIntDict tests ---------------------------------------------

	// Demonstrate any Bag functions that were not used/demonstrated in the implemention
	//of your BDictionary and ABag using a Bag of KVpairs<int, string>. 

	ABag<KVpair<int, string>> myBag; 
		ABag<KVpair<int, std::string>> bag = ABag<KVpair <int, std::string>>(10);
	//Used to test bag functions not previously demonstrated
		// TESTS 
		cout << "Begin Tests: \n\n\n";

		cout << "print bag capacity: " << bag.bagCapacity() << endl;
		cout << "print bag size: " << bag.size() << endl;
		KVpair<int, std::string> keyPair = KVpair<int, std::string >(23, "Lebron");
		KVpair<int, std::string> keyPairtwo = KVpair<int, std::string >(24, "Kobe");
		KVpair<int, std::string> keyPairthree = KVpair<int, std::string >(3, "Anthony");
		KVpair<int, std::string> keyPairfour = KVpair<int, std::string >(23, "Michael");
		KVpair<int, std::string> keyPairfive = KVpair<int, std::string >(30, "Stephen");
		KVpair<int, std::string> keyPairsix = KVpair<int, std::string >(11, "Kyrie");
		cout << "print += if added (23, Lebron) print true:  ";
		if ((bag += keyPair) == true) {
			cout << "true\n";
		}
		else {
			cout << "false\n";
		}
		bag.addItem(keyPairtwo);
		bag.addItem(keyPairthree);
		bag.addItem(keyPairfour);
		bag.addItem(keyPairfive);
		bag.addItem(keyPairsix);
		cout << "Inspect top: " << bag.inspectTop(keyPairsix) << endl;
		cout << "print bag size: " << bag.size() << endl;
		cout << "Remove key pair: "<< bag.remove(keyPairfour) << endl;
		cout <<"Bag Size is now: " <<  bag.size() << endl;
		cout << "find: " << bag.find(keyPairthree) << endl;
	wait();
	
	return 0;
}
 
//Used to pause the screen wherever desired
void wait()
{
	//The following if-statement checks to see how many characters are in cin's buffer
	//If the buffer has characters in it, the clear and ignore methods get rid of them.
	if (cin.rdbuf()->in_avail() > 0) //If the buffer is empty skip clear and ignore
	{
		cin.clear();
		cin.ignore(256, '\n'); //Clear the input buffer 
	}
	char ch;
	std::cout << "Press the Enter key to continue ... ";
	std::cin.get(ch);
}

