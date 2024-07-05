#include <iostream>
#include <cstring>
#include <ostream>
#include "unsorted_array.h"
using namespace std;

unsorted_array::unsorted_array()
{
	wordsUn = nullptr;
	countUn = nullptr;
	sizeUn = 0;

}

unsorted_array::~unsorted_array()
{
  delete [] wordsUn;
  wordsUn=nullptr;
}
void unsorted_array::setSizeUn(int sizeWords) {
	this->sizeUn = sizeWords;
}
int unsorted_array::getSizeUn() {
	return sizeUn;
}
void unsorted_array::push_back_string(string k)
{
	string* temp;
	int* temp2;

	temp = new string[sizeUn + 2];
	temp2 = new int[sizeUn + 2];
	for (int i = 0; i < sizeUn; i++) {
		temp[i] = wordsUn[i];
		temp2[i] = countUn[i];
	}
	delete[]wordsUn;
	delete[]countUn;
	wordsUn = temp;
	countUn = temp2;
	sizeUn++;
	wordsUn[sizeUn - 1] = k;
	countUn[sizeUn - 1] = 1;
}


bool unsorted_array::deleteUnsorted(string key) {
	int flag = searchUnsorted(key);

	if (flag == -1)
    return false;

	for (int i = flag; i < sizeUn; i++)
		wordsUn[i]= wordsUn[i + 1];

  return true;
}

int unsorted_array::searchUnsorted(string key) {
	 int i = 0;
	while ( i < sizeUn) {
		if (key==wordsUn[i])
			return i;		// returns  the position of the element in the array
		else
			i++;
	}
	return -1;
}

void unsorted_array::increaseCounter(int position) {
	countUn[position]++;
}

void  unsorted_array::printUn() {
	for (int i = 0; i < sizeUn; i++) {
		cout << wordsUn[i] << " is appeared " << countUn[i] << " times!"<<endl;
	}
}

void unsorted_array::printElementUn(int position,int& times)
{
  times=countUn[position];
	cout<<"\""<<wordsUn[position]<<"\" is appeared "<<countUn[position]<<" times!"<<endl;
}

string unsorted_array::getElement(int a) {
    return wordsUn[a];
}
