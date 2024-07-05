#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <ctime>
#include "binary_tree.h"
#include "avl_tree.h"
#include "hash_table.h"
#include "MainFunctions.h"
#include "sortedClass.h"
#include "unsorted_array.h"

using namespace std;

int main()
{
  int ret,Qsize,i,temp;
  string key, filename,output_name, *Q;
  ifstream file;
  ofstream output_file;
  clock_t start,stop;
  filename="gutenberg.txt";                     // determines the name of the input file
  output_name="output_file.txt";                // determines the name of the output file
  randomNum(Qsize, 800, 1200,0);                // returns a random number in the Qsize variable
  cout<<"Qsize: "<<Qsize<<endl;

  output_file.open(output_name, ios::out);      // opens the output file
  if(!output_file.is_open())                    //checks it the file is open.If it's not it shuts down the program.
  {
    cout << "File could not open." << endl;
		return -1;
  }

////////////////////////////////////////////////////////////////////////////////////////
  output_file<<"------------------Unsorted Array------------------"<<endl<<endl;
  cout<<"------------------Unsorted Array------------------"<<endl;
	unsorted_array a;

	file.open(filename, ios::in);

  if (!file.is_open())                            //checks it the file is open.If it's not it shuts down the program.
  {
		cout << "File could not open." << endl;
		return -1;
	}
  cout<<"Inserting has begun..."<<endl;
  start=clock();
	while (file>>key)                   //while there are objects to read from file
  {
		RemoveCaps(key);		                //this function removes caps
		RemovePunctuation(key);		        	// this function removes punctuation
		int positionUn = a.searchUnsorted(key);
		if (positionUn == -1) {
			a.push_back_string(key);	//inserts the element at the last place of the array
		}
		else {
			a.increaseCounter(positionUn);
		}

	}
	file.close();
  stop=clock();

  output_file<<"Inserting all the words took "<<(float)(stop-start)/CLOCKS_PER_SEC<<" seconds"<<endl<<endl;
  cout<<"Inserting all the words took "<<(float)(stop-start)/CLOCKS_PER_SEC<<" seconds"<<endl;

  Q=new string [Qsize];
  for (int k=0;k<Qsize;k++)                     // in this loop, the Q array is formed with random words from the unsorted array
  {
    randomNum(temp, 0, a.getSizeUn(),k);        // returns a random number in the temp variable
    Q[k]=a.getElement(temp);
  }

  cout<<"searching"<<endl;
	start=clock();
  for (i=0;i<Qsize;i++)                         // searching all the words of Q array in this structure
  {
    key=Q[i];
    int eleUn;
    eleUn = a.searchUnsorted(key);
    if (eleUn != -1) {
      a.printElementUn(eleUn,ret);
      output_file<<"\""<<key<<"\" found "<<ret<<" times"<<endl;
    }
    else {
      cout << "Element does not exist!" << endl;
    }
  }
  stop=clock();
  output_file<<endl<<"Searching all the words in Q took "<<(float)(stop-start)/CLOCKS_PER_SEC<<" seconds"<<endl<<endl;
  cout<<"Searching all the words in Q took "<<(float)(stop-start)/CLOCKS_PER_SEC<<" seconds"<<endl;

  cout<<"deleting"<<endl;
	cin >> key;
  while(key!="0")                               // in this loop you can delete words from the structure until you press '0' to continue
  {
    int eleUn;
    eleUn = a.searchUnsorted(key);
    if (eleUn != -1) {
      if (a.deleteUnsorted(key))
        cout<<"Deleted"<<endl;
      else
        cout<<"Not deleted"<<endl;
    }
    else {
      cout << "Element does not exist!" << endl;
    }
    cin >> key;
  }

  a.~unsorted_array();

////////////////////////////////////////////////////////////////////////////////////////
  output_file<<"-------------------Sorted Array-------------------"<<endl<<endl;
  cout<<"------------------Sorted Array------------------"<<endl;
	sortedClass b;

	file.open(filename, ios::in);

  if (!file.is_open())                              //checks it the file is open.If it's not it shuts down the program.
  {
		cout << "File could not open." << endl;
		return -1;
	}
  start=clock();
  cout<<"Inserting has begun..."<<endl;
	while (file >> key )                                // while there are objects to read from file
  {
			RemoveCaps(key);						    // this function removes caps
			RemovePunctuation(key);			            // removes punctuation
			int positionSor = b.binarySearch(0, b.getSizeSor(),key);
			if (positionSor == -1) {
				b.push_back_strings(key);	            // inserts the element at the last place of the array
			}
			else {
				b.increaseSorted(positionSor);
			}
	}
	file.close();
  stop=clock();
  output_file<<"Inserting all the words took "<<(float)(stop-start)/CLOCKS_PER_SEC<<" seconds"<<endl<<endl;
  cout<<"Inserting all the words took "<<(float)(stop-start)/CLOCKS_PER_SEC<<" seconds"<<endl;

  cout<<"searching"<<endl;
  start=clock();
  for (i=0;i<Qsize;i++)                                 // searching all the words of Q array in this structure
  {
    key=Q[i];
    int eleSor;
    eleSor = b.binarySearch(0, b.getSizeSor(), key);
    if (eleSor != -1) {
      b.printElementSor(eleSor,ret);
      output_file<<"\""<<key<<"\" found "<<ret<<" times"<<endl;
    }
    else {
      cout << "Element does not exist!" << endl;
    }
  }
  stop=clock();
  output_file<<endl<<"Searching all the words in Q took "<<(float)(stop-start)/CLOCKS_PER_SEC<<" seconds"<<endl<<endl;
  cout<<"Searching all the words in Q took "<<(float)(stop-start)/CLOCKS_PER_SEC<<" seconds"<<endl;

  cout<<"deleting"<<endl;
	cin >> key;
  while(key!="0")                                           // in this loop you can delete words from the structure until you press '0' to continue
  {
    int eleSor;
    eleSor = b.binarySearch(0, b.getSizeSor(), key);
    if (eleSor != -1) {
      if (b.DeleteElement(key))
        cout<<"Deleted"<<endl;
      else
        cout<<"Not deleted"<<endl;
    }
    else {
      cout << "Element does not exist!" << endl;
    }
    cin >> key;
  }
  b.~sortedClass();


/////////////////////////////////////////////////////////////////////////////////////
  output_file<<"-------------------Binary Tree--------------------"<<endl<<endl;
  cout<<"------------------Binary Tree------------------"<<endl;
  file.open(filename, ios::in);
  if (!file.is_open())                      //checks it the file is open.If it's not it shuts down the program.
  {
    cerr<<"Could not open the file"<<endl;
    return -1;
  }

    btree B;
    cout<<"Inserting has begun..."<<endl;
    start=clock();
    while(file>>key)                        //while there are objects to read from file
    {
      RemoveCaps(key);                      //this function removes caps
      RemovePunctuation(key);               // this function removes punctuation
      B.insert(key);
    }
    file.close();
    stop=clock();
    output_file<<"Inserting all the words took "<<(float)(stop-start)/CLOCKS_PER_SEC<<" seconds"<<endl<<endl;
    cout<<"Inserting all the words took "<<(float)(stop-start)/CLOCKS_PER_SEC<<" seconds"<<endl;

  cout<<"Searching begins:"<<endl;
  start=clock();
  for (i=0;i<Qsize;i++)                         // searching all the words of Q array in this structure
  {
    key=Q[i];
      if (B.search(key,ret))
      {
        output_file<<"\""<<key<<"\" found "<<ret<<" times"<<endl;
        cout<<"\""<<key<<"\" found "<<ret<<" times"<<endl;
      }
      else
        cout<<"\""<<key<<"\" not found"<<endl;
    }
    stop=clock();
    output_file<<endl<<"Searching all the words in Q took "<<(float)(stop-start)/CLOCKS_PER_SEC<<" seconds"<<endl<<endl;
    cout<<"Searching all the words in Q took "<<(float)(stop-start)/CLOCKS_PER_SEC<<" seconds"<<endl;

    short control;
    cout<<"Do you want to see the preorder traversal? (0=No, 1=Yes)"<<endl;
    cin>>control;
    if (control)
      B.PreOrder ();                    // prints the preorder traversal of the tree

    cout<<"Do you want to see the inorder traversal? (0=No, 1=Yes)"<<endl;
    cin>>control;
    if (control)
      B.InOrder ();                     // prints the inorder traversal of the tree

    cout<<"Do you want to see the postorder traversal? (0=No, 1=Yes)"<<endl;
    cin>>control;
    if (control)
      B.PostOrder ();                   // prints the postorder traversal of the tree

    cout<<"Begin deleting:"<<endl;
    cout<<"Press \"0\" if you want to stop deleting"<<endl;
    cin>>key;
    while(key!="0")                                             // in this loop you can delete words from the structure until you press '0' to continue
    {
      if (B.remove(key))
        cout<<"Deleted"<<endl;
      else
        cout<<"Not deleted"<<endl;

      cout<<"Press \"0\" if you want to stop deleting"<<endl;
      cin>>key;
    }

    B.destroy_tree();

////////////////////////////////////////////////////////////////////////////////////
  output_file<<"---------------------AVL Tree---------------------"<<endl<<endl;
  cout<<"------------------AVL Tree------------------"<<endl;
  file.open(filename, ios::in);
  if (!file.is_open())                          //checks it the file is open.If it's not it shuts down the program.
  {
    cerr<<"Could not open the file"<<endl;
    return -1;
  }

    avl A;
    cout<<"Inserting has begun..."<<endl;
    start=clock();
    while(file>>key)                            //while there are objects to read from file
    {
      RemoveCaps(key);                          //this function removes caps
      RemovePunctuation(key);                   // this function removes punctuation
      A.insert(key);
    }
    file.close();
    stop=clock();
    output_file<<"Inserting all the words took "<<(float)(stop-start)/CLOCKS_PER_SEC<<" seconds"<<endl<<endl;
    cout<<"Inserting all the words took "<<(float)(stop-start)/CLOCKS_PER_SEC<<" seconds"<<endl;

    cout<<"Searching begins:"<<endl;
  start=clock();
  for (i=0;i<Qsize;i++)                         // searching all the words of Q array in this structure
  {
    key=Q[i];
      if (A.search(key,ret))
      {
        output_file<<"\""<<key<<"\" found "<<ret<<" times"<<endl;
        cout<<"\""<<key<<"\" found "<<ret<<" times"<<endl;
      }
      else
        cout<<"\""<<key<<"\" not found"<<endl;
    }
    stop=clock();
    output_file<<endl<<"Searching all the words in Q took "<<(float)(stop-start)/CLOCKS_PER_SEC<<" seconds"<<endl<<endl;
    cout<<"Searching all the words in Q took "<<(float)(stop-start)/CLOCKS_PER_SEC<<" seconds"<<endl;

    cout<<"Do you want to see the preorder traversal? (0=No, 1=Yes)"<<endl;
    cin>>control;
    if (control)
      A.PreOrder();                         // prints the preorder traversal of the tree

    cout<<"Do you want to see the inorder traversal? (0=No, 1=Yes)"<<endl;
    cin>>control;
    if (control)
      A.InOrder ();                         // prints the inorder traversal of the tree

    cout<<"Do you want to see the postorder traversal? (0=No, 1=Yes)"<<endl;
    cin>>control;
    if (control)
      A.PostOrder ();                       // prints the postorder traversal of the tree

    cout<<"Begin deleting:"<<endl;
    cout<<"Press \"0\" if you want to stop deleting"<<endl;
    cin>>key;
    while(key!="0")                                             // in this loop you can delete words from the structure until you press '0' to continue
    {
      if (A.remove(key))
        cout<<"Deleted"<<endl;
      else
        cout<<"Not deleted"<<endl;

      cout<<"Press \"0\" if you want to stop deleting"<<endl;
      cin>>key;
    }



/////////////////////////////////////////////////////////////////////////////
  output_file<<"--------------------Hash Table--------------------"<<endl<<endl;
  cout<<"------------------Hash Table------------------"<<endl;

  hashTable H(10);
  file.open(filename, ios::in);
  if (!file.is_open())                              //checks it the file is open.If it's not it shuts down the program.
  {
    cerr<<"Could not open the file"<<endl;
    return -1;
  }

    cout<<"Inserting has begun..."<<endl;
    start=clock();
    while(file>>key)                                //while there are objects to read from file
    {
      RemoveCaps(key);                              //this function removes caps
      RemovePunctuation(key);                       // this function removes punctuation
      H.insert(key);
    }
    file.close();
    stop=clock();
    output_file<<"Inserting all the words took "<<(float)(stop-start)/CLOCKS_PER_SEC<<" seconds"<<endl<<endl;
    cout<<"Inserting all the words took "<<(float)(stop-start)/CLOCKS_PER_SEC<<" seconds"<<endl;


    cout<<"Searching begins:"<<endl;
    start=clock();
    for (i=0;i<Qsize;i++)                               // searching all the words of Q array in this structure
    {
      key=Q[i];
      if (H.search(key,ret))
      {
        output_file<<"\""<<key<<"\" found "<<ret<<" times"<<endl;
        cout<<"\""<<key<<"\" in table, "<<ret<<" times"<<endl;
      }
      else
        cout<<"Not in table"<<endl;
    }
    stop=clock();
    output_file<<endl<<"Searching all the words in Q took "<<(float)(stop-start)/CLOCKS_PER_SEC<<" seconds"<<endl;
    cout<<"Searching all the words in Q took "<<(float)(stop-start)/CLOCKS_PER_SEC<<" seconds"<<endl;

  H.~hashTable();

  output_file.close();

  return 0;
}
