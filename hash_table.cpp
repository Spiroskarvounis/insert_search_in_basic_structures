#include <iostream>
#include <cstring>
#include <string.h>
#include "hash_table.h"

using namespace std;

hashTable::hashTable(int n)
{
    size=n;
    elements=0;

    A = new myPair *[size];
    for(int i=0;i<size;i++)
        A[i]=nullptr;
}

hashTable::~hashTable()
{
    delete[] A;
    A=nullptr;
    elements=0;
    size=0;
}

unsigned int hashTable::hash(const string &d)
{
    return d%size;
}

unsigned int hashTable::hash2(unsigned int d)
{
    return (d+1)%size;
}

bool hashTable::insert (const string &key)
{
    if (search(key)!=nullptr)
    {
      search(key)->data++;
      return false;
    }
    if (elements>=size/2)
    {
        myPair **temp;
        size*=2;
        temp = new myPair*[size];
        for(int i=0;i<size;i++)
            temp[i]=nullptr;

        for (int i=0;i<size/2;i++)
        {
            if (A[i]!=nullptr)
            {
                unsigned int p = hash(A[i]->key);
                while (temp[p]!=nullptr)
                    p = hash2(p);
                temp[p]=A[i];
                A[i]=nullptr;
            }
        }
        delete[]A;
        A=temp;
    }
    unsigned int p = hash(key);
    while (A[p]!=nullptr)
        p = hash2(p);
    A[p]=new  myPair (key);
    elements++;
    return true;
}

myPair *& hashTable::search(const string &key)
{
    unsigned int p = hash(key);
    while (A[p]!=nullptr && A[p]->key.compare(key)!=0)
        p = hash2(p);

    return A[p];
}

bool hashTable::search(const string &key, int &data)
{
    myPair *p = search(key);

    if (p==nullptr)
        return false;

    data = p->data;

    return true;
}

unsigned long long int operator% (string s, int k)
{
    int sum =0;
    for (int i=0;i<s.length();i++)
        sum+=s[i]*(3^i);

    return sum % k;
}
