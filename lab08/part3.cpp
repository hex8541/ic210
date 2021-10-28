//Nicholas Heil 242628
//Read a file given by user, then count number of distinct protocols

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

bool before(string a, string b);  //modified for string
void selection_sort(string* A, int n);  //modified for string

int main()
{
  //Gather input
  string filename;
  cout << "What file? ";
  cin >> filename;
  ifstream fin(filename);
  
  //Create array and read in
  int size;
  fin >> size; //Read in number of connections logged
  string* protocol = new string[size];
  for(int i = 0; i < size; i++){
    string junk;  //Used to skip first pieces of information on each line
    fin >> junk >> junk >> junk >> junk >> protocol[i] >> junk;
  }
  
  //Sort by protocols
  selection_sort(protocol, size);

  //Count distinct protocols
  int p=1;  
  string current = protocol[0];  //initialize
  for(int i=1; i < size; i++){
    if(protocol[i] != current){  //when a new protocol is reached
      p++; //increase count of distinct protocols
      current = protocol[i];
    }
    //Nothing happens if the protocols are the same
  }
  cout << p;

  delete [] protocol;  //delete array
  return 0;
}

void selection_sort(string* A, int n) //modified for string
{
  for (int i = 0; i < n - 1; ++i) {
    // find nexti, the index of the next element
    int nexti = i;
    for (int j = i + 1; j < n; ++j) {
      if (before(A[j], A[nexti])) {
        nexti = j;
      }
    }
    // swap A[i] and A[nexti]
    string temp = A[i];
    A[i] = A[nexti];
    A[nexti] = temp;
  }
}

bool before(string a, string b) //modified for string
{
  return a < b;
}
