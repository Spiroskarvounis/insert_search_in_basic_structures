#ifndef unsorted_h
#define unsorted_h

#include<cstring>
#include <ostream>

using namespace std;

class unsorted_array
{
 private:
    string *wordsUn;	  // array that stores all the words from the file
    int* countUn;     	  // array that stores the times each word appears
    int sizeUn;		  // the size of the two arrays

  public:
    unsorted_array();			// constructor
    ~unsorted_array();			// destructor
    void increaseCounter(int);		// increases the counter of a specific word by 1
    void setSizeUn(int);		// setter for the sizeUn
    int getSizeUn();			// getter for the sizeUn
    void push_back_string(string); 	// inserts the string in the last position of the array (wordsUn)
    int searchUnsorted(string);    	// returns the position of the element, if this element does not exist it returns -1
    bool deleteUnsorted(string);        // deletes a specific string from the wordsUn array
    void printElementUn(int,int&);	// prints a specific element of the wordsUn array
    void printUn();			// prints every word in the array and the times it appears
    string getElement(int);  		// returns a specific element (word) from the wordsUn array                                  
};

#endif