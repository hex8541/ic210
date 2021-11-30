//Nicholas Heil 242628
//Process commands involving integers in arrays
#include <iostream>
using namespace std;

// ======================================
// Function prototypes below
// ======================================
int readN();  //Reads in array size
int* readData(int n); //Reads in user input for array of size n
void show(int* N, int n);  //Show stars=int value for each position
void swap(int* N, int n);  //Show stars after swapping two values

// ======================================
// main function
// TOUCH NOTHING INSIDE THE FUNCTION!!
// ======================================
int main()
{
  int n = readN();
  int* A = readData(n);

  string cmd;
  cout << "cmd: ";
  while( (cin >> cmd) && cmd != "quit" ) 
  {
    if( cmd == "show" )
      show(A, n);
    else if ( cmd == "swap" )
      swap(A, n);

    cout << "cmd: ";
  }

  delete [] A;
  return 0;
}


// ======================================
// Function definitions below
// ======================================
int readN()  //Sorts through input to find array size and returns this value
{
  cout << "N = ";
  int out;
  cin >> out;
  return out;
}
int* readData(int n)
{
  cout << "Numbers: ";
  int* data = new int[n];  
  for (int i = 0; i < n; i++)
    cin >> data[i];
  return data;
}
void show(int* N, int n) //Displays stars for each int value in array
{
  for (int i = 0; i < n; i++){
    cout << "[" << i << "] ";  //current position
    for (int j = 1; j <= N[i]; j++)  //asterisks
      cout << "*";
    cout << endl;  //ends line 
  }
}
void swap(int* N, int n)
{
  int a, b, t; //Used for swap, t is temp variable
  cin >> a >> b;
  t = N[a];
  N[a] = N[b];
  N[b] = t;
  show(N, n);  //reuse show function
}
