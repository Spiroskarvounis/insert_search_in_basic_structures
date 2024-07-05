#ifndef funcs_h
#define funcs_h

#include <cstring>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <ctime>
using namespace std;


void RemoveCaps(string& str) 			// converts capital letters to lowercase
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
	}
}

void RemovePunctuation(string&str) 		// converts punctuation into spaces and then deletes them
{
	for (int i = 0; i < str.length(); i++)
  	{
		if ((int)str[i]==130)
		 	str[i]=(char)'e';
		if (!(str[i] >= 'a'&& str[i]<='z') && !(str[i]>='0' && str[i]<='9'))
    			str[i] = ' ';
	}
  str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());       //removes spaces
}


void randomNum(int& rand_num,int min,int max, int i)   // returns a random number through rand_num between min and max
{
	srand(i);
	bool state = false;
	while (!state) {
		rand_num = rand() % max;
		if (rand_num >= min)
			state = true;
	}
}

#endif