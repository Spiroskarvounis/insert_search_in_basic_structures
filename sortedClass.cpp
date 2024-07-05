#include <string>
#include <fstream>
#include <cstring>
#include <iostream>
#include "sortedClass.h"
using namespace std;


sortedClass::sortedClass() {
	wordsSor = nullptr;
	countSor = nullptr;
	sizeSor = 0;
}

sortedClass::~sortedClass() {
	delete[]wordsSor;
  wordsSor=nullptr;
}

void sortedClass::setSizeSor(int sizeSor) {
	this->sizeSor = sizeSor;
}

int sortedClass::getSizeSor() {
	return sizeSor;
}

void sortedClass::sort_Array() {
	int i, j, min_obj;
	string minStr;
	for (i = 0; i < sizeSor - 1; i++) {
		min_obj = i;
		minStr=wordsSor[i];

		for (j = i + 1; j < sizeSor; j++) {
			if (minStr> wordsSor[j]) {
				minStr= wordsSor[j];
				min_obj = j;
			}
		}
		if (min_obj != i) {
			string tmp;
			tmp= wordsSor[i];
			wordsSor[i]= wordsSor[min_obj];
			wordsSor[min_obj]=tmp;

		}
	}
}

void sortedClass::push_back_strings(string k)
{
	string* tempS;
	int* temp2S;

	tempS = new string[sizeSor + 2];
	temp2S = new int[sizeSor + 2];
	for (int i = 0; i < sizeSor; i++) {
		tempS[i] = wordsSor[i];
		temp2S[i] = countSor[i];
	}
	delete[]wordsSor;
	delete[]countSor;
	wordsSor = tempS;
	countSor = temp2S;
	sizeSor++;
	insertSorted(k);
}

void sortedClass::insertSorted(string k) {

	int i;

	for (i = sizeSor - 2;i>=0 && k.compare(wordsSor[i]) < 0 ;i--) {
		wordsSor[i+1]=wordsSor[i];
		countSor[i + 1] = countSor[i];
	}
	wordsSor[i+1]=k;
	countSor[i+1] = 1;
}

void sortedClass::increaseSorted(int position) {
	countSor[position]++;
}

bool sortedClass::DeleteElement(string deleteword) {
	int found = binarySearch(0, sizeSor -1, deleteword);
	if (found == -1)
  {
		cout << "There is no element to delete in this array!" << endl;
    return false;
  }
  else {
		for (int i = found; i < sizeSor - 1; i++) {
			wordsSor[i]=wordsSor[i + 1];
		}
	}
  return true;
}

int sortedClass::binarySearch(int left, int size, string search) {
	int right = size - 1;
	while (left <= right) {
		int mid = left + (right - left);

		if (search.compare(wordsSor[mid]) == 0)
		return mid;;

		if (search.compare(wordsSor[mid]) > 0)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;


}



string sortedClass::getWords(int num) {
	return wordsSor[num];
}

void  sortedClass::printSor() {
	for (int i = 0; i < sizeSor; i++) {
		cout << wordsSor[i] << " is appeared " << countSor[i] << " times!" << endl;
	}
}

void sortedClass::printElementSor(int position, int& times)
{
  times=countSor[position];
	cout<<"\""<<wordsSor[position]<<"\" is appeared "<<countSor[position]<<" times!"<<endl;
}
