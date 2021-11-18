//Nicholas Heil 242628
//Sort ten ints and return them in ascending order, odds then evens

#include <iostream>

using namespace std;

void selection_sort(int* A, int n);
bool before(int a, int b);

int main()
{
  //Create array and gather input from user
  int* PosInt = new int[10];
  for (int i=0; i < 10; i++)
    cin >> PosInt[i];
  
  //Sort
  selection_sort(PosInt, 10);
  
  //Output
  for (int i=0; i < 10; i++)
    cout << PosInt[i] << " ";


  delete [] PosInt;
  return 0;
}

void selection_sort(int* A, int n) 
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
    int temp = A[i];
    A[i] = A[nexti];
    A[nexti] = temp;
  }
}

bool before(int a, int b) //Sort by ascending odd, then ascending even
{
  if (a%2 == 1 && b%2 ==1)  //If both are odd
    return a < b;  
  else if(a%2 == 1)  //If a is odd and b is even, move a up
    return true;
  else if(a%2 == 0 && b%2 == 1)  //If a is even and b is odd, move b up
    return false;
  else  //If both are even 
    return a < b;
}

