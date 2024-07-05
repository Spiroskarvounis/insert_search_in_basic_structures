#ifndef sorted_h
#define sorted_h

#include <iostream>
#include<cstring>
using namespace std;

class sortedClass 	
{
 private:
	string* wordsSor;  	// array that stores all the words from the file
	int* countSor;		// array that stores the times each word appears
	int sizeSor;		// the size of the two arrays
 public:
	sortedClass();				// constructor
	~sortedClass();				// destructor
	string getWords(int);			// returns a specific element (word) from the wordsSor array 
	void insertSorted(string);		// inserts the string in the array (wordsSor)
	void setSizeSor(int);			// setter for the sizeSor
	int  getSizeSor();			// getter for the sizeSor
	void sort_Array(); 			// sorts the string using selection sort
	void push_back_strings(string);		// increase the size of the arrays by 1 place
	void increaseSorted(int );		// increases the counter of a specific word by 1
	bool DeleteElement(string); 		// deletes a specific string from the wordsSor array
	int binarySearch(int,int, string); 	// returns the position of the element, if this element does not exist it returns -1
	void printElementSor(int,int&);		// prints a specific element of the wordsUn array
	void printSor();			// prints every word in the array and the times it appears
};

#endif