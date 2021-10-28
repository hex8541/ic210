//Nicholas Heil 242628
//Read a file given by user, print out sizes of the ten largest connections

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void selection_sort(int* A, int n);
bool before(int a, int b);

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
  int* connections = new int[size];
  for(int i = 0; i < size; i++){
    string junk;  //Used to skip first pieces of information on each line
    fin >> junk >> junk >> junk >> junk >> junk >> connections[i];
  }
  
  //Sort in descending order
  selection_sort(connections, size);

  //Output largest ten in descending order
  for(int i=0; i < 10; i++)
    cout << connections[i] << endl;

  delete [] connections;
  return 0;
}

void selection_sort(int* A, int n) {
  for (int i = 0; i < n - 1; ++i) {
    // find nexti, the index of the next element
    int nexti = i;
    for (int j = i + 1; j < n; ++j) {
      if (before(A[j], A[nexti])) {
        nexti = j;
      }
    }
    // swap A[i] and A[nexti]
    int temp = A[i];
    A[i] = A[nexti];
    A[nexti] = temp;
  }
}

bool before(int a, int b)  
{
  return a > b; //results in descending order
}
