//Nicholas Heil 242628
//Program that takes two vectors and outputs their dot products

#include <iostream>

using namespace std;

int main()
{
  int n;  //integer size of vectors
  char j, v1, v2;  //Junk sorter and vectors 1 and 2
  cin >> j >> j >> n >> v1 >> j >> j;
  //Pointers to arrays
  double* x = new double[n];
  double* y = new double[n];

  //Stores vectors in each array
  for (int i = 1; i <= n; i++)  //Stores first vector
    cin >> x[i] >> j;
  cin >> v2 >> j >> j;
  for (int i =1; i <= n; i++)  //Second vector
    cin >> y[i] >> j;

  //Calculate and output dot products
  double d1 = 0, d2 = 0;  //Initialize
  for (int i =1; i <=n; i++)
    d1 = d1 + (x[i] * y[i]);
  for (int i = 1; i <= n; i++)
    d2 = d2 + (y[i] * x[i]);
  cout << "<" << v1 << "," << v2 << "> = ";
  for (int i =1; i <=n; i++){  //Outputs first dot product and how computed
    if (x[i] < 0)
      cout << "(" << x[i] << ") * ";
    else 
      cout << x[i] << " * ";
    if (y[i] < 0 && i < n)
      cout << "(" << y[i] << ") + ";
    else if (i < n) 
      cout << y[i] << " + ";
    else if (y[i] < 0)
      cout << "(" << y[i] << ") = ";
    else
      cout << y[i] << " = ";
  }
  cout << d1 << endl << "<" << v2 << "," << v1 << "> = ";
  for (int i =1; i <=n; i++){  //Outputs second dot product and how computed
    if (y[i] < 0)
      cout << "(" << y[i] << ") * ";
    else 
      cout << y[i] << " * ";
    if (x[i] < 0 && i < n)
      cout << "(" << x[i] << ") + ";
    else if (i < n) 
      cout << x[i] << " + ";
    else if (x[i] < 0)
      cout << "(" << x[i] << ") = ";
    else
      cout << x[i] << " = ";
  }
  cout << d2 << endl;
  return 0;
}
