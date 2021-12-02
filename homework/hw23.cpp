//Nicholas Heil 242628
//Perform operations on a matrix of integers

#include <iostream>

using namespace std;

int main()
{
  //Initialize size of array 
  cout << "What size? ";
  int n, m; //n is number of rows, m is number of columns
  char j;
  cin >> n >> j >> m;
  
  //Reads in values for each storage location in the matrix
  int** A = new int*[n];
  for (int i=0; i < n; i++){  //Works on array of arrays
    A[i] = new int[m];  
    for(int j=0; j < m; j++)  //Inputs values to each location in each array
     cin >> A[i][j]; 
  }
  
  //Find rows whose sum is divisible by 3, or the row is a multiple of 3
  cout << "rows: ";
  int sum=0;
  for (int i=0; i < n; i++){  //Cycles rows to test each
    for (int j=0; j < m; j++){  //Takes sum of the row
      sum = sum + A[i][j];
    }
    if (sum%3 == 0)  //Checks if sum is divisible evenly by 3
      cout << i << " ";
    sum = 0;  //Reset sum for repeated use
  }

  //Find columns whose sum is divisible by 3
  sum = 0;
  cout << "\ncols: ";
  for (int i=0; i < m; i++){  //similar to above, but order reversed/cols first
    for (int j=0; j < n; j++){  //take sum of current column
      sum = sum + A[j][i];
    }
    if (sum%3 == 0)
      cout << i << " ";
    sum = 0;
  }

  for(int i = 0; i < n; i++)
    delete [] A[i];
  delete [] A;  //Delete the array used 

  return 0;
}
