#ifndef hashTable_h
#define hashTable_h

using namespace std;

class myPair			// represents the pair of a word and the number of its appearances
{
    public:
        myPair(string k)	// constructor
        {
            data=1;
            key=k;
        }
        int data;		// counter of the word's appearances
        string key;		// word
};

class hashTable
{
    private:
        int size;				// size of the array
        int elements;				// number of elements in the array
        myPair **A;				// array of myPair
        unsigned int hash(const string &);	// hash function
        unsigned int hash2(unsigned int );	// second hash function
        myPair *& search(const string &);	// searches a word and returns the pointer of its myPair
    public:
        hashTable(int);				// constructor
        ~hashTable();				// destructor
        bool insert(const string &);		// inserts a word in the array (successfull insertion=true, failed insertion=false)
        bool search(const string &, int &data);	// searches a word and returns through the int& the number of its appearances(found=true, not found=false)
};

unsigned long long int operator% (string, int);	// operator % for strings

#endif