//Nicholas Heil 242628
//Defining shapes to be drawn in gnuplot


#include <iostream>
#include <string>

using namespace std;

int main()
{
  //Save inputs to be used
  double x1, x2, x3, y1, y2, y3, xmax, xmin, ymax, ymin;
  char j; //sorts out punctuation
  cin >> j >> x1 >> j >> y1 >> j >> j >> x2 >> j >> y2 >> j >> j >> x3 >> j >> y3;

  //Sort variables to determine maximum and minimum values 
  if (x1 >= x2)
    xmax = x1, xmin = x2;
  else 
    xmax = x2, xmin = x1;
  if (x3 >= xmax)
    xmax = x3;
  else if (xmin >= x3)
    xmin = x3;
  //Do the same for y variables
  if (y1 >= y2)
    ymax = y1, ymin = y2;
  else 
    ymax = y2, ymin = y1;
  if (y3 >= ymax)
    ymax = y3;
  else if (ymin >= y3)
    ymin = y3;

  //Define bounding box
  cout << xmin << " " << ymin << endl;
  cout << xmin << " " << ymax << endl;
  cout << xmax << " " << ymax << endl;
  cout << xmax << " " << ymin << endl;
  cout << xmin << " " << ymin << endl;

  //Define triangle
  cout << x1 << " " << y1 << endl;
  cout << x2 << " " << y2 << endl;
  cout << x3 << " " << y3 << endl;
  cout << x1 << " " << y1 << endl;
}

