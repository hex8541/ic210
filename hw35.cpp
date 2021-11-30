//Nicholas Heil 242628
//Define a recursive function to return a number x to the power of int n

#include <iostream>

using namespace std;

double pow(double x, int n);

int main()
{
  double x;
  int n;
  cout << "Enter x and n: ";
  cin >> x >> n;
  cout << "x^n is " << pow(x,n) << endl;
  return 0;
}

double pow(double x, int n){
  double p=1; //initialize with 1 for multiplicative identity
  if(n == 0)
    return p; //if reached end of iterations, end
  else
    p = x * pow(x, n-1); //recursive step
  return p;
}
